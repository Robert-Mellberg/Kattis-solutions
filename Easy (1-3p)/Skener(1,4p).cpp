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

//https://open.kattis.com/problems/skener

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int row, column, newRow, newColumn;
    cin >> row >> column >> newRow >> newColumn;
    cin.ignore();
    for (int i = 0; i < row; i++) {
        string row;
        getline(cin, row);

        for (int l = 0; l < newRow; l++) {
            for (int let = 0; let < row.size(); let++) {
                char c = row[let];
                for (int p = 0; p < newColumn; p++) {
                    cout << c;
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}
