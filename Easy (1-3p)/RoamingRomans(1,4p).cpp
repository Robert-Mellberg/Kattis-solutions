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

//https://open.kattis.com/problems/romans

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    double num;
    cin >> num;
    cout << (int)((1000 * num * 5280 / 4854)+0.5);
    return 0;
}
