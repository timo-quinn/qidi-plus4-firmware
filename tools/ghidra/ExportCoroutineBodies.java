// Export Cython coroutine implementations that the wrapper exporter omits.

import java.io.BufferedWriter;
import java.io.FileWriter;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class ExportCoroutineBodies extends GhidraScript {
    public void run() throws Exception {
        DecompInterface decompiler = new DecompInterface();
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(false);
        decompiler.openProgram(currentProgram);
        int total = 0;
        int done = 0;
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(getScriptArgs()[0]))) {
            writer.write("/* Static Cython coroutine decompilation; not original source. */\n");
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            while (functions.hasNext()) {
                Function f = functions.next();
                if (!f.getName().startsWith("__pyx_gb_")) continue;
                total++;
                writer.write("\n/* Address: " + f.getEntryPoint() + "\n * Symbol:  " + f.getName() + "\n */\n");
                DecompileResults r = decompiler.decompileFunction(f, 45, monitor);
                if (r.decompileCompleted() && r.getDecompiledFunction() != null) {
                    writer.write(r.getDecompiledFunction().getC());
                    done++;
                } else writer.write("/* FAILED: " + r.getErrorMessage() + " */\n");
                writer.flush();
            }
            writer.write("\n/* Successfully decompiled " + done + " of " + total + " coroutine bodies. */\n");
        } finally { decompiler.dispose(); }
        println("Exported " + done + " of " + total + " coroutine bodies");
    }
}
