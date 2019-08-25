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

//https://open.kattis.com/problems/isithalloween

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string manad;
    int dag;
    cin >> manad >> dag;
    if (manad == "OCT" && dag == 31|| manad == "DEC" && dag == 25) {
        cout << "yup";
    }
    else {
        cout << "nope";
    }
    return 0;
}
