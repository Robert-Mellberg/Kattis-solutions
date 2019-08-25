#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
#include <algorithm>
#include <sstream>
using namespace std;

//https://open.kattis.com/problems/simpleaddition

int main()
{
    
    string a, b;
    vector<char> nyTal;
    cin >> a >> b;
    int rest = 0;
    for (int i = 0; i < max(a.length(), b.length()); i++) {
        int aIndex = a.length() - 1 - i;
        int bIndex = b.length() - 1 - i;
        int summa = 0;
        if (aIndex >= 0) {
            summa += (int)a[aIndex]-48;
        }
        if (bIndex >= 0) {
            summa += (int)b[bIndex]-48;
        }
        summa += rest;
        nyTal.push_back((char)((summa%10)+48));
        rest = summa / 10;
    }
    if (rest == 1) {
        nyTal.push_back('1');
    }
    for (int k = nyTal.size() - 1; k >= 0; k--) {
        cout << nyTal[k];
    }
    return 0;
}
