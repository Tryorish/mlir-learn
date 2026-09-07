include "mlir/Pass/PassBase.td"

def ReduceNoiseOptimizer : Pass<"noisy-reduce-noise-optimizer"> {
    let summary = "Insert reduce_noise ops optimally";
    let description = [{
        Solves an integer linear program to select the optimal locations in the IR to insert `reduce_noise` ops.
    }];
    let dependentDialects = ["mlir::tutorial::noisy::NoisyDialect"];
}
