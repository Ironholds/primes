context("Euler's totient")

test_that("phi matches reference values", {
  expect_equal(phi(9), 6L)
  expect_equal(phi(120:125), c(32L,110L,60L,80L,60L,100L))

  # Ironholds/primes#14
  expect_equal(phi(c(451,737,803,902)), c(400L, 660L, 720L, 400L))
  expect_equal(phi(c(9460L, 9713L, 9782L, 9977L)), c(3360L, 8820L, 4752L, 9060L))
})
