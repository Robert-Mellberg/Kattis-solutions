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

//https://open.kattis.com/problems/bank

void subtract(vector<int> &antalLuckor, int index) {
    for (int i = index; i >= 0; i--) {
        if (antalLuckor[i]) {
            antalLuckor[i] = 0;
            break;
        }
    }
}

bool getStatus(vector<int> &antalLuckor, int index) {
    for (int i = index; i >= 0; i--) {
        if (antalLuckor[i]) {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    int antalKunder, tid;
    cin >> antalKunder >> tid;

    vector<int> antalLuckor(tid, 1);
    int total = 0;

    multimap<int, int> pengarTid;
    for (int i = 0; i < antalKunder; i++) {
        int pengar, tid;
        cin >> pengar >> tid;
        pengarTid.insert(pair<int, int>(-pengar, tid));
    }

    for (auto obj : pengarTid) {
        int tid = obj.second;
        if (getStatus(antalLuckor, tid)) {
            total -= obj.first;
            subtract(antalLuckor, tid);
        }
    }
    cout << total;

    return 0;
}
