context("Euler's totient")

test_that("phi matches reference values", {
  expect_equal(phi(9), 6L)
  expect_equal(phi(120:125), c(32L,110L,60L,80L,60L,100L))
})
