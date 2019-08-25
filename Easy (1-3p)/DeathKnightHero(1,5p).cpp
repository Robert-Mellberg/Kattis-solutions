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

//https://open.kattis.com/problems/deathknight

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases;
    cin >> cases;
    int count = 0;
    for (int k = 0; k < cases; k++) {
        string input;
        cin >> input;
        bool won = true;
        for (int i = 0; i < input.length() - 1; i++) {
            if (input[i] == 'C' && input[i + 1] == 'D') {
                won = false;
            }
        }
        if (won) {
            count++;
        }
    }
    cout << count;
    return 0;
}
