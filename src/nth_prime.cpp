#include "primes.h"

//' Get the n-th Prime from the Sequence of Primes.
//'
//' Get the n-th prime, \eqn{p_n}, in the sequence of primes.
//'
//' @param x an integer vector.
//'
//' @examples
//' nth_prime(5)
//' ## [1] 11
//'
//' nth_prime(c(1:3, 7))
//' ## [1]  2  3  5 17
//' @return An integer vector.
//' @author Paul Egeler, MS
//' @export
// [[Rcpp::export]]
Rcpp::IntegerVector nth_prime(const Rcpp::IntegerVector& x) {
  if (!x.size())
    return Rcpp::IntegerVector::create();

  auto primes = generate_n_primes(*std::max_element(x.begin(), x.end()));
  auto out = Rcpp::IntegerVector(x.size());
  auto it  = out.begin();

  for (auto n : x)
    *(it++) = n > 0 ? primes[n - 1] : NA_INTEGER;

  return out;
}
