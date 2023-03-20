#include <benchmark/benchmark.h>
#include <iostream>
#include <lib/lib.hpp>

static void BM_lib_test(benchmark::State &state) {
  for (auto _ : state) {
    lib::test();
  }
}

BENCHMARK(BM_lib_test);
