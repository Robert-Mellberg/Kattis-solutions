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

//https://open.kattis.com/problems/nastyhacks

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cases;
    cin >> cases;
    for (int l = 0; l < cases; l++) {

        int noAdvert, advert, cost;
        cin >> noAdvert >> advert >> cost;
        if (advert - cost > noAdvert) {
            cout << "advertise" << endl;
        }
        else if (advert - cost == noAdvert) {
            cout << "does not matter" << endl;;
        }
        else {
            cout << "do not advertise" << endl;
        }
    }
    return 0;
}
