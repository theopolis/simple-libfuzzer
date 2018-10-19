// This is used as a test.

#include "simple/simple.h"

#include <string>

/**
int main() {
  auto simple_string = std::string("doSimpleCalc: 1 - 1 + 2 + 3 .");
  auto result = doSimpleCalc(simple_string);

  printf("result: %d\n", result);
  return 0;
}
*/

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* Data, size_t Size) {
  std::string k((char*)Data, Size);
  auto n = doSimpleCalc(k);

  if (n == 103) {
    printSimpleYay(n);
  }
  return 0;
}
