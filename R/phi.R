#' Euler's Totient Function
#'
#' Compute Euler's Totient Function (\eqn{\phi(n)}{phi(n)}). Provides the
#' count of \eqn{k} integers that are coprime with \eqn{n} such that
#' \eqn{1 \le k \le n}{1 <= k <= n} and \eqn{gcd(n,k) = 1}{gcd(n, k) == 1}.
#'
#' @param n an integer vector.
#'
#' @examples
#' phi(12)
#' ## [1] 4
#'
#' phi(c(9, 10, 142))
#' ## [1]  6  4 70
#'
#' @references "Euler's totient function" (2020) Wikipedia.
#'   https://en.wikipedia.org/wiki/Euler%27s_totient_function (Accessed 21 Aug
#'   2020).
#' @seealso \code{\link{gcd}}, \code{\link{coprime}}, \code{\link{prime_factors}}
#' @return An integer vector.
#' @author Paul Egeler, MS
#' @export
phi <- function(n) {
  factors <- prime_factors(n)
  vapply(
    seq_along(n),
    function(i) as.integer(n[i] * prod(1 - 1 / unique(factors[[i]]))),
    integer(1)
  )
}
