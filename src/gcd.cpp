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

// [[Rcpp::export]]
int Rgcd_(const Rcpp::IntegerVector& x) {
  int out = x[0];
  for (auto it=x.begin() + 1; it != x.end() && out != 1; ++it) {
    out = gcd_(out, *it);
  }
  return out;
}

// [[Rcpp::export]]
int scm_(int m, int n) {
  return m == 0 || n == 0 ? 0 : abs(m / gcd_(m, n) * n);
}

// [[Rcpp::export]]
int Rscm_(const Rcpp::IntegerVector& x) {
  int out = x[0];
  for (auto it=x.begin() + 1; it != x.end(); ++it) {
    out = scm_(out, *it);
  }
  return out;
}

//' @rdname gcd
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
    out[i] = scm_(a[i], b[i]);

  return out;
}

//' @rdname gcd
//' @export
// [[Rcpp::export]]
Rcpp::LogicalVector coprime(const Rcpp::IntegerVector& m,
                            const Rcpp::IntegerVector& n) {
  return gcd(m, n) == 1;
}
