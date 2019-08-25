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

//https://open.kattis.com/problems/ladder

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double height, angle;
    cin >> height >> angle;
    int length = ceil(height / sin(angle*3.1415926535/180));
    cout << length;
    return 0;
}
