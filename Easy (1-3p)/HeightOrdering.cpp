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
#include <queue>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/height

//solve by using insertion sort and counting the amount of swaps
int main()
{
    int cases;
    cin >> cases;

    for (int i = 1; i <= cases; i++) {
        int currCase;
        cin >> currCase;

        vector<int> students;
        int count = 0;
        for (int p = 0; p < 20; p++) {
            int height;
            cin >> height;
            students.push_back(height);
        }

        for (int ind = 1; ind < 20; ind++) {
            int j = ind;
            while (j > 0 && students[j] < students[j - 1]) {
                int temp = students[j - 1];
                students[j - 1] = students[j];
                students[j] = temp;
                count++;
                j--;
            }
        }

        cout << currCase << " " << count << "\n";
    }
    return 0;
}
