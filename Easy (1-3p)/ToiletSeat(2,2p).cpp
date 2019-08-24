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

//https://open.kattis.com/problems/toilet


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    //1
    int count = 0;
    char position = input[0];
    for (int i = 1; i < input.length(); i++) {
        if (input[i] == 'U') {
            if (position == 'D') {
                count++;
            }
        }
        else {
            if (position == 'D') {
                count++;
            }
            else {
                count += 2;
            }
        }

        position = 'U';
    }
    cout << count << endl;


    count = 0;
    position = input[0];
    for (int i = 1; i < input.length(); i++) {
        if (input[i] == 'U') {
            if (position == 'D') {
                count+= 2;
            }
            else {
                count++;
            }
        }
        else {
            if (position == 'U') {
                count++;
            }
        }

        position = 'D';
    }
    cout << count << endl;


    count = 0;
    position = input[0];
    for (int i = 1; i < input.length(); i++) {
        if (input[i] == 'U') {
            if (position == 'D') {
                count++;
            }
            position = 'U';
        }
        else {
            if (position == 'U') {
                count++;
            }
            position = 'D';
        }
    }
    cout << count;

    return 0;
}
