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

//https://open.kattis.com/problems/different

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long num1, num2;

    while (cin >> num1 >> num2) {
        long long difference = num1 - num2;
        if (difference < 0) {
            difference *= -1;
        }
        cout << difference << endl;
    }
    return 0;
}
