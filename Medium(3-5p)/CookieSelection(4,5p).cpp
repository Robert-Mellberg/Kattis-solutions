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
using namespace std;

//https://open.kattis.com/problems/cookieselection

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;

    string num;
    while (cin >> num) {
        if (num == "#") {
            int diameter = upper.top();
            upper.pop();
            cout << diameter << "\n";
            if (upper.size() < lower.size()) {
                int switchNum = lower.top();
                lower.pop();
                upper.push(switchNum);
            }
        }
        else {
            int numberInt = atoi(num.c_str());
            if (upper.size() == 0 || upper.top() <= numberInt) {
                upper.push(numberInt);
                if (upper.size() - lower.size() == 2) {
                    int switchNum = upper.top();
                    upper.pop();
                    lower.push(switchNum);
                }
            }
            else {
                lower.push(numberInt);
                if (upper.size()+1 == lower.size()) {
                    int switchNum = lower.top();
                    lower.pop();
                    upper.push(switchNum);
                }
            }
        }
    }
    
    return 0;
}
