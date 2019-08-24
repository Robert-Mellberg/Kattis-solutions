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

//https://open.kattis.com/problems/easiest

int getSifferSumma(int a) {
    int summa = 0;
    for (int i = 1; i <= a; i *= 10) {
        summa += (a%(i * 10))/i;
    }
    return summa;
}

int main()
{
    int num;
    while (cin >> num) {
        if (num == 0) {
            break;
        }
        int smallest = 10;
        int summa = getSifferSumma(num);
        while (true) {
            smallest++;
            if (getSifferSumma(smallest*num) == summa) {
                break;
            }
        }
        cout << smallest << endl;
    }
    return 0;
}
