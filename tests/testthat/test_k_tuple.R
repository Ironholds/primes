context("Twin primes and other k-tuples")

test_that("First twin primes are correct", {
  expect_equal(twin_primes(2,19), list(c(3L,5L),c(5L,7L),c(11L,13L),c(17L,19L)))
})

test_that("Prime triplets are correct", {
  expect_equal(k_tuple(2,19,c(0,2,6)), list(c(5L,7L,11L), c(11L,13L,17L)))
})
