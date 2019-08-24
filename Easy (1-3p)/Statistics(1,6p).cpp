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

//https://open.kattis.com/problems/statistics

int main()
{
    int amountOfSamples;
    int testCase = 0;
    while (cin >> amountOfSamples) {
        testCase++;
        int min = 1000001;
        int max = -1000001;

        for (int i = 0; i < amountOfSamples; i++) {
            int read;
            cin >> read;
            if (read > max) {
                max = read;
            }
            if (read < min) {
                min = read;
            }
        }
        cout << "Case " << testCase << ": " << min << " " << max << " " << max - min << endl;
    }
    return 0;
}
