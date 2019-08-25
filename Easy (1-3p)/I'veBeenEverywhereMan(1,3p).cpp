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

//https://open.kattis.com/problems/everywhere

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int antal;
        cin >> antal;
        unordered_set<string> stader;
        int count = 0;
        for (int i = 0; i < antal; i++) {
            string read;
            cin >> read;
            if (stader.find(read) != stader.end()) {
                continue;
            }
            stader.insert(read);
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
