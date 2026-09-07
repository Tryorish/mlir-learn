
include "mlir/IR/OpBase.td"

def Noisy_Dialect : Dialect {
    let name = "noisy";
    let summary = "A dialect for arithmetic on noisy i32s";
    let cppNamespace = "::mlir::tutorial::noisy";
    let useDefaultTypePrinterParser = 1;
}
