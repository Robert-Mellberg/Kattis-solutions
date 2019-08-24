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

//https://open.kattis.com/problems/server

int main()
{
    int antalProblem, totalTime;
    cin >> antalProblem >> totalTime;
    int timeSpent = 0, problemsSolved = 0;
    for (int i = 0; i < antalProblem; i++) {
        int read;
        cin >> read;
        timeSpent += read;
        if (timeSpent > totalTime) {
            break;
        }
        problemsSolved++;
    }
    cout << problemsSolved;
    return 0;
}
