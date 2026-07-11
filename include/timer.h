#pragma once
#include <chrono>

template <typename Func>

double executionTimeCounter(Func f)
{
    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsedTime = stop - start;
    
    return elapsedTime.count();
}