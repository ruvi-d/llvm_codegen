#include "BIRCodegen.h"

int main() {
  ballerina::BIRCodegen codeGenerator{};
  codeGenerator.codegenPackage();
  codeGenerator.configureTarget();
  codeGenerator.dumpLLVMIR();
  return 0;
}