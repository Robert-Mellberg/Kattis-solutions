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

//https://open.kattis.com/problems/hangingout


int main()
{
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);
    int limit, commands;
    cin >> limit >> commands;
    int count = 0;
    int currStatus = 0;
    for (int i = 0; i < commands; i++) {
        string action;
        cin >> action;
        int amountOfPeople;
        cin >> amountOfPeople;
        if (action == "enter") {
            if (currStatus + amountOfPeople > limit) {
                count++;
            }
            else {
                currStatus += amountOfPeople;
            }
        }
        else {
            currStatus -= amountOfPeople;
        }
    }
    cout << count;
    return 0;
}
