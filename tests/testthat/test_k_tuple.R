context("Twin primes and other k-tuples")

test_that("First twin primes are correct", {
  expect_equal(twin_primes(2,19), list(c(3L,5L),c(5L,7L),c(11L,13L),c(17L,19L)))
})

test_that("Prime triplets are correct", {
  expect_equal(k_tuple(2,19,c(0,2,6)), list(c(5L,7L,11L), c(11L,13L,17L)))
})

test_that("Prime cousins are correct", {
  expect_equal(
    cousin_primes(0,29),
    list(c(3L, 7L), c(7L, 11L), c(13L, 17L), c(19L, 23L))
  )
})

test_that("Sexy prime triplets are correct", {
  expect_equal(
    sexy_prime_triplets(0,29),
    list(c(5L, 11L, 17L), c(7L, 13L, 19L), c(11L, 17L, 23L), c(17L, 23L, 29L))
  )
})
