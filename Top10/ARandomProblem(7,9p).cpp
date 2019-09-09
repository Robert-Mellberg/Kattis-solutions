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

//https://open.kattis.com/problems/randomproblem

struct trippleCorrelation {
    int a;
    int n;
    int b;
    int m;
    int c;
};

long long compareCorrelations(trippleCorrelation correlation, long long previousValue, vector<int> &siffror) {

    int a = correlation.a,  n = correlation.n,  b = correlation.b,  m = correlation.m,  c = correlation.c;

    long long value = 0;
    for (int i = 0; i < siffror.size(); i++) {
        int num = siffror[i];
        if (num == a && i+n+m < siffror.size() && siffror[i+n] == b) {
            if (siffror[i + n + m] != c) {
                return 0;
            }
            else {
                if (value == 0) {
                    value = i * 1000000 + n * 1000 + m;
                    if (value > previousValue) {
                        return 0;
                    }
                }
            }
        }
        if (num == b && i-n >= 0 && i+m < siffror.size() && siffror[i+m] == c && siffror[i-n] != a) {
            return 0;
        }
        if (num == c && i-m-n >= 0 && siffror[i-m-n] == a && siffror[i-m] != b) {
            return 0;
        }
    }
    return value;

}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int antalSiffror;
    cin >> antalSiffror;

    vector<int> siffror;
    for (int i = 0; i < antalSiffror; i++) {
        int read;
        cin >> read;
        siffror.push_back(read);
    }
    vector<int> possibleSizes(10, 0);
    vector<int> siffrorAppearance(10, 0);
    int minAppearance = ceil((double)siffror.size() / 40)+1;
    for (int ind = 0; ind < siffror.size(); ind++) {
        int siffra = siffror[ind];
        siffrorAppearance[siffra]++;
        if (siffrorAppearance[siffra] == minAppearance) {
            possibleSizes[siffra] = siffror.size() - ind;
        }
    }
    vector<int> xToYAppearance(100000, 0);
    vector<int> empty;
    vector<vector<int>> empty1(10, empty);
    vector<vector<vector<int>>> xToYDistances(10, empty1);

    for (int xInd = 0; xInd < siffror.size(); xInd++) {
        int x = siffror[xInd];
        for (int yInd = xInd + 1; yInd <= xInd + possibleSizes[x] && yInd < siffror.size(); yInd++) {
            int y = siffror[yInd];
            int hashIndex = x * 10000 + y * 1000 + yInd - xInd;
            xToYAppearance[hashIndex]++;
            if (xToYAppearance[hashIndex] == minAppearance) {
                xToYDistances[x][y].push_back(yInd - xInd);
            }
        }
    }

    vector<trippleCorrelation> trippleCorrelations;
    //test all a-b-c combinations
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {

                for (int n : xToYDistances[a][b]) {
                    for (int m : xToYDistances[b][c]) {
                        bool approved = false;
                        for (int mn : xToYDistances[a][c]) {
                            if (mn == n + m) {
                                approved = true;
                            }
                        }
                        if (approved) {
                            trippleCorrelations.push_back({a, n, b, m, c});
                        }

                    }
                }


            }
        }
    }
    long long hashValueMin = 10000000000;
    trippleCorrelation firstCor;
    for (trippleCorrelation tri : trippleCorrelations) {
        long long hashValue = compareCorrelations(tri, hashValueMin, siffror);
        if (hashValue && hashValue < hashValueMin) {
            hashValueMin = hashValue;
            firstCor = tri;
        }
    }
    if (hashValueMin != 10000000000) {
        cout << "triple correlation " << firstCor.a << "(" << firstCor.n << ")" << firstCor.b << "(" << firstCor.m << ")" << firstCor.c << " found";
    }
    else {
        cout << "random sequence";
    }
    return 0;
}
