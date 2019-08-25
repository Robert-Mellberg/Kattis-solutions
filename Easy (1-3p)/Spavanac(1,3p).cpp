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
#include <stack>
using namespace std;

//https://open.kattis.com/problems/spavanac

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int hour, min;
    cin >> hour >> min;
    hour = hour + (min / 45) - 1;
    min = (min + 15) % 60;
    hour = (hour + 24) % 24;
    cout << hour << " " << min;
    return 0;
}
