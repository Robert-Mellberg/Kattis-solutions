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

//Has to be solved in a fast language because of the time limit

//Can be solved using a prime sieve
//A prime sieve is a vector of size N which keeps track of which numbers < N that are primes and which are composite.
//Start by making a vector V of size N filled with true booleans.
//Iterate V from index 2 to sqrt(N), if V is true at index I, then I is a prime
//Mark all multiples of I as composite (V(I*2) = false, V(I*3) = false, ... , V(I*⌊(N-1)/I⌋))
//You only have to iterate to sqrt(N) because if I > sqrt(N) then ⌊(N-1)/I⌋ is < sqrt(N)
//and the multiples of integers < sqrt(N) are already marked as composites.


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n, q;
    cin >> n >> q;

    vector<bool> sieve(n+1, 1);
    sieve[1] = false;
    int sqrtNum = sqrt(n);

    int primeCount = 0;
    for (int i = 2; i <= sqrtNum; i++) {
        if (sieve[i]) {
            primeCount++;
            for (int j = 2 * i; j <= n; j+=i) {
                sieve[j] = false;
            }
        }
    }

    for (int i = sqrtNum + 1; i <= n; i++) {
        if (sieve[i]) {
            primeCount++;
        }
    }

    cout << primeCount << "\n";
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        cout << sieve[num] << "\n";
    }

    return 0;
}
