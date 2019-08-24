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

//https://open.kattis.com/problems/raggedright

int main()
{
    int maxLength = 0;
    vector<int> sizes;
    string lastLine = "";
    string currLine = "";
    while (getline(cin, currLine)) {
        if(lastLine != "")
        sizes.push_back(lastLine.length());
        if (currLine.length() > maxLength) {
            maxLength = currLine.length();
        }
        lastLine = currLine;
    }
    int total = 0;
    for (int i : sizes) {
        total += (maxLength - i) * (maxLength - i);
    }
    cout << total;
    return 0;
}
