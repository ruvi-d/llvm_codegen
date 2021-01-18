#include <fstream>
#include <iostream>
#include <kaitai/kaitaistream.h>
#include "bir.h"

int main() {
  std::ifstream ifs("test-bir-dump", std::ifstream::binary);
  kaitai::kstream ks(&ifs);

  ballerina::bir_t bir(&ks);
  auto bir_funcs = bir.module()->functions();
  std::cout << "Function positions:" << std::endl;
  for (auto &func : *bir_funcs)
  {
    auto position = func->position();
    std::cout << "\tline "<< position->s_line() << std::endl;
  }
  return 0;
}