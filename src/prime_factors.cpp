#include <Rcpp.h>
#include <algorithm>  // max_element
#include <cmath>      // sqrt
#include <vector>

#include "primes.h"

static Rcpp::IntegerVector prime_factors_(int n, const std::vector<int> &primes) {
  Rcpp::IntegerVector factors;

  int stop = sqrt((double)n);
  for (auto p = primes.begin(); p != primes.end() && *p <= stop && n > 1; ++p) {
    while (n % *p == 0) {
      factors.push_back(*p);
      n /= *p;
    }
  }
  if (n > 1) {
    factors.push_back(n);
  }

  return factors;
}

//' Perform Prime Factorization on a Vector
//'
//' Compute the prime factors of elements of an integer vector.
//'
//' @param x an integer vector.
//'
//' @examples
//' prime_factors(c(1, 5:7, 99))
//' ## [[1]]
//' ## integer(0)
//' ##
//' ## [[2]]
//' ## [1] 5
//' ##
//' ## [[3]]
//' ## [1] 2 3
//' ##
//' ## [[4]]
//' ## [1] 7
//' ##
//' ## [[5]]
//' ## [1]  3  3 11
//'
//' @return A list of integer vectors reflecting the prime factorizations of
//'   each element of the input vector.
//' @author Paul Egeler, MS
//' @export
// [[Rcpp::export]]
Rcpp::List prime_factors(const Rcpp::IntegerVector &x) {
  if (!x.size())
    return {};

  Rcpp::List out(x.size());
  auto it = out.begin();
  int max = *std::max_element(x.begin(), x.end());
  auto primes = generate_primes_(2, max > 8 ? sqrt((double)max) : 2);

  for (auto n : x) {
    *(it++) = Rcpp::IntegerVector::is_na(n)
                  ? Rcpp::IntegerVector::create(NA_INTEGER)
                  : prime_factors_(n, primes);
  }

  return out;
}
