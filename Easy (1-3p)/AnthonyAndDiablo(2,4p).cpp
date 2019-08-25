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

//https://open.kattis.com/problems/anthonyanddiablo

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    double area, langd;
    cin >> area >> langd;
    if ((langd*langd)/(4*3.141592653589793238462643383279502884) >= area) {
        cout << "Diablo is happy!";
    }
    else {
        cout << "Need more materials!";
    }
    return 0;
}
