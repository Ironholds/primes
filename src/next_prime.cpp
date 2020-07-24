#include "primes.h"

//' Find the Next and Previous Prime Numbers
//'
//' Find the next prime number or previous prime number in a vector.
//'
//' For `next_prime`, if a value is less than or equal to 2, the function will
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
//' @export
// [[Rcpp::export]]
Rcpp::IntegerVector next_prime(std::vector<int> x) {

  Rcpp::IntegerVector out(x.size());
  Rcpp::IntegerVector::iterator it = out.begin();

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
Rcpp::IntegerVector prev_prime(std::vector<int> x) {

  Rcpp::IntegerVector out(x.size(), NA_INTEGER);
  Rcpp::IntegerVector::iterator it = out.begin();

  for (auto n : x) {
    while (!is_prime_(--n) && n >= 2)
      ;
    if (n >= 2)
      *it = n;
    it++;
  }

  return out;
}
