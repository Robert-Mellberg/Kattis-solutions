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

//https://open.kattis.com/problems/volim

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int start, questions;
    cin >> start >> questions;
    start--;
    int totalTime = 0;
    for (int i = 0; i < questions; i++) {
        int time;
        char answer;
        cin >> time >> answer;
        totalTime += time;
        if (totalTime > 210) {
            break;
        }
        if (answer == 'T') {
            start = (start + 1)%8;
        }
    }
    cout << start + 1;
    return 0;
}
