context("Prime-counting funcs")

test_that("Number of primes <= n", {
  expect_gte(prime_count(100, TRUE),  length(generate_primes(max = 100)))
  expect_lte(prime_count(100, FALSE), length(generate_primes(max = 100)))
})

test_that("Value of nth prime", {
  expect_gte(nth_prime_estimate(100, TRUE),  generate_n_primes(100)[100])
  expect_lte(nth_prime_estimate(100, FALSE), generate_n_primes(100)[100])
})
