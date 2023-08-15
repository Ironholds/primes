#' Find the Greatest Common Divisor, Smallest Common Multiple, or Coprimality
#'
#' These functions provide vectorized computations for the greatest common
#' divisor (`gcd`), smallest common multiple (`scm`), and coprimality. Coprime
#' numbers are also called _mutually prime_ or _relatively prime_ numbers.
#' The smallest common multiple is often called the _least common multiple_.
#'
#' The greatest common divisor uses Euclid's algorithm, a fast and widely
#' used method. The smallest common multiple and coprimality are computed using
#' the gcd, where \eqn{scm = \frac{a}{gcd(a, b)} \times b}{scm = a / gcd(a, b) * b}
#' and two numbers are coprime when \eqn{gcd = 1}.
#'
#' The `gcd`, `scm`, and `coprime` functions perform element-wise computation.
#' The `Rgcd` and `Rscm` functions perform `gcd` and `scm` over multiple values
#' using reduction. That is, they compute the greatest common divisor and least
#' common multiple for an arbitrary number of integers based on the properties
#' \eqn{gcd(a_1, a_2, ..., a_n) = gcd(gcd(a_1, a_2, ...), a_n)} and
#' \eqn{scm(a_1, a_2, ..., a_n) = scm(scm(a_1, a_2, ...), a_n)}. The binary
#' operation is applied to two elements; then the result is used as the first
#' operand in a call with the next element. This is done iteratively until all
#' elements are used. It is idiomatically equivalent to `Reduce(gcd, x)` or
#' `Reduce(scm, x)`, where `x` is a vector of integers, but much faster.
#'
#' @param m,n,... integer vectors.
#'
#'@examples
#' gcd(c(18, 22, 49, 13), 42)
#' ## [1] 6 2 7 1
#'
#' Rgcd(18, 24, 36, 12)
#' ## [1] 6
#'
#' scm(60, 90)
#' ## [1] 180
#'
#' Rscm(1:10)
#' ## [1] 2520
#'
#' coprime(60, c(77, 90))
#' ## [1]  TRUE FALSE
#' @return The functions `gcd`, `scm`, and `coprime` return a vector of the
#'   length of longest input vector. If one vector is shorter, it will be
#'   recycled. The `gcd` and `scm` functions return an integer vector while
#'   `coprime` returns a logical vector. The reduction functions `Rgcd` and
#'   `Rscm` return a single integer.
#' @author Paul Egeler, MS
#' @name gcd
NULL

# Note on the following two functions:
# microbenchmark shows that writing custom reduction code resulted in 10x speed
# increase over using base::Reduce. Another approach was recursion, but that was
# similarly slower than relying on a for loop in Rcpp.
# Rscm <- function(x) {
#   if (length(x) < 2)
#     x
#   else if (length(x) == 2)
#     scm_(x[1], x[2])
#   else
#     scm_(x[1], Recall(x[-1]))
# }

#' @rdname gcd
#' @export
Rgcd <- function(...) {
  x <- unlist(list(...))
  if (length(x))
    Rgcd_(x)
  else
    integer(0)
}

#' @rdname gcd
#' @export
Rscm <- function(...) {
  x <- unlist(list(...))
  if (length(x))
    Rscm_(x)
  else
    integer(0)
}
