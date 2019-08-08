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
#include <queue>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/coke

//The optimal strategy to buying coke is with as few coins as possible:
//1. Buy as many cokes you can with your 10kr coins.
//2. Buy n cokes with two 5kr coins each, where (n = amount of 5kr coins - amount of cokes left to buy).
//3. Buy as many cokes as you can with the remaining 5kr coins and three 1kr coins per coke.
//4. If you still haven't bought all cokes; travel back in time to step 1 and instead of inserting one 10kr coin for one coke
//   insert one 10kr coin and three 1kr coin, buy one coke, get a 5kr coin in exchange, insert one 5kr coin and three 1kr coins
//   and buy another coke. This will result in only using seven additional coins for the extra coke instead of eight (if we only used 1kr coins)
//5. Buy the remaining (if any) with eight 1kr coins each.


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    unordered_map<char, char> charMap;
    
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int coke, ett, fem, tio;
        cin >> coke >> ett >> fem >> tio;
        
        //buy with 10kr coins
        int count = 0;
        count += min(tio, coke);
        coke -= tio;
        if (coke <= 0) {
            cout << count << "\n";
            continue;
        }
        ett += 2 * tio;
        
        //buy with two 5kr coins
        int koptFem = max(0, fem - coke);
        koptFem = min(koptFem, coke);
        fem -= 2*koptFem;
        coke -= koptFem;
        ett += 2 * koptFem;
        count += 2 * koptFem;
        
        //buy with one 5kr coin and three 1kr coins
        int koptFemEtt = min(fem, coke);
        coke -= koptFemEtt;
        count += 4*koptFemEtt;
        ett -= 3 * koptFemEtt;
        

        //see step 4
        int changeOnesToTen = min(tio, coke);
        coke -= changeOnesToTen;
        count += 7 * changeOnesToTen;

        //buy with eight 1kr coins
        count += coke * 8;
        cout << count << "\n";

    }

    return 0;
}
