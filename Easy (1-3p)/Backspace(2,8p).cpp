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

//https://open.kattis.com/problems/backspace

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    cin >> input;
    vector<char> newWord;
    for (int i = 0; i < input.length(); i++){
        if (input[i] == '<') {
            newWord.pop_back();
        }
        else {
            newWord.push_back(input[i]);
        }
    }

    for (char c : newWord) {
        cout << c;
    }

    return 0;
}
