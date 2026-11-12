// Decompile every function in the current program and write C to <output dir>/<program>.c
// @category RT100
import java.io.File;
import java.io.PrintWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

public class DumpDecomp extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String outDir = getScriptArgs().length > 0 ? getScriptArgs()[0] : ".";
        File out = new File(outDir, currentProgram.getName() + ".c");
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);
        int count = 0;
        try (PrintWriter w = new PrintWriter(out)) {
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                DecompileResults r = decomp.decompileFunction(f, 60, monitor);
                w.println("// ===== " + f.getName() + " @ " + f.getEntryPoint());
                w.println(r.decompileCompleted() ? r.getDecompiledFunction().getC() : "// decompile failed");
                count++;
            }
        }
        println("wrote " + count + " functions to " + out);
    }
}
