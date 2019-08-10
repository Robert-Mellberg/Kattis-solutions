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

//https://open.kattis.com/problems/digitsum

//The solution to this problem split up the problem in several parts as follows;
//eg. If you want to count the digitsum of the interval [0, 9468], then count (9460, 9468]+(9400, 9460]+(9000, 9400]+[0,9400]

//If you want to calculate (abcd*10^(k+1), abcde*10^k], k >= 0, where a,b,c,d,e are digits;
//Then there are e*10^k numbers in (abcd*10^(k+1), abcde*10^k], e*10^k (all of those numbers) will contain abcd,
//10^k of those numbers will contain 0, 10^k will contain 1, 10^k will contain 2 ... 10^k will contain e-1
//(10^k*e/10) of those numbers will contain 0 as last digit, (10^k*e/10) will contain 1 as last digit ... (10^k*e/10) will contain 9 as last digit
//(10^k*e/10) of those numbers will contain 0 as second last digit, (10^k*e/10) will contain 1 as second last digit ... (10^k*e/10) will contain 9 as second last digit
.
.
.
//(10^k*e/10) of those numbers will contain 0 as k last digit, (10^k*e/10) will contain 1 as second last digit ... (10^k*e/10) will contain 9 as second last digit

//If you sum all those together you will get the answer = (10^k*e/10)*K*(1+2+3+4+5+6+7+8+9)+10^k*(1+2+3+...+e)+(10^k*e)*(a+b+c+d)


//The example [0, 9468] is calculated as;
//(9460, 9468] = (1*8/10)*0*45+1*28+1*8*(9+4+6)
//(9400, 9460] = (10*6/10)*1*45+10*15+10*6*(9+4)
//(9000, 9400] = (100*4/10)*2*45+100*6+100*4*(9)
//(0, 9000] = (1000*9/10)*3*45+1000*36+1000*9*(0)

//To calculate the digit sum of [a, b], calculate [0, b]-[0, a]+digit sum of a

long long TenPow(long long expo) {
    long long base = 10;
    long long result = 1;

    while (expo != 0) {
        if (expo & 1) {
            result *= base;
        }
        expo /= 2;
        base *= base;
    }
    return result;
}

long long getDigit(long long num, long long ind) {
    long long dig = (num % TenPow(ind + 1))/TenPow(ind);
    return dig;
}

long long digitSum(long long num) {
    vector<long long> summor = { 0,0,1,3,6, 10, 15, 21, 28, 36 };
    long long sum0to10 = 45;

    long long total = 0;
    for (int i = 0; i <= 16; i++) {
        long long antal = TenPow(i)*getDigit(num, i);
        total += (antal/10) * i*sum0to10;
        total += TenPow(i) *summor[getDigit(num, i)];

        long long sumDigitsOver = 0;
        for (int j = i + 1; j <= 16; j++) {
            sumDigitsOver += getDigit(num, j);
        }

        total += antal * sumDigitsOver;
        num -= antal;
        //cout << total << "\n";
    }

    return total;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        long long num1, num2;
        cin >> num1 >> num2;

        long long countNum1 = digitSum(num1), countNum2 = digitSum(num2);
        long long diff = countNum2 - countNum1;
        for (int l = 0; l <= 16; l++) {
            diff += getDigit(num2, l);
        }
        cout << diff << "\n";
    }
    
    return 0;
}
