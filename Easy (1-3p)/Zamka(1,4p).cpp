#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <sstream>
using namespace std;

//https://open.kattis.com/problems/zamka

int main()
{
    int l, h, x;
    cin >> l >> h >> x;
    for (int i = l; i <= h; i++) {
        if (i / 10000 + (i % 10000) / 1000 + (i % 1000) / 100 + (i % 100) / 10 + i % 10 == x) {
            cout << i << endl;
            break;
        }
    }
    for (int i = h; h >= l; i--) {
        if (i / 10000 + (i % 10000) / 1000 + (i % 1000) / 100 + (i % 100) / 10 + i % 10 == x) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
