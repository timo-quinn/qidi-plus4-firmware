// Ghidra headless post-script used by Export-QidiComponentReference.ps1.
// Exports the useful named functions from a Cython extension while omitting
// external imports and most generated CPython glue.

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;

public class ExportCythonDecompilation extends GhidraScript {
    private static boolean shouldExport(Function function) {
        if (function.isExternal() || function.isThunk()) {
            return false;
        }

        String name = function.getName();
        return name.startsWith("__pyx_pf_")
            || name.startsWith("__pyx_f_")
            || name.startsWith("__pyx_pw_")
            || name.startsWith("__pyx_pymod_exec_")
            || name.startsWith("PyInit_")
            || (!name.startsWith("_") && !name.startsWith("FUN_"));
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) {
            throw new IllegalArgumentException("Expected pseudocode and disassembly output path arguments");
        }

        File output = new File(args[0]);
        File disassemblyOutput = new File(args[1]);
        File parent = output.getParentFile();
        if (parent != null) {
            parent.mkdirs();
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(disassemblyOutput))) {
            writer.write("# Ghidra listing for " + currentProgram.getName() + "\n");
            writer.write("# Address | bytes | decoded ARM64 instruction\n");
            InstructionIterator instructions = currentProgram.getListing().getInstructions(true);
            while (instructions.hasNext()) {
                Instruction instruction = instructions.next();
                byte[] bytes = instruction.getBytes();
                StringBuilder hex = new StringBuilder();
                for (byte value : bytes) {
                    hex.append(String.format("%02x", value & 0xff));
                }
                writer.write(String.format("%s  %-16s  %s%n",
                    instruction.getAddress(), hex.toString(), instruction.toString()));
            }
        }

        List<Function> functions = new ArrayList<>();
        FunctionIterator iterator = currentProgram.getFunctionManager().getFunctions(true);
        while (iterator.hasNext()) {
            Function function = iterator.next();
            if (shouldExport(function)) {
                functions.add(function);
            }
        }
        functions.sort(Comparator.comparing(Function::getEntryPoint));

        DecompInterface decompiler = new DecompInterface();
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(true);
        decompiler.setSimplificationStyle("decompile");
        if (!decompiler.openProgram(currentProgram)) {
            throw new RuntimeException("Ghidra could not open the imported program");
        }

        int successful = 0;
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
            writer.write("/*\n");
            writer.write(" * Reverse-engineered Ghidra output. This is not original source code.\n");
            writer.write(" * Program: " + currentProgram.getName() + "\n");
            writer.write(" * Language: " + currentProgram.getLanguageID() + "\n");
            writer.write(" * Selected named functions: " + functions.size() + "\n");
            writer.write(" */\n\n");

            for (Function function : functions) {
                if (monitor.isCancelled()) {
                    break;
                }
                monitor.setMessage("Decompiling " + function.getName());
                DecompileResults result = decompiler.decompileFunction(function, 90, monitor);
                writer.write("\n/* ================================================================\n");
                writer.write(" * Address: " + function.getEntryPoint() + "\n");
                writer.write(" * Symbol:  " + function.getName() + "\n");
                writer.write(" * Signature: " + function.getSignature().getPrototypeString() + "\n");
                writer.write(" * ================================================================ */\n");
                if (result.decompileCompleted() && result.getDecompiledFunction() != null) {
                    writer.write(result.getDecompiledFunction().getC());
                    successful++;
                } else {
                    writer.write("/* DECOMPILATION FAILED: " + result.getErrorMessage() + " */\n");
                }
                writer.flush();
            }
            writer.write("\n/* Successfully decompiled " + successful + " of " + functions.size() + " selected functions. */\n");
        } finally {
            decompiler.dispose();
        }

        println("Exported " + successful + " functions to " + output.getAbsolutePath());
        println("Exported disassembly to " + disassemblyOutput.getAbsolutePath());
    }
}
