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

//https://open.kattis.com/problems/pizza2

int main()
{
    double radius, crust;
    cin >> radius >> crust;
    printf("%.10f", pow((radius-crust)/radius, 2)*100);
    return 0;
}
