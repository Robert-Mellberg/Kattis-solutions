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

//https://open.kattis.com/problems/provincesandgold



int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    int total = num1 * 3 + num2 * 2 + num3 * 1;
    if (total >= 8) {
        cout << "Province or ";
    }
    else if (total >= 5) {
        cout << "Duchy or ";
    }
    else if (total >= 2) {
        cout << "Estate or ";
    }
    if (total >= 6) {
        cout << "Gold";
    }
    else if (total >= 3) {
        cout << "Silver";
    }
    else{
        cout << "Copper";
    }
    return 0;
}
