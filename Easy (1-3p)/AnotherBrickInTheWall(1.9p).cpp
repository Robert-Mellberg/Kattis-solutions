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

//https://open.kattis.com/problems/anotherbrick


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int height, width, antal;
    cin >> height >> width >> antal;
    vector<int> storlekar;
    for (int i = 0; i < antal; i++) {
        int read;
        cin >> read;
        storlekar.push_back(read);
    }
    int currWidth = 0;
    for (int b : storlekar) {
        currWidth += b;
        if (currWidth > width) {
            cout << "NO";
            return 0;
        }
        if (currWidth == width) {
            currWidth = 0;
            height--;
            if (height == 0) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}
