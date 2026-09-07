#include "lib/Transform/Noisy/ReduceNoiseOptimizer.h"

namespace mlir {
namespace tutorial {
namespace noisy {

#define GEN_PASS_REGISTRATION
#include "lib/Transform/Noisy/Passes.h.inc"

}
}
}