#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <algorithm>
using namespace std;

//https://open.kattis.com/problems/harddrive

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int sizeDisk, requiredAmount, brokenBits;
    cin >> sizeDisk >> requiredAmount >> brokenBits;
    unordered_set<int> brokenBitsList;
    for (int k = 0; k < brokenBits; k++) {
        int read;
        cin >> read;
        brokenBitsList.insert(read);
    }


    string sekvens = "0";
    int totalaBitChange = 0;
    bool forraNoll = true;
    for (int i = sizeDisk - 1; i >= 1; i--) {
        if (totalaBitChange >= requiredAmount-1) {
            sekvens += "0";
            continue;
        }
        if (brokenBitsList.find(i) != brokenBitsList.end() || !forraNoll) {
            forraNoll = true;
            sekvens += "0";
            continue;
        }
        if (forraNoll) {
            sekvens += "1";
            forraNoll = false;
            totalaBitChange += 2;
        }

    }
    if (requiredAmount - 1 == totalaBitChange) {
        sekvens[sekvens.length() - 1] = '1';
    }
    for (int l = sekvens.length() - 1; l >= 0; l--) {
        cout << sekvens[l];
    }

    return 0;
}
