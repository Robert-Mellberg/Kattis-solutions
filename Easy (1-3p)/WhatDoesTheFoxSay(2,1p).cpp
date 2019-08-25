#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

//https://open.kattis.com/problems/whatdoesthefoxsay

int main()
{
    int antalTestCases;
    cin >> antalTestCases;
    for (int i = 0; i < antalTestCases; i++) {


        vector<string> allWords;
        unordered_set<string> forbiddenWords;
        
        string t;
        cin.ignore();
        getline(cin, t);
        istringstream iss(t);
        string word;
        while (iss >> word) {
            /* do stuff with word */
            allWords.push_back(word);
        }
        int count = 0;
        while (true) {
            string read;
            cin >> read >> read;
            if (read == "does") {
                cin >> read >> read >> read;
                for (int i = 0; i < allWords.size(); i++) {
                    if (forbiddenWords.find(allWords[i]) == forbiddenWords.end()) {
                        if (count == 0) {
                            cout << allWords[i];
                        }
                        else {
                            cout << " " << allWords[i];
                        }
                        count++;
                    }
                }
                break;
            }
            else {
                cin >> read;
                forbiddenWords.insert(read);
            }
        }
        cout << endl;
    }
}
