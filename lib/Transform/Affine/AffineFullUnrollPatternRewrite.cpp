#include "lib/Transform/Affine/AffineFullUnrollPatternRewrite.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/include/mlir/Pass/Pass.h"

namespace mlir {
namespace tutorial {

#define GEN_PASS_DEF_AFFINEFULLUNROLLPATTERNREWRITE
#include "lib/Transform/Affine/Passes.h.inc"

using mlir::affine::AffineForOp;
using mlir::affine::loopUnrollFull;

struct AffineFullUnrollPattern : public OpRewritePattern<AffineForOp> {
    AffineFullUnrollPattern(mlir::MLIRContext* context) :
        OpRewritePattern<AffineForOp>(context, 1) {}
    
    LogicalResult matchAndRewrite(AffineForOp op, PatternRewriter &rewriter) const override {
        return loopUnrollFull(op);
    }
};

struct AffineFullUnrollPatternRewrite : 
    impl::AffineFullUnrollPatternRewriteBase<AffineFullUnrollPatternRewrite> {
    
    using AffineFullUnrollPatternRewriteBase::AffineFullUnrollPatternRewriteBase;
    void runOnOperation() {
        mlir::RewritePatternSet patterns(&getContext());
        patterns.add<AffineFullUnrollPattern>(&getContext());
        (void)applyPatternsAndFoldGreedily(getOperation(), std::move(patterns));
    }    
};

}
}