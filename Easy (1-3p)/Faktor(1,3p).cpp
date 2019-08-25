#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/faktor

int main()
{
    int a, i;
    cin >> a >> i;
    int bribe = 0;
    while (true) {
        if (((double)bribe / a) > i - 1) {
            cout << bribe;
            return 0;
        }
        bribe++;
    }

    return 0;
}
