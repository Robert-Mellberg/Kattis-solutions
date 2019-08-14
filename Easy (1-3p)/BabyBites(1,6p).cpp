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

//https://open.kattis.com/problems/babybites


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int antal;
    cin >> antal;

    for (int i = 1; i <= antal; i++) {
        string mess;
        cin >> mess;
        if (mess == "mumble") {

        }
        else {
            int num = atoi(mess.c_str());
            if (num != i) {
                cout << "something is fishy";
                return 0;
            }
        }
    }
    cout << "makes sense";
    return 0;
}
