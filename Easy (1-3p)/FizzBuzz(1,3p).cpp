#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/fizzbuzz

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int divid1, divid2, limit;
    cin >> divid1 >> divid2 >> limit;

    for (int i = 1; i <= limit; i++) {
        if (i%divid1 == 0) {
            if (i%divid2 == 0) {
                cout << "FizzBuzz" << endl;
            }
            else {
                cout << "Fizz" << endl;
            }
        }
        else if (i%divid2 == 0) {
            cout << "Buzz" << endl;
        }
        else {
            cout << i << endl;
        }
    }
    
    return 0;
}
