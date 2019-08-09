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
#include <queue>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/thinkingofanumber

//The method uses euclidean algorithm to find the greatest common denominator
int getCommonDenominator(int a, int b) {

    while (true) {
        int temp1 = a % b;
        a = b;
        b = temp1;
        if (b == 0) {
            return a;
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n && n) {
        int lower = 0, higher = 100000, divider = 1;
        for (int i = 0; i < n; i++) {
            string message, trash;
            int num;
            cin >> message >> trash >> num;

            if (message == "greater") {
                lower = max(num, lower);
            }
            else if (message == "less") {
                higher = min(num, higher);
            }
            else {
                divider *= num/getCommonDenominator(num, divider);
            }
        }

        if (higher == 100000) {
            cout << "infinite\n";
            continue;
        }
        int num = ((lower / divider) + 1)*divider;
        vector<int> numbers;
        while (num < higher) {
            numbers.push_back(num);
            num += divider;
        }
        if (numbers.size() == 0) {
            cout << "none\n";
            continue;
        }
        cout << numbers[0];
        for (int i = 1; i < numbers.size(); i++) {
            cout << " " << numbers[i];
        }
        cout << "\n";
    }
    



    return 0;
}
