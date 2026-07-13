// Ghidra headless post-script for exporting an explicit set of named functions.

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class ExportNamedDecompilation extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            throw new IllegalArgumentException(
                "Expected output path followed by one or more exact function names");
        }

        File output = new File(args[0]);
        File parent = output.getParentFile();
        if (parent != null) {
            parent.mkdirs();
        }

        Set<String> requested = new HashSet<>();
        for (int index = 1; index < args.length; index++) {
            requested.add(args[index]);
        }

        List<Function> functions = new ArrayList<>();
        FunctionIterator iterator = currentProgram.getFunctionManager().getFunctions(true);
        while (iterator.hasNext()) {
            Function function = iterator.next();
            if (!function.isExternal() && !function.isThunk()
                    && requested.contains(function.getName())) {
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

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
            writer.write("/* Named Ghidra pseudocode; not original source. */\n");
            writer.write("/* Program: " + currentProgram.getName() + " */\n\n");
            for (Function function : functions) {
                monitor.setMessage("Decompiling " + function.getName());
                DecompileResults result = decompiler.decompileFunction(function, 180, monitor);
                writer.write("\n/* ================================================================\n");
                writer.write(" * Address: " + function.getEntryPoint() + "\n");
                writer.write(" * Symbol: " + function.getName() + "\n");
                writer.write(" * Signature: " + function.getSignature().getPrototypeString() + "\n");
                writer.write(" * ================================================================ */\n");
                if (result.decompileCompleted() && result.getDecompiledFunction() != null) {
                    writer.write(result.getDecompiledFunction().getC());
                } else {
                    writer.write("/* DECOMPILATION FAILED: " + result.getErrorMessage() + " */\n");
                }
                writer.flush();
            }
            if (functions.size() != requested.size()) {
                writer.write("\n/* Requested " + requested.size() + " names; found "
                    + functions.size() + ". */\n");
            }
        } finally {
            decompiler.dispose();
        }
        println("Exported " + functions.size() + " named functions to " + output);
    }
}
