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

//https://open.kattis.com/problems/alphabet

string word;
int maxIRad = 0;
void allaFoljder(int indexMin, int valueMin, int count) {
    if (count > maxIRad) {
        maxIRad = count;
    }
    int maxx = 1000;
    for (int index = indexMin + 1; index < word.length(); index++) {
        int charValue = int(word[index]);
        if (charValue < maxx && charValue >valueMin) {
            maxx = charValue;
            allaFoljder(index, charValue, count+1);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> word;
    allaFoljder(-1, 0, 0);

    cout << 26-maxIRad;
    return 0;
}
