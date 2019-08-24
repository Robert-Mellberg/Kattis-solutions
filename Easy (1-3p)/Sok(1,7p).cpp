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

//https://open.kattis.com/problems/sok

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    double juice1, juice2, juice3, raio1, ratio2, ratio3;
    cin >> juice1 >> juice2 >> juice3 >> raio1 >> ratio2 >> ratio3;
    double maxx = 1000;
    if (juice1 / raio1 < maxx) {
        maxx = juice1 / raio1;
    }
    if (juice2 / ratio2 < maxx) {
        maxx = juice2 / ratio2;

    }
    if (juice3 / ratio3 < maxx) {
        maxx = juice3 / ratio3;
    }
    printf("%.10f", juice1-raio1*maxx);
    printf(" ");
    printf("%.10f", juice2 - ratio2 * maxx);
    printf(" ");
    printf("%.10f", juice3 - ratio3 * maxx);
    return 0;
}
