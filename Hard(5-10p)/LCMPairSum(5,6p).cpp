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

//https://open.kattis.com/problems/lcmpairsum

long long modulo1000000007 = 1000000007;
long long modPow(long long base, int exponent, long long mod) {

    long long results = 1;
    while (exponent > 0) {
        //exponent ojämn, dra ut en faktor
        if (exponent % 2 == 1) {
            results = (results*base)%mod;
        }

        exponent /= 2;
        base = (base*base) % mod;
    }

    return results;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;

    for (int i = 1; i <= cases; i++) {

        int antalPrimTal;
        cin >> antalPrimTal;

        vector<pair<int, int>> primePower;
        for (int l = 0; l < antalPrimTal; l++) {
            int primTal, power;
            cin >> primTal >> power;
            primePower.push_back(pair<int, int>(primTal, power));
        }

        vector<long long> factors;
        long long compositeNumber = 1;
        for (auto par : primePower) {
            compositeNumber = (compositeNumber* modPow(par.first, par.second, modulo1000000007))%modulo1000000007;

            long long factor = 0;
            factor += ((par.second + 1)*modPow(par.first, par.second, modulo1000000007));
            for (int power = par.second - 1; power >= 0; power--) {
                factor += modPow(par.first, power, modulo1000000007);
            }
            factor %= modulo1000000007;
            factors.push_back(factor);
        }

        long long term = 1;
        for (long long factor : factors) {
            term = (term*factor) % modulo1000000007;
        }

        cout << "Case " << i << ": " << (term + compositeNumber) % modulo1000000007 << endl;

    }
    
    return 0;
}
