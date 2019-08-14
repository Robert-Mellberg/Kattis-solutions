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

//https://open.kattis.com/problems/queens


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int antal;
    cin >> antal;

    unordered_set<int> rows;
    unordered_set<int> cols;
    unordered_set<int> diagonals1;
    unordered_set<int> diagonals2;
    bool impossible = false;
    for (int i = 0; i < antal; i++) {
        int row, col;
        cin >> row >> col;
        int diag1 = row + col;
        int diag2 = row - col;
        if (rows.find(row) != rows.end()) {
            impossible = true;
        }
        else if (cols.find(col) != cols.end()) {
            impossible = true;
        }
        else if (diagonals1.find(diag1) != diagonals1.end()) {
            impossible = true;
        }
        else if (diagonals2.find(diag2) != diagonals2.end()) {
            impossible = true;
        }
        rows.insert(row);
        cols.insert(col);
        diagonals1.insert(diag1);
        diagonals2.insert(diag2);
    }
    if (impossible) {
        cout << "INCORRECT";
    }
    else {
        cout << "CORRECT";
    }
    return 0;
}
 r
