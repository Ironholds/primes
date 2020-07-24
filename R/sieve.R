#' Generate a Sequence of Prime Numbers
#'
#' Generates a sequence of prime numbers from `min` to `max` using a modified
#' Sieve of Eratosthenes.
#'
#' @param min the lower bound of the sequence.
#' @param max the upper bound of the sequence.
#' @examples
#' generate_primes(max = 12)
#' ## [1]  2  3  5  7 11
#' @export
generate_primes <- function(min = 2L, max){
  .Call('_primes_generate_primes_', PACKAGE = 'primes', min, max)
}
