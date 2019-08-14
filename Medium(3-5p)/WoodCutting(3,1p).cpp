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

//https://open.kattis.com/problems/woodcutting


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        long long antalKunder = 0;
        cin >> antalKunder;

        vector<long long> storlekKund;
        for (int j = 0; j < antalKunder; j++) {
            long long antalBitar;
            cin >> antalBitar;
            long long totalStorlek = 0;
            for (int k = 0; k < antalBitar; k++) {
                long long stor;
                cin >> stor;
                totalStorlek += stor;
            }
            storlekKund.push_back(totalStorlek);
        }
        long long totalVanteTid = 0;
        sort(storlekKund.begin(), storlekKund.end());
        for (int l = 0; l < storlekKund.size(); l++) {
            long long antalKvar = storlekKund.size() - l;
            totalVanteTid += antalKvar * storlekKund[l];
        }
        printf("%.10f", totalVanteTid / (double)storlekKund.size());
        if (i != cases - 1) {
            printf("\n");
        }
    }
    return 0;
}
