#include "primes.h"

static const double prime_count_c = 30 * log((double) 113) / 113;

//' @rdname prime_count
//' @export
// [[Rcpp::export]]
int prime_count(int n, bool upper_bound) {
  return (upper_bound ? prime_count_c : 1) * n / log((double) n);
}

//' @rdname prime_count
//' @export
// [[Rcpp::export]]
int nth_prime_estimate(int n, bool upper_bound) {
  double c = upper_bound ? 0 : 1;
  return n * (log(n * log((double) n)) - c);
}
