#include "monteCarloPi.hpp"
#include <iostream>
#include <cstdlib>

int main() {
  auto experimentResults = idm::piReplications(1e9, 10u);
  std::cout << "Mean = " << experimentResults.mean << "\n";
  std::cout << "Stdev = " << experimentResults.stdDev << "\n";
  return EXIT_SUCCESS;
}
