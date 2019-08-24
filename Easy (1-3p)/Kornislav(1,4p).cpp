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

//https://open.kattis.com/problems/kornislav

int main()
{
    vector<int> numbers;
    for (int i = 0; i < 4; i++) {
        int read;
        cin >> read;
        numbers.push_back(read);
    }
    sort(numbers.begin(), numbers.end());
    cout << numbers[0] * numbers[2];
    return 0;
}
