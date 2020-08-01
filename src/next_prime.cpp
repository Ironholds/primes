#include "primes.h"

//' Find the Next and Previous Prime Numbers
//'
//' Find the next prime numbers or previous prime numbers over a vector.
//'
//' For `prev_prime`, if a value is less than or equal to 2, the function will
//' return `NA`.
//'
//' @param x a vector of integers from which to start the search.
//'
//' @examples
//' next_prime(5)
//' ## [1] 7
//'
//' prev_prime(5:7)
//' ## [1] 3 5 5
//' @aliases prev_prime
//' @return An integer vector of prime numbers.
//' @author Paul Egeler, MS
//' @export
// [[Rcpp::export]]
Rcpp::IntegerVector next_prime(const Rcpp::IntegerVector& x) {

  Rcpp::IntegerVector out(x.size());
  auto it = out.begin();

  for (auto n : x) {
    while (!is_prime_(++n))
      ;
    *(it++) = n;
  }

  return out;
}

//' @rdname next_prime
//' @export
// [[Rcpp::export]]
Rcpp::IntegerVector prev_prime(const Rcpp::IntegerVector& x) {

  Rcpp::IntegerVector out(x.size());
  auto it = out.begin();

  for (auto n : x) {
    while (!is_prime_(--n) && n >= 2)
      ;
    *(it++) = n >= 2 ? n : NA_INTEGER;
  }

  return out;
}
