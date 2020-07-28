#' Find Ruth-Aaron Pairs of Integers
#'
#' Find pairs of consecutive integers where the prime factors sum to the same
#' value. For example, (5, 6) are Ruth-Aaron pairs because the prime factors
#' \eqn{5 = 2 + 3}{5 == 2 + 3}.
#'
#' @param min an integer representing the minimum number to check.
#' @param max an integer representing the maximum number to check.
#' @param distinct a logical indicating whether to consider repeating prime
#'   factors or only distinct prime number factors.
#' @author Paul Egeler, MS
#' @return A List of integer pairs.
#' @export
ruth_aaron_pairs <-function(min, max, distinct = FALSE) {
  n <- seq(min, max)

  sums <- vapply(
    prime_factors(n),
    if (distinct) function(x) sum(unique(x)) else function(x) sum(x),
    integer(1L)
  )

  lapply(
    which(c(-1L, diff(sums)) == 0L),
    function(x) n[c(x-1L, x)]
  )
}
