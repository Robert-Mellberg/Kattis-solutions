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

//https://open.kattis.com/problems/trik

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    
    vector<int> ballPos = { 1, 0, 0 };
    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        int temp;
        switch (c)
        {
        case 'A':
            temp = ballPos[0];
            ballPos[0] = ballPos[1];
            ballPos[1] = temp;
            break;
        case 'B':
            temp = ballPos[1];
            ballPos[1] = ballPos[2];
            ballPos[2] = temp;
            break;
        case 'C':
            temp = ballPos[0];
            ballPos[0] = ballPos[2];
            ballPos[2] = temp;
            break;
        }
    }
    for (int l = 0; l < ballPos.size(); l++) {
        if (ballPos[l]) {
            cout << l + 1;
        }
    }
    return 0;
}
