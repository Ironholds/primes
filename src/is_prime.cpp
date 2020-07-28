#include "primes.h"

bool is_prime_(int x) {

  bool out = true;
  if (x <= 3) {
    out = (x > 1);
  } else if (x % 2 == 0 || x % 3 == 0) {
    out = false;
  } else {
    for(int i=5, stop=sqrt((double) x); i <= stop; i+=6) {
      if (x % i == 0 || x % (i + 2) == 0) {
        out = false;
        break;
      }
    }
  }

  return out;
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
std::vector<bool> is_prime(std::vector<int> x) {

  std::vector<bool> out;
  out.reserve(x.size());

  for (auto n : x)
    out.push_back(is_prime_(n));

  return out;
}
