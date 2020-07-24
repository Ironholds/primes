context("Test actual prime numbers are determined to be prime")

test_that("actual prime numbers are determined to be prime",{
  expect_true(is_prime(5))
  expect_true(is_prime(9587))
  expect_true(is_prime(1299827))
})

test_that("Non-primes are determined to be not-prime", {
  expect_false(is_prime(4))
  expect_false(is_prime(9586))
  expect_false(is_prime(1299824))
})

context("Test prime numbers can be generated")

test_that("Prime numbers can be generated, full stop", {
  expect_that(generate_primes(max=12), equals(c(2,3,5,7,11)))
})

test_that("'min' is respected", {
  expect_that(generate_primes(4, 12), equals(c(5,7,11)))
  expect_that(generate_primes(5, 12), equals(c(5,7,11)))
})


context("Test for next and previous")

test_that("Search for next prime works", {
  expect_that(next_prime(-1:7), equals(c(2L, 2L, 2L, 3L, 5L, 5L, 7L, 7L, 11L)))
})

test_that("Search for previous also works", {
  expect_that(prev_prime(-1:7), equals(c(NA, NA, NA, NA, 2L, 3L, 3L, 5L, 5L)))
})
