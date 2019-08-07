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
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/primes

//Use the fact that every number can only be prime factorized in one unique way.
//Thus every number with the given primes as factors can be computed by prime1^n1*prime2^n2*...*primek^nk
//Where n1,n2...nk varies between 0 and infinity
//We only have to compute all n1,n2...nk such that prime1^n1*prime2^n2*...*primek^nk is less than the given upper bound.

//We can do this recursively by first looping through n1 from 0 to infinity and then calling the method (calcComp) recursively,
//in the next level the method will loop through n2 from 0 to infinity, and then call recursively and loop through n3 etc.
//When ni reaches such a value that prime1^n1*prime2^n2*...*primek^nk > upper, then the method can return and doesn't have to continue recursively


void calcComp(vector<long long> &allComposites, vector<long long> primes, int index, long long result, long long lower, long long upper) {
    if (index == primes.size()) {
        return;
    }
    calcComp(allComposites, primes, index + 1, result, lower, upper);
    while (true) {
        result *= primes[index];
        if (result >= lower && result <= upper) {
            allComposites.push_back(result);
        }
        if (result > upper) {
            return;
        }
        calcComp(allComposites, primes, index + 1, result, lower, upper);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int antalPrimes;
    while (cin >> antalPrimes && antalPrimes) {
        vector<long long> primes;
        for (int i = 0; i < antalPrimes; i++) {
            long long prime;
            cin >> prime;
            primes.push_back(prime);
        }
        long long lower, upper;
        cin >> lower >> upper;
        vector<long long> allComposites;
        if (lower == 1) {
            allComposites.push_back(1);
        }
        calcComp(allComposites, primes, 0, 1, lower, upper);
        sort(allComposites.begin(), allComposites.end());
        if (allComposites.size() == 0) {
            cout << "none\n";
            continue;
        }
        cout << allComposites[0];
        for (int i = 1; i < allComposites.size(); i++) {
            cout << "," << allComposites[i];
        }
        cout << "\n";
    }

    return 0;
}
