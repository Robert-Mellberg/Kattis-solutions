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
using namespace std;

//https://open.kattis.com/problems/sequences

struct questionMark {
    unsigned long long antalEttorLeft = 0;
    unsigned long long antalNollorLeft = 0;
};

long long modPow(unsigned long long base, unsigned long long exponent, unsigned long long mod) {
    unsigned long long result = 1;
    while (exponent != 0) {

        if (exponent & 1) {
            result = (result*base)%mod;
        }

        exponent /= 2;
        base = (base*base) % mod;
    }

    return result;
}

long long mod1000000007 = 1000000007;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    unsigned long long antalEttor = 0, antalNollor = 0;
    string input;
    cin >> input;

    vector<questionMark> questionMarks;
    unsigned long long inversionsKnown = 0;
    for (char c : input) {
        switch(c) {
        case '0':
            antalNollor++;
            inversionsKnown += antalEttor;
            break;
        case '1':
            antalEttor++;
            break;
        case '?':
            questionMarks.push_back({antalEttor, antalNollor});
            break;
        }
    }
    unsigned long long k = questionMarks.size();
    inversionsKnown %= mod1000000007;

    long long total = (modPow(2, k, mod1000000007)*inversionsKnown)%mod1000000007;
    unsigned long long DifSeqForKnown = modPow(2, k-1, mod1000000007);

    //+ amount of tranversions for q if q is 0 and tranversions for known 0 if q is 1 
    for (questionMark q : questionMarks) {
        unsigned long long antalNollRight = antalNollor - q.antalNollorLeft;
        total += DifSeqForKnown * (antalNollRight + q.antalEttorLeft);
        total %= mod1000000007;
    }
    total %= mod1000000007;
    unsigned long long sumQRgith = ((k*k-k)/2) % mod1000000007;
    sumQRgith = (sumQRgith * modPow(2, k - 1, mod1000000007))%mod1000000007;
    total += sumQRgith;
    unsigned long long doubleCount = 0, multiplier = k-1, divider = 2, nChooseXVal = k;
    for (int antalQ = 2; antalQ <= k; antalQ++) {
        doubleCount += antalQ - 1;
        doubleCount %= mod1000000007;
        nChooseXVal = (nChooseXVal*multiplier) % mod1000000007;
        nChooseXVal = (nChooseXVal * modPow(divider, 1000000005, mod1000000007))%mod1000000007;
        total = (total - (long long)(doubleCount * nChooseXVal))%mod1000000007;
        divider++;
        multiplier--;
    }
    if (total < 0) {
        total += mod1000000007;
    }
    cout << total << endl;
    return 0;
}
