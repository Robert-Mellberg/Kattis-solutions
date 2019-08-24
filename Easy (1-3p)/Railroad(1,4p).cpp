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

//https://open.kattis.com/problems/railroad2



int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    
    int antalSwitch;
    cin >> antalSwitch >> antalSwitch;
    if (antalSwitch % 2 == 0) {
        cout << "possible";
    }
    else {
        cout << "impossible";
    }
    return 0;
}
