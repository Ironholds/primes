#include "primes.h"

bool is_prime_single(int x) {

  bool output = true;
  if (x <= 3) {
    output = (x > 1);
  } else if (x % 2 == 0 || x % 3 == 0) {
    output = false;
  } else {
    for(int i=5, stop=sqrt(x); i <= stop; i+=6) {
      if (x % i == 0 || x % (i + 2) == 0) {
        output = false;
        break;
      }
    }
  }

  return output;
}

// [[Rcpp::export]]
std::vector<bool> is_prime_vector(std::vector<int> x) {

  std::vector<bool> output;
  output.reserve(x.size());

  for (auto n : x)
    output.push_back(is_prime_single(n));

  return output;
}
