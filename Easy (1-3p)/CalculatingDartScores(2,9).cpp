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

//https://open.kattis.com/problems/calculatingdartscores


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    vector<string> names = {"", "single", "double", "triple"};
    int sum;
    cin >> sum;
    for (int kast1 = 0; kast1 <= 20; kast1++) {
        for (int antal1 = 1; antal1 <= 3; antal1++) {
            for (int kast2 = 0; kast2 <= 20; kast2++) {
                for (int antal2 = 1; antal2 <= 3; antal2++) {
                    for (int kast3 = 0; kast3 <= 20; kast3++) {
                        for (int antal3 = 1; antal3 <= 3; antal3++) {
                            if (kast1*antal1 + kast2 * antal2 + kast3 * antal3 == sum) {
                                if (kast1 != 0) {
                                    cout << names[antal1] << " " << kast1 << "\n";
                                }
                                if (kast2 != 0) {
                                    cout << names[antal2] << " " << kast2 << "\n";
                                }
                                if (kast3 != 0) {
                                    cout << names[antal3] << " " << kast3 << "\n";
                                }
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "impossible";
    return 0;
}
