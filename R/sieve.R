#' Generate a Sequence of Prime Numbers
#'
#' Generate a sequence of prime numbers from `min` to `max` or generate a vector
#' of the first `n` primes. Both functions use a fast implementation of the
#' Sieve of Eratosthenes.
#'
#' @param min the lower bound of the sequence.
#' @param max the upper bound of the sequence.
#' @param n the number of primes to generate.
#' @examples
#' generate_primes(max = 12)
#' ## [1]  2  3  5  7 11
#'
#' generate_n_primes(5)
#' ## [1]  2  3  5  7 11
#' @return An integer vector of prime numbers.
#' @author Paul Egeler, MS
#' @export
generate_primes <- function(min = 2L, max){
  .Call('_primes_generate_primes_', PACKAGE = 'primes', min, max)
}
