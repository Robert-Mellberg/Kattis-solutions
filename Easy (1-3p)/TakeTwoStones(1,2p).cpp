#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/twostones

int main()
{
    int a;
    cin >> a;
    if (a % 2 == 0) {
        cout << "Bob";
    }
    else {
        cout << "Alice";
    }
    return 0;
}
