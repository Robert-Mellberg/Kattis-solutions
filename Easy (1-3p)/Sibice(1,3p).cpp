#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <random>
using namespace std;

//https://open.kattis.com/problems/sibice

int main()
{
    int antalCases;
    cin >> antalCases;
    int a, b;
    cin >> a >> b;
    int maxLength = sqrt(pow(a, 2) + pow(b, 2));
    for (int i = 0; i < antalCases; i++) {
        int read;
        cin >> read;
        if (read <= maxLength) {
            cout << "DA" << endl;
        }
        else {
            cout << "NE" << endl;
        }
    }
    return 0;
}
