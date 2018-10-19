// This is used as a test.

#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <functional>
#include <map>

std::vector<std::string> split(const std::string& s, char delimiter) {
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}

int plus(int a, int b) {
  return a + b;
}

int end(int a, int b) {
  return a + b;
}

int minus(int a, int b) {
  return a - b;
}

std::map<std::string, std::function<int(int, int)>> kOperators = {
  {"+", plus},
  {"-", minus},
  {".", end},
};

int doSimpleCalc(std::string& simple) {
  int result = 0;

  auto tokens = split(simple, ' ');
  if (tokens.size() < 2) {
    // Nothing todo.
    return 0;
  }

  if (tokens[0] != "doSimpleCalc:") {
    // Nothing todo.
    return 0;
  }

  auto& ops = kOperators;
  for (size_t i = 2; i < tokens.size(); i++) {
    if (i % 2 == 0) {
      int n = 0;
      try {
        // TODO[1]: Uncomment this line.
        //n = std::stoi(tokens[i-1], nullptr, 0);

        // TODO[2]: Uncomment this line.
        //result = ops[tokens[i]](result, n);
      } catch (...) {
        // Let all exceptions pass through.
      }
      
      // TODO[1]: Erase this line.
      n = std::stoi(tokens[i-1], nullptr, 0);

      // TODO[2]: Erase this line.
      result = ops[tokens[i]](result, n);
    }
  }

  return result;
}

void printSimpleYay(int n) {
  char* yay = nullptr;

  if (n*3 > 4096) {
    // Too large, not so yay.

    // TODO[4]: Uncomment this line.
    // return;
  }

  yay = (char*)malloc((n*3<4096) ? n*3 : 4096);

  std::string oneyay{"yay"};
  for (size_t i = 0; i < n; i++) {
    memcpy(yay, oneyay.data(), oneyay.size());
  }

  printf("%s", yay);

  // TODO[3]: Make sure to keep memory sane.
  // free(yay);
}


