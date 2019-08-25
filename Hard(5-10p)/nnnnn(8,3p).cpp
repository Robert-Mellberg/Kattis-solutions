#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
using namespace std;

//https://open.kattis.com/problems/nnnnn

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    if (input[0] == '0') {
        cout << "0";
        return 0;
    }
    long long avrundning = 0;
    for (int i = 0; i < 15; i++) {
        if (i < input.length()) {
            avrundning = avrundning * 10 + input[i] - '0';
        }
        else {
            avrundning = avrundning * 10;
        }
    }

    //log(x) + x = log(a)+input.length()-14
    double lower = 0, higher = 1000000, middle;
    double yLed = log10(avrundning) + input.length() - 14;

    while (abs(lower - higher) > 1) {
        middle = (lower + higher) / 2;
        double answer = log10(middle) + middle;
        if (answer < yLed) {
            lower = middle;
        }
        else {
            higher = middle;
        }
    }
    int divider;
    if (log10(ceil(lower)) + ceil(lower) <= yLed) {
        divider = ceil(lower);
    }
    else {
        divider = floor(lower);
    }

    int remainder = 0;
    string nySiffra = "";
    int index = 0;
    while (true) {
        remainder = remainder * 10 + input[index] - '0';
        if (remainder / divider != 0) {
            nySiffra += (char)((remainder / divider) + 48);
            remainder %= divider;
            index++;
            break;
        }
        index++;
    }

    while (index < input.length()) {
        remainder = remainder * 10 + input[index] - '0';
        nySiffra += (char)(remainder / divider + 48);
        remainder %= divider;
        index++;
    }
    cout << nySiffra;
    return 0;
}
