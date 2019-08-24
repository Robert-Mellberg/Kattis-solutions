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

//https://open.kattis.com/problems/areal

int main()
{
    long long area;
    cin >> area;
    setprecision(15);
    printf("%.9f", sqrt(area) * 4);
    return 0;
