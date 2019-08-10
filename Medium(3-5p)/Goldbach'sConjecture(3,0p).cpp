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


https://open.kattis.com/problems/goldbach2


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int cases;
    cin >> cases;
    vector<bool> sieve(32001, 1);
    sieve[0] = 0;
    sieve[1] = 0;
    for (int i = 2; i <= sqrt(32001); i++) {
        if (sieve[i]) {
            for (int j = 2 * i; j < 32001; j += i) {
                sieve[j] = 0;
            }
        }
    }



    for (int i = 0; i < cases; i++) {
        int num;
        cin >> num;
        vector<string> representations;

        int lower = 0, higher = num;
        while (lower <= higher) {
            if (sieve[lower] && sieve[higher]) {
                string rep = std::to_string(lower) + "+" + std::to_string(higher);
                representations.push_back(rep);
            }
            lower++;
            higher--;
        }

        cout << num << " has " << representations.size() << " representation(s)\n";
        for (string rep : representations) {
            cout << rep << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}
