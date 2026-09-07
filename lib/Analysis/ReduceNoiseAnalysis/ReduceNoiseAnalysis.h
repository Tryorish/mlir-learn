#ifndef LIB_ANALYSIS_REDUCENOISEANALYSIS_REDUCENOISEANALYSIS_H_
#define LIB_ANALYSIS_REDUCENOISEANALYSIS_REDUCENOISEANALYSIS_H_

#include "llvm/include/ADT/DenseMap.h"
#include "mlir/include/mlir/IR/Operation.h"
#include "mlir/include/mlir/IR/Value.h"

namespace mlir {
namespace tutorial {

class ReduceNoiseAnalysis {
public:
    ReduceNoiseAnalysis(Operation* op);
    ~ReduceNoiseAnalysis() = default;

    // Return true if a reduce_noise op should be inserted after the given
    // operation, according to the solution to the optimization problem.
    bool shouldInsertReduceNoise(Operation* op) const {
        return solution.lookup(op);
    }
private:
    llvm::DenseMap<Operation*, bool> solution;
};

}
}

#endif