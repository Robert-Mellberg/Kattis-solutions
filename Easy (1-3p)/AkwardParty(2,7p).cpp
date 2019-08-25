#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
using namespace std;

//https://open.kattis.com/problems/awkwardparty

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<int, int> seatings;
    
    int antalGaster;
    cin >> antalGaster;
    int min = antalGaster;
    for (int i = 1; i <= antalGaster; i++) {
        int gastSprak;
        cin >> gastSprak;
        int andraTalarePlacering = seatings[gastSprak];
        seatings[gastSprak] = i;
        if (andraTalarePlacering == 0) {
            continue;
        }
        if (i - andraTalarePlacering < min) {
            min = i - andraTalarePlacering;
        }
    }
    cout << min;

    return 0;
}
