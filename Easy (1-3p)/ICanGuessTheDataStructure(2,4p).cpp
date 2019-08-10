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
#include <queue>
using namespace std;


//https://open.kattis.com/problems/guessthedatastructure




int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int antal;
    while (cin >> antal) {

        stack<int> Stack;
        queue<int> Q;
        priority_queue<int> PQ;
        bool stWork = 1, qWork = 1, pQWork = 1;

        for (int i = 0; i < antal; i++) {
            int type, num;
            cin >> type >> num;
            if (type == 1) {
                Stack.push(num);
                Q.push(num);
                PQ.push(num);
            }
            else {
                if (Stack.size() == 0) {
                    stWork = false;
                    qWork = false;
                    pQWork = false;
                    continue;
                }
                if (Stack.top() != num) {
                    stWork = false;
                }
                if (Q.front() != num) {
                    qWork = false;
                }
                if (PQ.top() != num) {
                    pQWork = false;
                }
                Stack.pop();
                Q.pop();
                PQ.pop();
            }
        }
        if (stWork + qWork + pQWork >= 2) {
            cout << "not sure\n";
        }
        else if (!stWork && !qWork && !pQWork) {
            cout << "impossible\n";
        }
        else if (stWork) {
            cout << "stack\n";
        }
        else if (qWork) {
            cout << "queue\n";
        }
        else if (pQWork) {
            cout << "priority queue\n";
        }
    }
    
    return 0;
}
