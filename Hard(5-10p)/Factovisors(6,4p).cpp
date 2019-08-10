#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

//https://open.kattis.com/problems/factovisors

//You can solve the problem by prime factorizing both numbers
//For the denominator to divide the numerator the following criterion must be met:
//Every factor in the primefactorization of the denominator must also be a factor of the numerator.

//Start by generating all primes under (2^31)^(1/2) < 2^16 = 65536 with the help of a sieve and store in a vector
//Factorize the denominator by trying to divide with all the primes and store the amount of times each prime divided the denominator in a map or vector.
//Loop through every prime in that vector or map, check so that the numerator contains as many or more of that prime as factors.
//(Or equivalently, the numerator can be divided by each of those primes as many or more times than the denominator)
//If that condition is met for every prime, then the numerator is divisble by the denominator.

//The highest number of K of a specific prime P such that P^K is a factor of N can be calculated by 
//K = ⌊N/P⌋+⌊N/P^2⌋+⌊N/P^3⌋+...⌊N/P^∞⌋, which is calculated in getNumOfPrimesFact().


long long getNumOfPrimesFact(long long num, long long prime) {
    long long total = 0;
    long long div = prime;
    while (num >= div) {
        total += num / div;
        div *= prime;
    }

    return total;
}


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    vector<long long> primes;
    vector<bool> sieve(65537, 1);

    for (int i = 2; i <= 65536; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= 65536; j += i) {
                sieve[j] = 0;
            }
        }
    }

    long long num, numFac;
    while (cin >> numFac >> num) {
        if (num == 0) {
            cout << num << " does not divide " << numFac << "!\n";
            continue;
        }
        unordered_map<long long, int> count;
        long long numCopy = num;
        for (long long prime : primes) {
            while (num % prime == 0) {
                count[prime]++;
                num /= prime;
            }
            if (prime > num) {
                break;
            }
        }

        if (num != 1) {
            count[num]++;
        }
        bool works = true;
        for (auto prime : count) {
            if (prime.second > getNumOfPrimesFact(numFac, prime.first)) {
                works = false;
            }
        }
        cout << numCopy << " ";
        if (works) {
            cout << "divides ";
        }
        else {
            cout << "does not divide ";
        }
        cout << numFac << "!\n";
    }


    
    return 0;
}
