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

//https://open.kattis.com/problems/relocation


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int antalBygg, queries;
    cin >> antalBygg >> queries;

    vector<int> placeringar(antalBygg+1, 0);
    for (int i = 1; i <= antalBygg; i++) {
        int read;
        cin >> read;
        placeringar[i] = read;
    }
    for (int j = 0; j < queries; j++) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            placeringar[a] = b;
        }
        else {
            cout << abs(placeringar[a] - placeringar[b]) << endl;
        }
    }
    return 0;
}
