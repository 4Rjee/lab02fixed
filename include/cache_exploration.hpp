// Copyright 2020 Kochurin Nikita kochurin.nikita@gmail.com

#ifndef INCLUDE_CACHE_EXPLORATION_HPP_
#define INCLUDE_CACHE_EXPLORATION_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

const size_t Kilobyte = 1024;

class cache_exploration {
 public:
  cache_exploration();
  void direct_travel();
  void reverse_travel();
  void random_travel();
  friend std::ostream& operator<<(std::ostream& out,
                                  const cache_exploration& c);

 private:
  std::string travel_variant;
  const std::vector<size_t> cache_size = {64 * Kilobyte, 256 * Kilobyte,
                                          6144 * Kilobyte};
  std::vector<size_t> buffer_size;
  std::vector<double> travel_time;
};

#endif  // INCLUDE_CACHE_EXPLORATION_HPP_