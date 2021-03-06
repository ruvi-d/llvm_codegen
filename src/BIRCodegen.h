#ifndef BIR_CODEGEN_H_
#define BIR_CODEGEN_H_

#include <memory>
#include <llvm-11/llvm/IR/Module.h>
#include <llvm-11/llvm/IR/LLVMContext.h>
#include <llvm-11/llvm/IR/IRBuilder.h>
#include <llvm-11/llvm/IR/DerivedTypes.h>

namespace ballerina {
class BIRCodegen {
private:
  /* data */
  std::unique_ptr<llvm::LLVMContext> mContext;
  std::unique_ptr<llvm::Module> mModule;
  std::unique_ptr<llvm::IRBuilder<>> mBuilder;
  llvm::FunctionType *codegenFunctionType();
  void codegenMainExpr();

public:
  BIRCodegen();
  ~BIRCodegen()=default;
  void codegenPackage();
  void configureTarget();
  void dumpLLVMIR();
};

} // namespace ballerina

#endif // BIR_CODEGEN_H_