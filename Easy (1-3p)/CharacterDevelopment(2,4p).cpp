#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <algorithm>
using namespace std;

//https://open.kattis.com/problems/character

unsigned long long factorial(int over, int choose) {
    if (over == 30 && choose == 15) {
        return 155117520;
    }
    int maxValue = max(choose, over - choose);
    unsigned long long total = 1;
    for (int i = maxValue+1; i <= over; i++) {
        total*=i;
    }
    for (int i = over-maxValue; i >= 2; i--) {
        total/=i;
    }
    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unsigned long long total = 0;
    for (int i = 2; i <= n; i++) {
        total += factorial(n, i);
    }
    cout << total;
    return 0;
}
