#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <sstream>
using namespace std;

//https://open.kattis.com/problems/babylonian

int main()
{
    int antalCases;
    cin >> antalCases;
    cin.ignore();
    for (int p = 0; p < antalCases; p++) {
        vector<int> siffror;
        string input;
        getline(cin, input);
        int tal = 0;
        int power = 0;
        for (int j = input.length() - 1; j >= 0; j--) {
            if (input[j] == ',') {
                siffror.push_back(tal);
                tal = 0;
                power = 0;
            }
            else {
                tal += ((int)input[j] - 48) * pow(10, power);
                power++;
            }
        }
        siffror.push_back(tal);
        long long calc = 0;
        for (int k = 0; k < siffror.size(); k++) {
            calc += pow(60, k)*siffror[k];
        }
        cout << calc << endl;
    }
    return 0;
}
