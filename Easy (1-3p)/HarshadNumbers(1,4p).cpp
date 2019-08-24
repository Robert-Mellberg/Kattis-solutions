#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/harshadnumbers

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    
    while (true) {
        int sum = (num % 10000000000) / 1000000000 +  (num % 1000000000) / 100000000 + (num % 100000000) / 10000000 + (num % 10000000) / 1000000 + (num % 1000000) / 100000 + (num % 100000) / 10000 + (num % 10000) / 1000 + (num % 1000) / 100 + (num % 100) / 10 + (num % 10);
        if (num%sum == 0) {
            break;
        }
        num++;
    }
    cout << num;
    return 0;
}
