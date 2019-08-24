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

//https://open.kattis.com/problems/amanda

struct node {
    int stuga = 0;
    vector<int> grannar;
};

bool impossible = false;

pair<int, int> countLounges(stack<node> &fixedStugor, vector<node> &allaStugor) {
    int count0 = 0, count2 = 0;

    while (!fixedStugor.empty()) {
        node nod = fixedStugor.top();
        fixedStugor.pop();

        for (int granne : nod.grannar) {
            if (nod.stuga == 1) {
                if (allaStugor[granne].stuga == 0) {
                    allaStugor[granne].stuga = -1;
                    fixedStugor.push(allaStugor[granne]);
                    count0++;
                }
                else if (allaStugor[granne].stuga == 1) {
                    impossible = true;
                }
            }
            else if (nod.stuga == -1){
                if (allaStugor[granne].stuga == 0) {
                    allaStugor[granne].stuga = 1;
                    fixedStugor.push(allaStugor[granne]);
                    count2++;
                }
                else if (allaStugor[granne].stuga == -1) {
                    impossible = true;
                }
            }
        }
    }

    return pair<int, int>(count0, count2);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int antalLounges, antalRoutes;
    cin >> antalLounges >> antalRoutes;

    node nodEmpty = {};
    vector<node> stugor (antalLounges, nodEmpty);

    int totalUtplaceradeStugor = 0;
    //read data
    for (int i = 0; i < antalRoutes; i++) {
        int stuga1, stuga2, antalStugor;
        cin >> stuga1 >> stuga2 >> antalStugor;
        stuga1--; stuga2--;

        if (antalStugor == 0) {
            if (stugor[stuga1].stuga == 1) {
                impossible = true;
            }
            else {
                stugor[stuga1].stuga = -1;
            }
            if (stugor[stuga2].stuga == 1) {
                impossible = true;
            }
            else {
                stugor[stuga2].stuga = -1;
            }
        }
        else if (antalStugor == 1) {
            stugor[stuga1].grannar.push_back(stuga2);
            stugor[stuga2].grannar.push_back(stuga1);
        }
        else {
            if (stugor[stuga1].stuga == -1) {
                impossible = true;
            }
            else {
                if (stugor[stuga1].stuga != 1) {
                    totalUtplaceradeStugor++;
                }
                stugor[stuga1].stuga = 1;
            }
            if (stugor[stuga2].stuga == -1) {
                impossible = true;
            }
            else {
                if (stugor[stuga2].stuga != 1) {
                    totalUtplaceradeStugor++;
                }
                stugor[stuga2].stuga = 1;
            }
        }
    }

    stack<node> fixedStugor;
    for (node stuga : stugor) {
        if (stuga.grannar.size() != 0 && (stuga.stuga == 1 || stuga.stuga == -1)) {
            fixedStugor.push(stuga);
        }
    }
    pair<int, int> result = countLounges(fixedStugor, stugor);
    totalUtplaceradeStugor += result.second;


    for (node stuga : stugor) {
        if (stuga.stuga == 0) {
            stuga.stuga = 1;
            fixedStugor.push(stuga);
            pair<int, int> result = countLounges(fixedStugor, stugor);
            int minAdd = min(result.first, result.second);
            totalUtplaceradeStugor += minAdd;
        }
    }


    if (impossible) {
        cout << "impossible";
    }
    else {
        cout << totalUtplaceradeStugor;
    }


    return 0;
}
