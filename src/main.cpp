#include "rate_limiter.h"
#include <thread>
#include <iostream>

using namespace std;

int main() {
    RateLimiter limiter;
    string userId = "user_A_123";

    limiter.initializeBucket(userId);

    cout << "--- Initial Burst ---\n";
    for (int i = 0; i < 10; i++) {
        limiter.allowRequest(userId);
    }

    cout << "\n--- Waiting 2 seconds ---\n";
    this_thread::sleep_for(chrono::seconds(2));

    cout << "\n--- After Refill ---\n";
    for (int i = 0; i < 15; i++) {
        limiter.allowRequest(userId);
    }

    return 0;
}
