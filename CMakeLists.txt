cmake_minimum_required(VERSION 3.10)
project(TokenBucketRateLimiter)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(rate_limiter
    src/main.cpp
    src/rate_limiter.cpp
)
