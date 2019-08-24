#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/blackfriday


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int antal;
    cin >> antal;

    map<int, int> numberToPerson;
    set<int> disqualified;
    for (int i = 1; i <= antal; i++) {
        int read;
        cin >> read;
        read *= -1;
        if (numberToPerson.find(read) != numberToPerson.end()) {
            disqualified.insert(read);
        }
        numberToPerson[read] = i;
    }
    for (auto i : numberToPerson) {
        if (disqualified.find(i.first) != disqualified.end()) {
            continue;
        }
        cout << i.second;
        return 0;
    }
    cout << "none";
    return 0;
}
