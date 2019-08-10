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
using namespace std;

//https://open.kattis.com/problems/collatz



int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    

    long long num1, num2;
    while (cin >> num1 >> num2 && num1 && num2) {
        long long amountOfSteps1 = 0, amountOfSteps2 = 0, endNumber1, endNumber2;
        unordered_map<long long, long long> sequenceNum1;

        long long num1Iter = num1;
        sequenceNum1[num1Iter] = amountOfSteps1;
        while (num1Iter != 1) {
            amountOfSteps1++;
            if (num1Iter % 2 == 0) {
                num1Iter /= 2;
            }
            else {
                num1Iter = num1Iter * 3 + 1;
            }
            sequenceNum1[num1Iter] = amountOfSteps1;
        }

        long long num2Iter = num2;
        while (true) {
            if (sequenceNum1.find(num2Iter) != sequenceNum1.end()) {
                long long countNum1 = sequenceNum1[num2Iter];
                long long countNum2 = amountOfSteps2;
                cout << num1 << " needs " << countNum1 << " steps, ";
                cout << num2 << " needs " << countNum2 << " steps, ";
                cout << "they meet at " << num2Iter << "\n";
                break;
            }

            if (num2Iter % 2 == 0) {
                num2Iter /= 2;
            }
            else {
                num2Iter = num2Iter * 3 + 1;
            }
            amountOfSteps2++;
        }
    }
    return 0;
}
