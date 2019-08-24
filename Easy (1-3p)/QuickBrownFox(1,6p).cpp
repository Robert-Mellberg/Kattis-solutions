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

//https://open.kattis.com/problems/quickbrownfox

int main()
{
    int cases;
    cin >> cases;
    cin.ignore();
    for (int j = 0; j < cases; j++) {

        set<int> bokstaver;
        for (int i = 97; i <= 122; i++) {
            bokstaver.insert(i);
        }
        string word;
        getline(cin, word);
        for (char c : word) {
            bokstaver.erase(int(c));
            bokstaver.erase(int(c) + 32);
        }
        if (bokstaver.size() != 0) {
            cout << "missing ";
            for (int i : bokstaver) {
                cout << (char)i;
            }
            cout << endl;
        }
        else {
            cout << "pangram" << endl;
        }
    }
    return 0;
}
