context("nth prime")

test_that("The nth prime is correct", {
  expect_equal(nth_prime(5), 11L)
  expect_equal(nth_prime(0), NA_integer_)
})
