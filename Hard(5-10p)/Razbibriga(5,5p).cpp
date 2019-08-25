#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

//https://open.kattis.com/problems/razbibriga

int main()
{
    vector<vector<int>> antalMedNamn;
    vector<int> inre(26, 0);
    antalMedNamn.resize(26, inre);
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    long long total = 0;
    int antalOrd;
    cin >> antalOrd;

    for (int k = 0; k < antalOrd; k++) {
        string namn;
        cin >> namn;
        int bokstavForst = (int)namn[0]-65;
        int bokstavSist = (int)namn.back()-65;
        antalMedNamn[bokstavForst][bokstavSist] = antalMedNamn[bokstavForst][bokstavSist] + 1;
    }
    for (int bokstav1 = 0; bokstav1 < 26; bokstav1++) {
        for (int bokstav2 = 0; bokstav2 < 26; bokstav2++) {
            int antalNamn1 = antalMedNamn[bokstav1][bokstav2];
            for (int bokstav3 = 0; bokstav3 < 26; bokstav3++) {
                int antalNamn2 = antalMedNamn[bokstav1][bokstav3];
                if (bokstav2 == bokstav3) {
                    antalNamn2--;
                }
                for (int bokstav4 = 0; bokstav4 < 26; bokstav4++) {
                    int antalNamn3 = antalMedNamn[bokstav3][bokstav4];
                    if (bokstav1 == bokstav3) {
                        if (bokstav2 == bokstav4) {
                            antalNamn3--;
                        }
                        if (bokstav3 == bokstav4) {
                            antalNamn3--;
                        }
                    }
                    int antalNamn4 = antalMedNamn[bokstav2][bokstav4];
                    if (bokstav1 == bokstav2) {
                        if (bokstav2 == bokstav4) {
                            antalNamn4--;
                        }
                        if (bokstav3 == bokstav4) {
                            antalNamn4--;
                        }
                    }
                    if (bokstav2 == bokstav3) {
                        antalNamn4--;
                    }
                    total += antalNamn1*antalNamn2*antalNamn3*antalNamn4;
                }
            }
        }
    }
    cout << total;
    return 0;
}
