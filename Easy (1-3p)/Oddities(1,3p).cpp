#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/oddities

int main()
{
    int antalCases;
    cin >> antalCases;
    for (int i = 0; i < antalCases; i++) {
        int read;
        cin >> read;
        if (read % 2 == 0) {
            cout << read << " is even" << endl;
        }
        else {
            cout << read << " is odd" << endl;
        }
    }
    return 0;
}
