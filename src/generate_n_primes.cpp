#include "primes.h"

//' @rdname generate_primes
//' @export
// [[Rcpp::export]]
std::vector<int> generate_n_primes(int n) {
  if (n < 1)
    return {};

  int max = n >= 6 ? nth_prime_estimate(n, true) : 11;
  auto out = generate_primes_(2, max);
  out.resize(n);
  return out;
}
