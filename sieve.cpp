//
// Created by sienmich on 25.10.2019.
//

#include <cmath>
#include "sieve.h"

using namespace std;

vector<long long> primes(long long bound) {
    vector<bool> prime(bound + 1, false);
    long long root = sqrt(bound);

    vector<long long> res;
    if (bound >= 2)
        res.push_back(2);
    if (bound >= 3)
        res.push_back(3);
    if (bound >= 5)
        res.push_back(5);

    vector<long long> remindersAll = {1,7,11,13,17,19,23,29,31,37,41,43,47,49,53,59};
    vector<long long> possibles;
    for (long long i = 0; i < bound; i += 60)
        for (auto &x : remindersAll)
            possibles.push_back(i + x);
    while (possibles.size() && possibles[possibles.size() - 1] > bound)
        possibles.pop_back();

    vector<int> reminders[3] = {{1, 13, 17, 29, 37, 41, 49, 53},
                                {7, 19, 31, 43},
                                {11, 23, 47, 59}};
    vector<bool> buckets[3];
    for (int b = 0; b < 3; b++) {
        buckets[b].resize(60, false);
        for (auto &x : reminders[b])
            buckets[b][x] = true;
    }


    for (long long x = 1; x <= root; x++) {
        long long xx4 = 4 * x * x;
        for (long long y = 1; y <= root; y += 2) {
            long long n = xx4 + y * y;
            if (n > bound)
                break;
            if (buckets[0][n % 60])
                prime[n] = !prime[n];
        }
    }

    for (long long x = 1; x <= root; x += 2) {
        long long xx3 = 3 * x * x;
        for (long long y = 2; y <= root; y += 2) {
            long long n = xx3 + y * y;
            if (n > bound)
                break;
            if (buckets[1][n % 60])
                prime[n] = !prime[n];
        }
    }

    for (long long x = 2; x <= root; x += 1) {
        long long xx3 = 3 * x * x;
        for (long long y = x % 2 + 1; y < x; y += 2) {
            long long n = xx3 - y * y;
            if (n <= 0)
                break;
            if (n > bound)
                continue;
            if (buckets[2][n % 60])
                prime[n] = !prime[n];
        }
    }

    for (auto &n : possibles) {
        if (n > root)
            break;
        if (prime[n]) {
            long long nn = n * n;
            for (auto &c : possibles) {
                if (nn * c > bound)
                    break;
                prime[nn * c] = false;
            }
        }
    }

    for (auto &n : possibles) {
        if (prime[n]) {
            res.push_back(n);
        }
    }

    return res;
}

