#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/heartrate

int main()
{
    int antalCases;
    cin >> antalCases;
    for (int i = 0; i < antalCases; i++) {
        double beats, seconds;
        cin >> beats >> seconds;
        cout << 60 / (seconds / (beats - 1)) << " " << (60 * beats) / seconds << " " << 60 / (seconds / (beats + 1)) << endl;
    }
    return 0;
}
