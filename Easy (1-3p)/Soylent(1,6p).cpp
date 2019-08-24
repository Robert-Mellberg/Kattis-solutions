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

//https://open.kattis.com/problems/soylent

int main()
{
    double cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        double calories;
        cin >> calories;
        cout << ceil(calories / 400) << endl;
    }
    return 0;
}
