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

//https://open.kattis.com/problems/conundrum

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    vector<char> bokstaver = {'P', 'E', 'R'};
    int count = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != bokstaver[i % 3]) {
            count++;
        }
    }
    cout << count;
    return 0;
}
