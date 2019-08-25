#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
#include <random>
using namespace std;

//https://open.kattis.com/problems/sumsquareddigits

int main()
{
    int antalCases;
    cin >> antalCases;
    for (int i = 1; i <= antalCases; i++) {
        int total = 0;
        int bas, tal;
        cin >> bas >> bas >> tal;
        int c, d;
        c = tal;
        while (true) {
            d = c / bas;
            total += pow(c%bas, 2);
            if (d == 0) {
                break;
            }
            c = d;
        }
        cout << i << " " << total << endl;
    }
}
