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

//https://open.kattis.com/problems/hydrasheads

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    while(true){

        int head, tails;
        cin >> head >> tails;
        int antalMoves = 0;
        if (head == 0 && tails == 0) {
            break;
        }
        
        if (head & 1 && tails == 0) {
            cout << -1 << endl;
            continue;
        }
        head += tails / 2;
        antalMoves += tails / 2;
        tails %= 2;

        antalMoves += head / 2;
        head %= 2;

        if (head == 1 && tails == 1) {
            antalMoves += 3;
        }
        else if (head == 1 && tails == 0) {
            antalMoves += 4;
        }
        else if (head == 0 && tails == 1) {
            antalMoves += 6;
        }
        cout << antalMoves << endl;
    }
    return 0;
}
