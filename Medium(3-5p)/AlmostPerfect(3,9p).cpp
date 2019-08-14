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



long long getGeometricalSum(long long prime, long long maxExponent) {
    return (pow(prime, maxExponent + 1)-1)/(prime-1);
}

long long mod1000000007 = 1000000007;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long num;
    while (cin >> num) {
        unordered_map<int, int> primeFactorsCount;
        long long numCopy = num;

        for (int j = 2; j < 50000; j++) {
            if (num % j == 0) {
                primeFactorsCount[j]++;
                num /= j;
                while (num % j == 0) {
                    primeFactorsCount[j]++;
                    num /= j;
                }
                if (j > num) {
                    break;
                }
            }
        }
        if (num != 1) {
            primeFactorsCount[num]++;
        }
        long long sumDivisors = 1;
        for (auto p : primeFactorsCount) {
            sumDivisors *= getGeometricalSum(p.first, p.second);
        }
        sumDivisors -= numCopy;

        cout << numCopy << " ";
        if (sumDivisors == numCopy) {
            cout << "perfect";
        }
        else if (abs(sumDivisors - numCopy) <= 2) {
            cout << "almost perfect";
        }
        else {
            cout << "not perfect";
        }
        cout << "\n";
    }
}
