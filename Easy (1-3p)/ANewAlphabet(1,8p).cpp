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

//https://open.kattis.com/problems/anewalphabet

int main()
{
    vector<string> shitMap = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};
    string word;
    
    getline(cin, word);
    for (char c : word) {
        if (int(c) >= 97 && int(c) <= 122) {
            cout << shitMap[int(c) - 97];
        }
        else if (int(c) >= 65 && int(c) <= 90) {
            cout << shitMap[int(c) - 65];
        }
        else {
            cout << c;
        }
    }
    return 0;
}
