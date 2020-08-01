#include "primes.h"

bool is_prime_(int x) {

  if (x < 4)
    return x > 1;

  if (x % 2 == 0 || x % 3 == 0)
    return false;

  for(int i=5, stop=sqrt((double) x); i <= stop; i+=6)
    if (x % i == 0 || x % (i + 2) == 0)
      return false;

  return true;
}

//' Test for Prime Numbers
//'
//' Test whether a vector of numbers is prime or composite.
//'
//' @param x an integer vector containing elements to be tested for primality.
//'
//' @examples
//' is_prime(4:7)
//' ## [1] FALSE  TRUE FALSE  TRUE
//'
//' is_prime(1299827)
//' ## [1] TRUE
//'
//' @return A logical vector.
//' @author Os Keyes and Paul Egeler, MS
//' @export
// [[Rcpp::export]]
Rcpp::LogicalVector is_prime(const Rcpp::IntegerVector& x) {

  int len = x.size();
  Rcpp::LogicalVector out(len);

  for (int i=0; i < len; i++)
    out[i] = is_prime_(x[i]);

  return out;
}
