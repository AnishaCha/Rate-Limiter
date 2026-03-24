#include "rate_limiter.h"
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

TimeStamp RateLimiter::getCurrentTimeMs() const {
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

BucketState& RateLimiter::refillBucket(const string& key) {
    BucketState& bucket = buckets[key];
    TimeStamp now = getCurrentTimeMs();

    if (bucket.lastRefill == 0) {
        bucket.tokens = BUCKET_CAPACITY;
        bucket.lastRefill = now;
        return bucket;
    }

    double timeElapsedSeconds = (double)(now - bucket.lastRefill) / 1000.0;
    double tokensToAdd = timeElapsedSeconds * REFILL_RATE_PER_SEC;

    bucket.tokens = min(bucket.tokens + tokensToAdd, (double)BUCKET_CAPACITY);
    bucket.lastRefill = now;

    return bucket;
}

bool RateLimiter::allowRequest(const string& key) {
    BucketState& bucket = refillBucket(key);

    if (bucket.tokens >= 1.0) {
        bucket.tokens -= 1.0;
        cout << "[ALLOWED] " << key << " Remaining: " << bucket.tokens << endl;
        return true;
    } else {
        cout << "[BLOCKED] " << key << endl;
        return false;
    }
}

void RateLimiter::initializeBucket(const string& key) {
    buckets[key] = {0.0, 0};
}
