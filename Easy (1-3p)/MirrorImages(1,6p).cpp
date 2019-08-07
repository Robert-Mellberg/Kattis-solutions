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

//https://open.kattis.com/problems/mirror

//Start by inserting all chars into a 2d array. Mirror all columns in the array and then mirror all the rows in the array.
int main()
{
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        int rows, columns;
        cin >> rows >> columns;

        vector<vector<char>> picture;
        for (int p = 0; p < rows; p++) {
            vector<char> row;
            for (int l = 0; l < columns; l++) {
                char c;
                cin >> c;
                row.push_back(c);
            }
            //mirror the columns
            for (int ind = 0; ind <= (columns-1) / 2; ind++) {
                int temp = row[ind];
                row[ind] = row[columns - 1 - ind];
                row[columns - 1 - ind] = temp;

            }
            picture.push_back(row);
        }
        //mirror the rows
        for (int x = 0; x < columns; x++) {
            for (int y = 0; y <= (rows-1) / 2; y++) {
                int temp = picture[y][x];
                picture[y][x] = picture[rows-1-y][x];
                picture[rows - 1 - y][x] = temp;
            }
        }
        //print picture
        cout << "Test " << i << "\n";
        for (vector<char> row : picture) {
            for (char c : row) {
                cout << c;
            }
            cout << "\n";
        }

    }
    
    return 0;
}
