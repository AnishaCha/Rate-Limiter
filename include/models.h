#pragma once
using TimeStamp = long long;

struct BucketState {
    double tokens;
    TimeStamp lastRefill;
};
