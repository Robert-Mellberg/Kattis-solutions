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

//https://open.kattis.com/problems/integerlists

//Could also represent structure in a doubly linked list.

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        string input;
        cin >> input;
        int antalIArray;
        cin >> antalIArray;

        vector<int> integerList;
        char trash;
        cin >> trash;
        for (int i = 0; i < antalIArray; i++) {
            int read;
            cin >> read >> trash;
            integerList.push_back(read);
        }
        if (antalIArray == 0) {
            cin >> trash;
        }

        bool reversed = false;
        int start = 0, end = integerList.size() - 1;
        for (char c : input) {
            if (c == 'D') {
                if (reversed) {
                    end--;
                }
                else {
                    start++;
                }
            }
            else {
                reversed ^= true;
            }
        }

        if (end == start - 1) {
            cout << "[]\n";
        }
        else if (end < start - 1) {
            cout << "error\n";
        }
        else {
            cout << "[";
            if (!reversed) {
                for (int ind = start; ind < end; ind++) {
                    cout << integerList[ind] << ",";
                }
                cout << integerList[end] << "]\n";
            }
            else {
                for (int ind = end; ind > start; ind--) {
                    cout << integerList[ind] << ",";
                }
                cout << integerList[start] << "]\n";
            }
        }
    }
    return 0;
}
