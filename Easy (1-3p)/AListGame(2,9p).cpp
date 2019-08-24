#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/listgame#

vector<int> primes;

void getPrimes() {
    vector<bool> sieve(50000, true);

    for (int i = 2; i < sieve.size(); i++) {
        if (sieve[i]) {
            primes.push_back(i);
            for (int p = i+i; p < sieve.size(); p += i) {
                sieve[p] = false;
            }
        }
    }
}

bool isPrimes(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num%i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    getPrimes();

    int num, count = 0;
    cin >> num;
    while (true) {
        for (int prime : primes) {
            if (isPrimes(num)) {
                count++;
                cout << count;
                return 0;
            }
            if (num%prime == 0) {
                count++;
                num /= prime;
            }
        }
    }

    return 0;
}
