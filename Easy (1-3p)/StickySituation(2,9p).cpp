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

//https://open.kattis.com/problems/stickysituation


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int antal;
    cin >> antal;
    vector<long long> lengths;
    for (int i = 0; i < antal; i++) {
        long long read;
        cin >> read;
        lengths.push_back(read);
    }
    sort(lengths.begin(), lengths.end());
    for (int last = lengths.size() - 1; last >= 2; last--) {
        if (lengths[last - 2] + lengths[last - 1] > lengths[last]) {
            cout << "possible";
            return 0;
        }
    }
    cout << "impossible";
    return 0;
}
