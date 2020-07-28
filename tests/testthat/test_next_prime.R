context("Next and previous primes")

test_that("Search for next prime works", {
  expect_equal(next_prime(-1:7), c(2L, 2L, 2L, 3L, 5L, 5L, 7L, 7L, 11L))
})

test_that("Search for previous also works", {
  expect_equal(prev_prime(-1:7), c(NA, NA, NA, NA, 2L, 3L, 3L, 5L, 5L))
})
