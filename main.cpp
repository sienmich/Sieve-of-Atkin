//
// Created by sienmich on 25.10.2019.
//

#include <iostream>
#include <algorithm>
#include "sieve.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long bound;
    int n;
    cin >> bound >> n;
    vector<long long> query(n);
    for(int i = 0; i < n; i++)
        cin >> query[i];

    /// Counting minimal number of necessary primes.
    auto primesVec = primes(*max_element(query.begin(), query.end()));

    /// Binary searching primes smaller than query.
    for (auto &q : query)
        cout << upper_bound(primesVec.begin(), primesVec.end(), q) - primesVec.begin()  << "\n";

    return 0;
}