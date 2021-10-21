#include "monteCarloPi.hpp"
#include <iostream>

int main() {
  auto experimentResults = idm::piReplications(1e9, 10u);
  std::cout << experimentResults.mean << "\n";

}
