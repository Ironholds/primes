#include "primes.h"

//' @rdname primorial
//' @export
// [[Rcpp::export]]
int primorial_n(int n) {
  if (n > 28)
    Rcpp::stop("Integer overflow");
  auto primes = generate_primes_(2, n);
  int out = 1;
  for (auto p : primes)
    out *= p;
  return out;
}

//' @rdname primorial
//' @export
// [[Rcpp::export]]
int primorial_p(int n) {
  if (n > 9)
    Rcpp::stop("Integer overflow");
  auto primes = generate_primes_(2, 23);
  int out = 1;
  for (int i=0; i < n; i++)
    out *= primes[i];
  return out;
}
