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

//https://open.kattis.com/problems/helpaphd

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        string input;
        cin >> input;
        if (input[0] == 'P') {
            cout << "skipped" << endl;
            continue;
        }
        int tal1 = 0;
        int index;
        for (int i = 0; true; i++) {
            if (input[i] == '+') {
                index = i + 1;
                break;
            }
            tal1 *= 10;
            tal1 += input[i]-48;
        }

        int tal2 = 0;
        for (int i = index; i < input.length(); i++) {
            tal2 *= 10;
            tal2 += input[i] - 48;
        }
        cout << tal1 + tal2 << endl;
    }
    return 0;
}
