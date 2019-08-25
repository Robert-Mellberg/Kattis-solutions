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

//https://open.kattis.com/problems/fishmongers

int main()
{
    map<int, int> prisPerKG;
    multiset<int> viktFiskar;
    int antalFisk, antalFiskKopare;
    cin >> antalFisk >> antalFiskKopare;
    for (int i = 0; i < antalFisk; i++) {
        int viktFisk;
        cin >> viktFisk;
        viktFiskar.insert(-viktFisk);
    }

    for (int j = 0; j < antalFiskKopare; j++) {
        int antalFiskKopa;
        int pris;
        cin >> antalFiskKopa >> pris;
        prisPerKG[pris] += antalFiskKopa;
    }
    long long total = 0;
    for (int fisk : viktFiskar) {
        if (prisPerKG.size() == 0) {
            break;
        }
        auto lastElement = prisPerKG.rbegin();
        total += (long long)(-fisk)*lastElement->first;
        lastElement->second--;
        if (lastElement->second == 0) {
            prisPerKG.erase(lastElement->first);
        }
    }
    cout << total;
    return 0;
}
