// Copyright 2020 Kochurin Nikita kochurin.nikita@gmail.com

#include <gtest/gtest.h>

#include <cache_exploration.hpp>

TEST(Example, EmptyTest) {
  cache_exploration cache;
  cache.direct_travel();
  std::cout << cache;
  cache.reverse_travel();
  std::cout << cache;
  cache.random_travel();
  std::cout << cache;
  EXPECT_TRUE(true);
}