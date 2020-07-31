context("GCD")

test_that("The gcd works", {
  expect_equal(gcd(integer(0), integer(0)), integer(0))
  expect_equal(gcd(5L, 5L), 5L)
  expect_equal(gcd(5L, 0L), 5L)
  expect_equal(gcd(c(154, 32, 105, 29), c(42,12)), c(14L, 4L, 21L, 1L))
})

test_that("The lcm works", {
  expect_equal(lcm(integer(0), integer(0)), integer(0))
  expect_equal(lcm(5L, 5L), 5L)
  expect_equal(lcm(5L, 0L), 0L)
  expect_equal(lcm(c(154, 32, 105, 29), c(42,12)), c(462L, 96L, 210L, 348L))
})

test_that("is_coprime works", {
  expect_true(is_coprime(35,99))
  expect_false(is_coprime(72, 210))
  expect_equal(is_coprime(c(26:27, 39), 13), c(FALSE, TRUE, FALSE))
  expect_equal(is_coprime(99, integer(0)), logical(0))
})
