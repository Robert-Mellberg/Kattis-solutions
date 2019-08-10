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

//https://open.kattis.com/problems/judging



int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int cases;
    cin >> cases;



    unordered_map<string, int> count1;
    for (int i = 0; i < cases; i++) {
        string res;
        cin >> res;
        count1[res]++;
    }

    unordered_map<string, int> count2;
    for (int i = 0; i < cases; i++) {
        string res;
        cin >> res;
        count2[res]++;
    }

    int total = 0;
    for (auto i : count1) {
        int sec = count2[i.first];
        total += min(sec, i.second);
    }
    cout << total;

    
    return 0;
}
