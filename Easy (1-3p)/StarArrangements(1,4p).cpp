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

//https://open.kattis.com/problems/stararrangements

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int number;
    cin >> number;
    cout << number << ":" << endl;
    for (int firstRow = 2; firstRow*2-1 <= number; firstRow++) {
        if (number % (firstRow * 2 - 1) == 0 || number % (firstRow * 2 - 1) == firstRow) {
            cout << firstRow << "," << firstRow - 1 << endl;
        }


        if (number%firstRow == 0) {
            cout << firstRow << "," << firstRow << endl;
        }
    }
    return 0;
}
