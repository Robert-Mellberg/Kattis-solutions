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

//https://open.kattis.com/problems/stockbroker


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int antal;
    cin >> antal;

    vector<long long> prices;
    for (int i = 1; i <= antal; i++) {
        long long price;
        cin >> price;
        prices.push_back(price);
    }

    long long money = 100, antalStocks = 0;
    for (int d = 0; d < prices.size() - 1; d++) {
        if (prices[d] > prices[d + 1]) {
            //sell
            money += antalStocks * prices[d];
            antalStocks = 0;
        }
        else {
            if (antalStocks == 0) {
                //buy
                antalStocks = (money / prices[d]);
                if (antalStocks > 100000) {
                    antalStocks = 100000;
                }
                money -= antalStocks * prices[d];
            }
        }
    }
    money += antalStocks * prices[prices.size()-1];
    cout << money;

    return 0;
}
