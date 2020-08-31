#include "primes.h"

// [[Rcpp::export]]
int gcd_(int m, int n) {

  m = abs(m); n = abs(n);
  if (n > m)
    std::swap(m, n);

  // Euclid's Algorithm
  while (n > 0) {
    int r = m % n;
    m = n;
    n = r;
  }

  return m;
}

//' Find the Greatest Common Divisor, Smallest Common Multiple, or Coprimality
//'
//' These functions provide vectorized computations for the greatest common
//' divisor (`gcd`), smallest common multiple (`scm`), and coprimality. Coprime
//' numbers are also called _mutually prime_ or _relatively prime_ numbers.
//' The smallest common multiple is often called the _least common multiple_.
//'
//' The greatest common divisor uses Euclid's algorithm, a fast and widely
//' used method. The smallest common multiple and coprimality are computed using
//' the gcd, where \eqn{scm = \frac{a}{gcd(a, b)} \times b}{scm = a / gcd(a, b) * b}
//' and two numbers are coprime when \eqn{gcd = 1}.
//'
//' @param m,n integer vectors.
//'
//'@examples
//' gcd(c(18, 22, 49, 13), 42)
//' ## [1] 6 2 7 1
//'
//' scm(60, 90)
//' ## [1] 180
//'
//' coprime(60, c(77, 90))
//' ## [1]  TRUE FALSE
//' @return A vector of the length of longest input vector. If one
//'   vector is shorter, it will be recycled. The `gcd` and `scm` functions
//'   return an integer vector while `coprime` returns a logical vector.
//' @author Paul Egeler, MS
//' @export
// [[Rcpp::export]]
Rcpp::IntegerVector gcd(const Rcpp::IntegerVector& m,
                        const Rcpp::IntegerVector& n) {
  if (!m.size() || !n.size())
    return Rcpp::IntegerVector::create();

  int len = std::max(m.size(), n.size());
  Rcpp::IntegerVector out(len);
  auto a = Rcpp::rep_len(m, len);
  auto b = Rcpp::rep_len(n, len);

  for (int i=0; i < len; i++)
    out[i] = gcd_(a[i], b[i]);

  return out;
}

//' @rdname gcd
//' @aliases lcm
//' @export
// [[Rcpp::export]]
Rcpp::IntegerVector scm(const Rcpp::IntegerVector& m,
                        const Rcpp::IntegerVector& n) {
  if (!m.size() || !n.size())
    return Rcpp::IntegerVector::create();

  int len = std::max(m.size(), n.size());
  Rcpp::IntegerVector out(len);
  auto a = Rcpp::rep_len(m, len);
  auto b = Rcpp::rep_len(n, len);

  for (int i=0; i < len; i++)
    out[i] = a[i] == 0 || b[i] == 0 ? 0 : abs(a[i] / gcd_(a[i], b[i]) * b[i]);

  return out;
}

//' @rdname gcd
//' @export
// [[Rcpp::export]]
Rcpp::LogicalVector coprime(const Rcpp::IntegerVector& m,
                            const Rcpp::IntegerVector& n) {
  return gcd(m, n) == 1;
}
