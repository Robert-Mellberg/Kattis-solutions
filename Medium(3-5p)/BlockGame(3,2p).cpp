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

//https://open.kattis.com/problems/blockgame2


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long torn1, torn2;
    cin >> torn1 >> torn2;
    if (torn1 == torn2) {
        cout << "win";
        return 0;
    }
    long long maxTorn = max(torn1, torn2);
    long long minTorn = min(torn1, torn2);
    int runda = 0;
    while (true) {
        if (maxTorn >= minTorn * 2) {
            if (runda % 2 == 0) {
                cout << "win";
            }
            else {
                cout << "lose";
            }
            return 0;
        }
        maxTorn -= minTorn;

        long long temp = maxTorn;
        maxTorn = minTorn;
        minTorn = temp;
        runda++;
    }
    return 0;
}
