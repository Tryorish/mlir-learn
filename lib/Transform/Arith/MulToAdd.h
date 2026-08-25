#ifndef LIB_TRANSFORM_ARITH_MULTOADD_H
#define LIB_TRANSFORM_ARITH_MULTOADD_H

#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/include/mlir/Pass/Pass.h"

namespace mlir {
namespace tutorial {

class MulToAddPass : public PassWrapper<MulToAddPass, OperationPass<mlir::func::FuncOp>>{
private:
    void runOnOperation() override;

    StringRef getArgument() const final {return "mul-to-add";}

    StringRef getDescription() const final {return "Convert multiplications to repeated additions";}

};

} // namespace tutorial
}


#endif