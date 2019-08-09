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

//https://open.kattis.com/problems/ones

//Use trial and error. Start with 1, then 11, 111, 1111... etc.
//Since we can only store values to a certain size, only store the rest; difference = 11111...1 % number

//This works since (11111...1)*10+1 % number = ((11111...1-difference)+difference)*10+1 % number = difference*10+1 etc.
//Thus if difference*10+1 = 0 then (11111...1)*10+1 % number = 0

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long num;
    while (cin >> num) {
        long long difference = 1;
        int count = 1;
        while (true) {
            difference %= num;
            if (difference == 0) {
                break;
            }
            count++;
            difference = (difference * 10) + 1;
        }
        cout << count << "\n";
    }

    return 0;
}
