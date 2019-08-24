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

//https://open.kattis.com/problems/herman


int main()
{
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);
    double num;
    cin >> num;
    printf("%.16f", num*num*3.14159265358979323846264338327950288419);
    printf("\n");
    printf("%.16f", num * num * 2);
    return 0;
}
