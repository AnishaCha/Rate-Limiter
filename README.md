# Token Bucket Rate Limiter (C++)

A high-performance **Token Bucket Rate Limiter** implemented in C++, widely used in **API Gateways, Distributed Systems, and Traffic Control**.

This project demonstrates real-world system design concepts like **rate limiting, burst handling, and time-based state management**.

---

# What is a Rate Limiter?

A **rate limiter** controls how many requests a user/service can make in a given time.

Prevents:

* System overload
* Abuse / DDoS
* Resource starvation

---

# Token Bucket Algorithm

## Concept

* Bucket = maximum request capacity
* Tokens = permission to process requests
* Tokens refill at a fixed rate

---

## How it works

1. Bucket starts full
2. Each request consumes 1 token
3. Tokens refill over time
4. If no tokens → request is **blocked**

---

## Example

* Capacity = 100
* Refill Rate = 10 tokens/sec

Burst allowed: **100 requests instantly**
Sustained rate: **10 requests/sec**

## Real-world usage

### API Gateways

* Amazon API Gateway
* Google Cloud Endpoints

Control user traffic and prevent abuse

---

### Distributed Systems

* Per-user throttling
* Fair usage enforcement

---

### Databases & Caches

* Protect backend systems like Redis / MySQL
* Prevent overload

---

### Messaging Systems

* Control consumer rate in Kafka

---


# Project Structure

```bash
rate-limiter-token-bucket/
│── src/
│   ├── main.cpp
│   ├── rate_limiter.cpp
│
│── include/
│   ├── rate_limiter.h
│   ├── models.h
│
│── CMakeLists.txt
│── README.md
```

---

# Build & Run

## Using g++

```bash
g++ src/*.cpp -Iinclude -o rate_limiter
./rate_limiter
```

---

## Using CMake

```bash
mkdir build
cd build
cmake ..
make
./rate_limiter
```

---

# Example Output

```
--- Initial Burst ---
[ALLOWED] user_A_123 Remaining: 99
[ALLOWED] user_A_123 Remaining: 98
...

--- Waiting 2 seconds ---

--- After Refill ---
[ALLOWED] user_A_123 Remaining: 90
[BLOCKED] user_A_123
```

---

# 🙌 Contribute

Feel free to fork, improve, and raise PRs!
