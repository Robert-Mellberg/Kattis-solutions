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

//https://open.kattis.com/problems/runlengthencodingrun

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    char type;
    cin >> type;
    if (type == 'D') {
        char c;
        int lengthC;
        while (cin >> c >> lengthC) {
            for (int i = 0; i < lengthC; i++) {
                cout << c;
            }
        }
    }
    else {
        string message;
        cin >> message;
        int count = 1;
        char lastChar = message[0];
        for (int i = 1; i < message.size(); i++) {
            char c = message[i];
            if (c == lastChar) {
                count++;
            }
            else {
                cout << lastChar << count;
                count = 1;
                lastChar = c;
            }
        }
        cout << lastChar << count;
    }
    return 0;
}
