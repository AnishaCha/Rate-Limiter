#pragma once
#include <string>
#include <unordered_map>
#include "models.h"
using namespace std;

class RateLimiter {
private:
    unordered_map<string, BucketState> buckets;
    const int BUCKET_CAPACITY = 100;
    const double REFILL_RATE_PER_SEC = 10.0;

    TimeStamp getCurrentTimeMs() const;
    BucketState& refillBucket(const string& key);

public:
    bool allowRequest(const string& key);
    void initializeBucket(const string& key);
};
