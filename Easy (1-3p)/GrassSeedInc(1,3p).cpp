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

//https://open.kattis.com/problems/grassseed

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    double cost, antalLand;
    cin >> cost >> antalLand;
    double totalArea = 0;
    for (int i = 0; i < antalLand; i++) {
        double width, height;
        cin >> width >> height;
        totalArea += width * height;
    }
    cout << setprecision(10) << totalArea * cost;
    return 0;
}
