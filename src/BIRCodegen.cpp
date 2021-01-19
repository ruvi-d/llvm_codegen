#include "BIRCodegen.h"
#include <llvm/ADT/APInt.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/raw_ostream.h>
#include <vector>

namespace ballerina {
void BIRCodegen::codegenPackage() {

  codegenMainExpr();

  return;
}

void BIRCodegen::codegenMainExpr() {
  llvm::FunctionType *mainType =
      llvm::FunctionType::get(llvm::IntegerType::getInt32Ty(*mContext),
                              std::vector<llvm::Type *>(), false /* isVarArgs */
      );
  llvm::Function *main = llvm::Function::Create(
      mainType, llvm::Function::ExternalLinkage, "main", mModule.get());

  llvm::BasicBlock *mainBasicBlock =
      llvm::BasicBlock::Create(*mContext, "entry", main);
  mBuilder->SetInsertPoint(mainBasicBlock);

  // Add main expressions

  llvm::APInt retVal(32 /* bitSize */, (uint32_t)42, true /* signed */);
  mBuilder->CreateRet(llvm::ConstantInt::get(*(mContext), retVal));
  llvm::verifyFunction(*main);
}

void BIRCodegen::dumpLLVMIR() { mModule->print(llvm::outs(), nullptr); }

void BIRCodegen::configureTarget() {
  auto TargetTriple = llvm::sys::getDefaultTargetTriple();
  // mModule->setDataLayout();
  mModule->setTargetTriple(TargetTriple);
}

BIRCodegen::BIRCodegen()
    : mContext{std::make_unique<llvm::LLVMContext>()},
      mModule{std::make_unique<llvm::Module>("Module", *mContext)},
      mBuilder{std::make_unique<llvm::IRBuilder<>>(*mContext)} {}

} // namespace ballerina