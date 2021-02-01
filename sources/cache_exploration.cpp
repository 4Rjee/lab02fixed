// Copyright 2020 Kochurin Nikita kochurin.nikita@gmail.com

#include "cache_exploration.hpp"
#include <algorithm>
#include <random>
const size_t Sixteen = 16;
const size_t One_thousand = 1000;

cache_exploration::cache_exploration() {
  for (size_t i = 1.0 / 2 * cache_size[0]; i < 3.0 / 2 * cache_size[2];
       i *= 2) {
    buffer_size.push_back(i);
  }
  buffer_size.push_back(3.0 / 2 * cache_size[2]);
}
void cache_exploration::direct_travel() {
  travel_variant = "direct";
  int k;
  if (!travel_time.empty()) {
    travel_time.clear();
  }
  for (const size_t& i : buffer_size) {
    int* arr = new int[i / 4];
    for (size_t j = 0; j < i / 4; j += Sixteen) {
      k = arr[j];
    }
    clock_t start_travel = clock();
    for (size_t n = 0; n < One_thousand; ++n) {
      for (size_t j = 0; j < i / 4; j += Sixteen) {
        k = arr[j];
      }
    }
    clock_t end_travel = clock();
    travel_time.push_back(static_cast<double>(end_travel - start_travel) /
                          CLOCKS_PER_SEC * One_thousand);
    delete[] arr;
    ++k;
  }
}
void cache_exploration::reverse_travel() {
  travel_variant = "reverse";
  int k;
  if (!travel_time.empty()) {
    travel_time.clear();
  }
  for (const size_t& i : buffer_size) {
    int* arr = new int[i / 4];
    for (size_t j = i / 4; j > 0; j -= Sixteen) {
      k = arr[j - 1];
    }
    clock_t start_travel = clock();
    for (size_t n = 0; n < One_thousand; ++n) {
      for (size_t j = i / 4; j > 0; j -= Sixteen) {
        k = arr[j - 1];
      }
    }
    clock_t end_travel = clock();
    travel_time.push_back(static_cast<double>(end_travel - start_travel) /
                          CLOCKS_PER_SEC * One_thousand);
    delete[] arr;
    ++k;
  }
}
void cache_exploration::random_travel() {
  travel_variant = "random";
  int k;
  if (!travel_time.empty()) {
    travel_time.clear();cache_exploration::cache_exploration() {
  for (size_t i = 1.0 / 2 * cache_size[0]; i < 3.0 / 2 * cache_size[2];
       i *= 2) {
    buffer_size.push_back(i);
  }
  buffer_size.push_back(3.0 / 2 * cache_size[2]);
}
  }
  for (const size_t& i : buffer_size) {
    std::vector<size_t> rand_values;
    int* arr = new int[i / 4];
    for (size_t j = 0; j < i / 4; j += Sixteen) {
      k = arr[j];
      rand_values.push_back(j);
    }
    std::random_device rd;
    std::mt19937 rnd(rd());
    std::shuffle(rand_values.begin(), rand_values.end(), rnd);
    clock_t start_travel = clock();
    for (size_t n = 0; n < One_thousand; ++n) {
      for (const auto& index : rand_values) {
        k = arr[index];
      }
    }
    clock_t end_travel = clock();
    travel_time.push_back(static_cast<double>(end_travel - start_travel) /
                          CLOCKS_PER_SEC * One_thousand);
    delete[] arr;
    ++k;
  }
}
std::ostream& operator<<(std::ostream& out, const cache_exploration& c) {
  out << "investigation:\n"
      << "\ttravel_order: " << c.travel_variant << "\n"
      << "\texperiments:\n";
  for (size_t i = 0; i < c.buffer_size.size(); ++i) {
    out << "\t- experiment: \n"
        << "\t\tnumber: " << i + 1 << "\n"
        << "\t\tinput_data:\n"
        << "\t\t\tbuffer_size: " << c.buffer_size[i] / Kilobyte << "KB\n"
        << "\t\tresults:\n"
        << "\t\t\tduration: " << c.travel_time[i] << "ms\n";
  }
  return out;
}
