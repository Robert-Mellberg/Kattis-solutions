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

//https://open.kattis.com/problems/lineup

int main()
{
    vector<string> names;
    int antal;
    cin >> antal;
    for (int i = 0; i < antal; i++) {
        string namn;
        cin >> namn;
        names.push_back(namn);
    }
    bool increasing = true, decreasing = true;
    for (int i = 1; i < names.size(); i++) {
        if (names[i - 1].compare(names[i]) > 0) {
            increasing = false;
        }
        else if(names[i - 1].compare(names[i]) < 0){
            decreasing = false;
        }
    }
    if (increasing) {
        cout << "INCREASING";
    }
    else if (decreasing) {
        cout << "DECREASING";
    }
    else
    {
        cout << "NEITHER";
    }
    return 0;
}
