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

//https://open.kattis.com/problems/primes2

long long russianPeasant(long long a, long long b, long long c) {
    long long result = 0;
    while (b) {
        if (b & 1) {
            result += a;
            result %= c;
        }
        a *= 2;
        a %= c;
        b /= 2;
    }
    return result;
}


long long modPow(long long base, long long exponent, long long mod) {
    long long result = 1;

    while (exponent) {

        if (exponent % 2 == 1) {
            result = russianPeasant(result, base, mod);
        }

        exponent /= 2;
        base = russianPeasant(base, base, mod);
    }
    return result;
}

bool isPrimeHelper(long long primeBase, long long d, long long prime) {
    long long x = modPow(primeBase, d, prime);

    if (x == 1 || x == prime - 1) {
        return true;
    }

    while (d != prime - 1) {
        x = russianPeasant(x, x, prime);
        d *= 2;

        if (x == 1) {
            return false;
        }
        else if (x == prime - 1) {
            return true;
        }
    }

    return false;
}

vector<int> testPrimes = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
bool rabinMillerIsPrime(long long num) {
    if (num == 2) {
        return true;
    }
    if (num %2 == 0 || num == 1) {
        return false;
    }

    long long d = num - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    for (int i : testPrimes) {
        if (num > i && !isPrimeHelper(i, d, num)) {
            return false;
        }
    }
    return true;
}

int minBase = 0;
vector<int> convertToDecimal(string num) {
    vector<int> convert;
    for (char c : num) {
        if ((int)c < 65) {
            convert.push_back(c - '0');
            minBase = max(minBase, c - '0');
        }
        else {
            minBase = 10;
            switch (c) {
            case 'A':
                convert.push_back(10);
                break;
            case 'B':
                convert.push_back(11);
                break;
            case 'C':
                convert.push_back(12);
                break;
            case 'D':
                convert.push_back(13);
                break;
            case 'E':
                convert.push_back(14);
                break;
            case 'F':
                convert.push_back(15);
                break;
            }
        }
    }
    return convert;
}

void printFraction(int numerator, int denominator) {
    if (numerator == 0) {
        cout << "0/1" << endl;
    }
    else if (numerator == denominator) {
        cout << "1/1" << endl;
    }
    else if (numerator == 2 && 4 == denominator) {
        cout << "1/2" << endl;
    }
    else {
        cout << numerator << "/" << denominator << endl;
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        minBase = 0;
        string num;
        cin >> num;
        vector<int> convertedToNumbers = convertToDecimal(num);
        vector<long long> convertedToDecimal;
        if (minBase < 2) {
            long long binary = 0;
            for (int i = 0; i < convertedToNumbers.size(); i++) {
                binary += pow(2, convertedToNumbers.size() - 1 - i)*convertedToNumbers[i];
            }
            convertedToDecimal.push_back(binary);
        }
        if (minBase < 8) {
            long long octal = 0;
            for (int i = 0; i < convertedToNumbers.size(); i++) {
                octal += pow(8, convertedToNumbers.size() - 1 - i)*convertedToNumbers[i];
            }
            convertedToDecimal.push_back(octal);
        }
        if (minBase < 10) {
            long long decimal = 0;
            for (int i = 0; i < convertedToNumbers.size(); i++) {
                decimal += pow(10, convertedToNumbers.size() - 1 - i)*convertedToNumbers[i];
            }
            convertedToDecimal.push_back(decimal);
        }
        long long hexadecimal = 0;
        for (int i = 0; i < convertedToNumbers.size(); i++) {
            hexadecimal += pow(16, convertedToNumbers.size() - 1 - i)*convertedToNumbers[i];
        }
        convertedToDecimal.push_back(hexadecimal);
        int count = 0;
        for (long long num : convertedToDecimal) {
            if (rabinMillerIsPrime(num)) {
                count++;
            }
        }
        printFraction(count, convertedToDecimal.size());
    }
    return 0;
}
