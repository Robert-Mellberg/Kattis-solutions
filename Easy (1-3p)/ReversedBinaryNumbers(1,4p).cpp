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

//https://open.kattis.com/problems/reversebinary

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int number;
    vector<int> bitRep;
    cin >> number;
    while (number != 0) {
        bitRep.push_back(number%2);
        number /= 2;
    }

    int newNum = 0;
    for (int i = 0; i < bitRep.size(); i++) {
        newNum += bitRep[i] * pow(2, bitRep.size()-1-i);
    }
    cout << newNum;

    return 0;
}
