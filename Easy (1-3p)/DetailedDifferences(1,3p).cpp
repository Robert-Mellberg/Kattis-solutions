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

//https://open.kattis.com/problems/detaileddifferences

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        string word1, word2;
        cin >> word1 >> word2;
        cout << word1 << endl << word2 << endl;
        for (int j = 0; j < word1.size(); j++) {
            if (word1[j] == word2[j]) {
                cout << ".";
            }
            else {
                cout << "*";
            }
        }
        cout << endl;
    }
    
    return 0;
}
