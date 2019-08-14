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
using namespace std;

//https://open.kattis.com/problems/inversefactorial

//If n >= 10 then (n+1)! will contain more digits than n!, and every n! will contain an unique amount of digits.
//This means that you don't have to store the whole number, you just need to store the length of the number and compare it to the given number

//Start with when n <= 10, start looping i from 1 to 10 and check if n = i!
//If n > 10, then loop i from 1 to infinity and store i! in scientific notation (A*10^B)
//If i! is stored in two variables resA and resB, i is stored is iA and iB
//Then the result of (i+1)! will be, resA = resA*iA and resB = resB + iB.
//Break the loop when the length of the result is the same as the length of the given string (resB+1 == string.length())

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string num;
    cin >> num;
    if (num.length() <= 7) {
        long long numInt = atoi(num.c_str());
        long long currNum = 1;
        for (int i = 1; i <= 10; i++) {
            currNum *= i;
            if (currNum == numInt) {
                cout << i;
                return 0;
            }
        }
    }

    int lengthNum = 0, currLength = 0;
    long double shortNum = 1;
    for (int i = 1; i < 300000; i++) {
        if (i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000) {
            currLength++;
        }
        long double iShortNum = (long double)i / pow(10, currLength);
        lengthNum += currLength;

        shortNum *= iShortNum;
        if (shortNum >= 10) {
            shortNum /= 10;
            lengthNum++;
        }
        if (lengthNum + 1 == num.length()) {
            cout << i;
            return 0;
        }
        
    }

    return 0;
}
