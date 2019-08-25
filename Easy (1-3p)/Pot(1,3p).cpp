#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/pot

int main()
{
    int antalCases;
    cin >> antalCases;
    int total = 0;
    for (int i = 0; i < antalCases; i++) {
        int read;
        cin >> read;
        total += pow((int)(read/10), read%10);
    }
    cout << total;
    return 0;
}
