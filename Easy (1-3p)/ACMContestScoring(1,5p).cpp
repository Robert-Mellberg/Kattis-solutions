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

//https://open.kattis.com/problems/acm

int main()
{
    unordered_map<char, int> wrongAnswers;
    string line;
    int totalScore = 0, totalProblemSolved = 0;
    while (getline(cin, line)) {
        if (line == "-1") {
            break;
        }
        int minutes;
        char problem;
        string status;
        stringstream ss(line);
        ss >> minutes >> problem >> status;

        if (status == "wrong") {
            wrongAnswers[problem]++;
        }
        else {
            totalScore += minutes;
            totalScore += wrongAnswers[problem]*20;
            totalProblemSolved++;
        }
    }
    cout << totalProblemSolved << " " << totalScore;
    return 0;
}
