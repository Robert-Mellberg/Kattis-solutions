#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/islands

int main()
{
    vector<int> table;


    int cases;
    cin >> cases;
    for (int j = 0; j < cases; j++) {
        int trash;
        cin >> trash;
        vector<int> bana;
        for (int i = 0; i < 12; i++) {
            int read;
            cin >> read;
            bana.push_back(read);
        }
        int total = 0;
        for (int size = 1; size <= 10; size++) {
            for (int startIndex = 1; startIndex <= 11 - size; startIndex++) {
                int endIndex = startIndex + size-1;

                bool check = true;
                for (int i = startIndex; i <= endIndex; i++) {
                    if (bana[i] <= bana[startIndex-1] || bana[i] <= bana[endIndex+1])
                        check = false;
                }
                if (check)
                    total++;
            }
        }
        cout << j + 1 << " " << total << endl;
    }
    
    return 0;
}
