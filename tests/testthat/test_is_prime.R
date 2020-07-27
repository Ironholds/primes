context("Primality tests")

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
