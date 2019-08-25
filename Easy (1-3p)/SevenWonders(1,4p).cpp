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

//https://open.kattis.com/problems/sevenwonders

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    
    int antalT = 0, antalC = 0, antalG = 0;
    for (int i = 0; i < input.size(); i++) {
        switch (input[i])
        {
        case 'T':
            antalT++;
            break;
        case 'C':
            antalC++;
            break;
        case 'G':
            antalG++;
            break;
        }
    }
    
    cout << pow(antalT, 2) + pow(antalG, 2) + pow(antalC, 2) + min(min(antalC, antalT), antalG)*7;
    return 0;
}
