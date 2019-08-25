#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/filip

int main()
{
    int a, b;
    cin >> a >> b;
    a = (a % 10) * 100 + ((a % 100) / 10) * 10 + (a / 100);
    b = (b % 10) * 100 + ((b % 100) / 10) * 10 + (b / 100);
    cout << max(a, b);

    return 0;
}
