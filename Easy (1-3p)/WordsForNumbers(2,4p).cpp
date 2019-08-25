#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/wordsfornumbers

vector<string> singleNumber = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> doubleNumber = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
int main()
{
    
    string input;
    while (getline(cin, input)) {

        istringstream iss(input);
        string word;
        iss >> word;
        if ((int)word[0] >= 48 && (int)word[0] <= 57) {
            string number;
            if (word.length() == 1 || (int)word[0] == 49) {
                number = singleNumber[atoi(word.c_str())];
            }
            else {
                int num = atoi(word.c_str());
                number = doubleNumber[num/10];
                if (num % 10 != 0) {
                    number+= "-" + singleNumber[num % 10];
                }
            }
            number[0] = (char)((int)number[0] - 32);
            cout << number;
        }
        else {
            cout << word;
        }
        while (iss >> word) {
            if ((int)word[0] >= 48 && (int)word[0] <= 57) {
                string number;
                if (word.length() == 1 || (int)word[0] == 49) {
                    number = singleNumber[atoi(word.c_str())];
                }
                else {
                    int num = atoi(word.c_str());
                    number = doubleNumber[num / 10];
                    if (num % 10 != 0) {
                        number += "-" + singleNumber[num % 10];
                    }
                }
                cout << " " << number;
            }
            else {
                cout << " " << word;
            }
        }
        cout << endl;

    }
    return 0;
}
