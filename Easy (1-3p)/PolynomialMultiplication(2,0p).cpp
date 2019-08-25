#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <cmath>
#include <random>
#include <algorithm>
#include <sstream>
using namespace std;

//https://open.kattis.com/problems/polymul1

int main()
{
    int antalCases;
    cin >> antalCases;
    for (int p = 0; p < antalCases; p++) {


        int grad1, grad2;
        cin >> grad1;
        vector<int> pol1;
        for (int i = 0; i <= grad1; i++) {
            int read;
            cin >> read;
            pol1.push_back(read);
        }
        cin >> grad2;
        vector<int> pol2;
        for (int i = 0; i <= grad2; i++) {
            int read;
            cin >> read;
            pol2.push_back(read);
        }
        vector<int> langstaPol;
        vector<int> kortastePol;
        if (pol1.size() > pol2.size()) {
            langstaPol = pol1;
            kortastePol = pol2;
        }
        else {
            langstaPol = pol2;
            kortastePol = pol1;
        }
        vector<int> produktPol;
        for (int grad = 0; grad <= langstaPol.size() + kortastePol.size() - 2; grad++) {
            int total = 0;
            int size1 = langstaPol.size() - 1;
            for (int pol1Index = min(grad, size1); pol1Index >= 0 && (grad - pol1Index) < kortastePol.size(); pol1Index--) {
                total += langstaPol[pol1Index] * kortastePol[grad - pol1Index];
            }
            produktPol.push_back(total);
        }
        cout << produktPol.size()-1 << endl;
        for (int l = 0; l < produktPol.size(); l++) {
            cout << produktPol[l] << " ";
        }
        cout << endl;
    }

    return 0;
}
