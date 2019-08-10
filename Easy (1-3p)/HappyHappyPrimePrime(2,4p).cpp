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

//https://open.kattis.com/problems/happyprime

int squareSum(int num) {
    int sum = 0;
    for (int div = 1; div < 10000; div *= 10) {
        sum += pow((num % (div * 10)) / div, 2);
    }
    return sum;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<bool> happy(350, 0);
    happy[1] = true;
    for (int rep = 0; rep < 350; rep++) {
        for (int i = 2; i < 350; i++) {
            if (happy[squareSum(i)]) {
                happy[i] = 1;
            }
        }
    }

    vector<bool> sieve(10001, 1);
    sieve[1] = false;

    for (int i = 2; i <= 10000; i++) {
        if (sieve[i]) {
            for (int j = 2 * i; j <= 10000; j += i) {
                sieve[j] = false;
            }
        }
    }

    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        int num;
        cin >> num >> num;
        cout << i << " " << num << " ";
        int squarNum = squareSum(num);
        if (sieve[num] && happy[squarNum]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    
    
    return 0;
}
