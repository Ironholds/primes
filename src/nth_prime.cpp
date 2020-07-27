#include "primes.h"

//' Get the n-th Prime from the Sequence of Primes.
//'
//' Get the n-th prime (\eqn{p_n}) in the sequence of primes.
//'
//' @param n an integer.
//' @return An integer vector of length 1.
//' @author Paul Egeler, MS
//' @export
// [[Rcpp::export]]
int nth_prime(int n) {
  auto out = generate_n_primes(n);
  return out.size() ? *(out.end() - 1) : NA_INTEGER;
}
