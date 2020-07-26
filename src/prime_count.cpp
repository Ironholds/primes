#include "primes.h"

// Estimating pi(x) -- the number of primes <= n
// This is a quick ball-park estimate
// `upper_bound = false` is guaranteed to under-estimate for n >= 17.
// [[Rcpp::export]]
int prime_count(int n, bool upper_bound) {
  return (upper_bound ? 1.26 : 1) * n / log(n);
}
