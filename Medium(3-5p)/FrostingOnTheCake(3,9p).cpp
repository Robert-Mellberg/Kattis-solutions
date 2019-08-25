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

//https://open.kattis.com/problems/frosting

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> bredder, hojder = {0, 0, 0};
    int antal;
    cin >> antal;
    for (int i = 0; i < antal; i++) {
        int read;
        cin >> read;
        bredder.push_back(read);
    }
    for (int i = 0; i < antal; i++) {
        int read;
        cin >> read;
        hojder[i % 3] += read;
    }

    vector<unsigned long long> frosting = {0, 0, 0};
    
    for (int breddSiffra = 0; breddSiffra < bredder.size(); breddSiffra++) {
        for (int hojdSiffra = 0; hojdSiffra < hojder.size(); hojdSiffra++) {
            int index = (hojdSiffra + breddSiffra + 2) % 3;
            frosting[index] += (unsigned long long)bredder[breddSiffra] * hojder[hojdSiffra];
        }
    }
    
    cout << frosting[0] << " " << frosting[1] << " " << frosting[2];
    return 0;
}
