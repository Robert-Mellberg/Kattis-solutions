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
#include <stack>
using namespace std;

//https://open.kattis.com/problems/aboveaverage

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        int antal;
        cin >> antal;
        double total = 0;
        vector<int> scoreElever;
        for (int j = 0; j < antal; j++) {
            int read;
            cin >> read;
            total += read;
            scoreElever.push_back(read);
        }
        total /= antal;
        int antalElever = 0;
        for (int k = 0; k < antal; k++) {
            if (scoreElever[k] > total) {
                antalElever++;
            }
        }
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(3);
        cout << ((double)antalElever / antal)*100 << "%" << endl;
    }
    
    return 0;
}
