#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
#include <random>
using namespace std;

//https://open.kattis.com/problems/freeweights

int main()
{
    vector<int> vikterUpper;
    vector<int> vikterLower;

    int antalVikter;
    cin >> antalVikter;
    for (int i = 0; i < antalVikter; i++) {
        int vikt;
        cin >> vikt;
        vikterUpper.push_back(vikt);
    }
    for (int i = 0; i < antalVikter; i++) {
        int vikt;
        cin >> vikt;
        vikterLower.push_back(vikt);
    }
    if (antalVikter == 1) {
        cout << vikterUpper[0];
        return 0;
    }

    int tyngsta = 0;
    bool change = false;;
    int left = vikterUpper[0];
    for (int j = 1; j < vikterUpper.size(); j++) {
        if (change) {
            left = vikterUpper[j];
            change = false;
            if (j == vikterUpper.size() - 1) {
                if (left > tyngsta) {
                    tyngsta = left;
                }
            }
            continue;
        }
        if (j == vikterUpper.size() - 1) {
            if (vikterUpper[j] != left) {
                if (vikterUpper[j] > tyngsta) {
                    tyngsta = vikterUpper[j];
                }
                if (left > tyngsta) {
                    tyngsta = left;
                }
            }
            continue;
        }
        //samma vikt som början
        if (vikterUpper[j] == left) {
            change = true;
            continue;
        }
        if (vikterUpper[j] > left) {
            if (left > tyngsta) {
                tyngsta = left;
            }
            left = vikterUpper[j];
            continue;
        }
        if (vikterUpper[j] > tyngsta) {
            tyngsta = vikterUpper[j];
        }
    }

    left = vikterLower[0];
    change = false;
    for (int j = 1; j < vikterLower.size(); j++) {
        if (change) {
            left = vikterLower[j];
            change = false;
            if (j == vikterLower.size() - 1) {
                if (left > tyngsta) {
                    tyngsta = left;
                }
            }
            continue;
        }
        if (j == vikterLower.size() - 1) {
            if (vikterLower[j] != left) {
                if (vikterLower[j] > tyngsta) {
                    tyngsta = vikterLower[j];
                }
                if (left > tyngsta) {
                    tyngsta = left;
                }
            }
            continue;
        }
        //samma vikt som början
        if (vikterLower[j] == left) {
            change = true;
            continue;
        }
        if (vikterLower[j] > left) {
            if (left > tyngsta) {
                tyngsta = left;
            }
            left = vikterLower[j];
            continue;
        }
        if (vikterLower[j] > tyngsta) {
            tyngsta = vikterLower[j];
        }
    }

    cout << tyngsta;
    return 0;
}
