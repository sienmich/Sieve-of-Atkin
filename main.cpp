//
// Created by sienmich on 25.10.2019.
//

#include <iostream>
#include <algorithm>
#include "sieve.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long bound;
    int n;
    cin >> bound >> n;
    vector<long long> query(n);
    for(int i = 0; i < n; i++)
        cin >> query[i];

    auto primesVec = primes(*max_element(query.begin(), query.end()));

    for (auto &q : query)
        cout << upper_bound(primesVec.begin(), primesVec.end(), q) - primesVec.begin()  << "\n";

    return 0;
}

/**
10
7
1
2
3
4
5
6
7
*/