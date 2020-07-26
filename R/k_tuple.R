#' Prime _k_-tuples
#'
#' Use prime _k_-tuples to create lists of twin primes, cousin primes,
#' prime triplets, and so forth.
#'
#' You can construct your own tuples and generate series of primes using
#' `k_tuple`; however, there are functions that exist for some of the named
#' relationships. They are listed below.
#'
#' \itemize{
#'   \item `twin_primes`: represents `c(0,2)`.
#'   \item `cousin_primes`: represents `c(0,4)`.
#'   \item `third_cousin_primes`: represents `c(0,8)`.
#'   \item `sexy_primes`: represents `c(0,6)`.
#'   \item `sexy_prime_triplets`: represents `c(0,6,12)`.
#' }
#'
#' The term "third cousin primes" is of the author's coinage. There is no
#' canonical name for that relationship to the author's knowledge.
#'
#' @inheritParams generate_primes
#' @param tuple an integer vector representing the target _k_-tuple pattern.
#'
#' @examples
#' # All twin primes up to 13
#' twin_primes(2, 13) # Identical to `k_tuple(2, 13, c(0,2))`
#' ## [[1]]
#' ## [1] 3 5
#' ##
#' ## [[2]]
#' ## [1] 5 7
#' ##
#' ## [[3]]
#' ## [1] 11 13
#'
#' # Some prime triplets
#' k_tuple(2, 19, c(0,4,6))
#' ## [[1]]
#' ## [1]  7 11 13
#' ##
#' ## [[2]]
#' ## [1] 13 17 19
#'
#' @return A list of vectors of prime numbers satisfying the condition of
#'   `tuple`.
#' @author Paul Egeler, MS
#' @name k_tuple
NULL

#' @rdname k_tuple
#' @export
twin_primes <- function(min, max)
  k_tuple(min, max, c(0,2))

#' @rdname k_tuple
#' @export
cousin_primes <- function(min, max)
  k_tuple(min, max, c(0,4))

#' @rdname k_tuple
#' @export
sexy_primes <- function(min, max)
  k_tuple(min, max, c(0,6))

#' @rdname k_tuple
#' @export
sexy_prime_triplets <- function(min, max)
  k_tuple(min, max, c(0,6,12))

#' @rdname k_tuple
#' @export
third_cousin_primes <- function(min, max)
  k_tuple(min, max, c(0,8))
