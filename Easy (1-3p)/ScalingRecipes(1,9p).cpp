#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
#include <random>
#include <iomanip> 
using namespace std;

//https://open.kattis.com/problems/recipes

int main()
{
    int antalCases;
    cin >> antalCases;
    for (int i = 1; i <= antalCases; i++) {
        cout << "Recipe" << " # " << i << endl;
        vector<string> namn;
        vector<double> procent;
        int antalIngred, antalPortRec, antalPortDes;
        cin >> antalIngred >> antalPortRec >> antalPortDes;
        double multi = (double)antalPortDes / antalPortRec;
        double refVikt;
        for (int l = 0; l < antalIngred; l++) {
            string ingredNamn;
            double vikt, proc;
            cin >> ingredNamn >> vikt >> proc;
            namn.push_back(ingredNamn);
            procent.push_back(proc/100);
            if (proc == 100.0) {
                refVikt = vikt * multi;
            }
        }
        for (int j = 0; j < namn.size(); j++) {
            cout << namn[j] << " " << fixed << setprecision(1) << (procent[j]*refVikt) << endl;
        }
        cout << "----------------------------------------" << endl;
    }
}
