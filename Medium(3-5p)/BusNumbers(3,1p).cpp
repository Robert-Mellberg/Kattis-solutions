#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

//https://open.kattis.com/problems/busnumbers2


vector<vector<int>> map;
int sokTyp;

int main()
{
    int maxTal;
    cin >> maxTal;
    set<int> bussNummerFirst;
    vector<int> bussNummerSecond;

    int rotenUr = floor(cbrt(maxTal));
    
    for (int outer = 0; outer <= rotenUr; outer++) {
        for (int inner = outer; inner <= rotenUr; inner++) {
            int nummer = outer * outer * outer + inner * inner * inner;
            if (nummer > maxTal) {
                continue;
            }
            //finns i lista
            if (bussNummerFirst.find(nummer) != bussNummerFirst.end()) {
                bussNummerSecond.push_back(nummer);
            }
            else {
                bussNummerFirst.insert(nummer);
            }
        }
    }
    if (bussNummerSecond.size() != 0) {
        sort(bussNummerSecond.begin(), bussNummerSecond.end());
        cout << bussNummerSecond[bussNummerSecond.size()-1];
    }
    else
    {
        cout << "none";
    }

    return 0;
}
