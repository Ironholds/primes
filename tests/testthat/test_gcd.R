context("GCD")

test_that("The gcd works", {
  expect_equal(gcd(integer(0), integer(0)), integer(0))
  expect_equal(gcd(5L, 5L), 5L)
  expect_equal(gcd(5L, 0L), 5L)
  expect_equal(gcd(c(154, 32, 105, 29), c(42,12)), c(14L, 4L, 21L, 1L))
})

test_that("The scm works", {
  expect_equal(scm(integer(0), integer(0)), integer(0))
  expect_equal(scm(5L, 5L), 5L)
  expect_equal(scm(5L, 0L), 0L)
  expect_equal(scm(c(154, 32, 105, 29), c(42,12)), c(462L, 96L, 210L, 348L))
})

test_that("coprime works", {
  expect_true(coprime(35,99))
  expect_false(coprime(72, 210))
  expect_equal(coprime(c(26:27, 39), 13), c(FALSE, TRUE, FALSE))
  expect_equal(coprime(99, integer(0)), logical(0))
})
