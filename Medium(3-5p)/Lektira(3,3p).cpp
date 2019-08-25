#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <stack>
using namespace std;

//https://open.kattis.com/problems/lektira

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string word;
    cin >> word;
    int smallestCode = 1000, smallestIndex;
    for (int i = 0; i < word.size()-2; i++) {
        if ((int)word[i] < smallestCode) {
            smallestIndex = i;
            smallestCode = (int)word[i];
        }
        if ((int)word[i] == smallestCode) {
            for (int subtract = 1; subtract < i; subtract++) {
                if (smallestIndex - subtract < 0 || word[smallestIndex-subtract] < word[i-subtract]) {
                    break;
                }
                else if (word[smallestIndex - subtract] > word[i - subtract]) {
                    smallestIndex = i;
                    break;
                }
            }
        }
    }

    string firstWord, secondWord, thirdWord, subWord;
    firstWord = word.substr(0, smallestIndex+1);
    subWord = word.substr(smallestIndex + 1);

    smallestCode = 1000;
    for (int j = 0; j < subWord.size()-1; j++) {
        if ((int)subWord[j] < smallestCode) {
            smallestIndex = j;
            smallestCode = (int)subWord[j];
        }
        if ((int)subWord[j] == smallestCode) {
            for (int subtract = 1; subtract < j; subtract++) {
                if (smallestIndex - subtract < 0 || subWord[smallestIndex - subtract] < subWord[j - subtract]) {
                    break;
                }
                else if (subWord[smallestIndex - subtract] > subWord[j - subtract]) {
                    smallestIndex = j;
                    break;
                }
            }
        }
    }
    secondWord = subWord.substr(0, smallestIndex+1);
    thirdWord = subWord.substr(smallestIndex + 1);
    reverse(firstWord.begin(), firstWord.end());
    reverse(secondWord.begin(), secondWord.end());
    reverse(thirdWord.begin(), thirdWord.end());

    cout << firstWord << secondWord << thirdWord;
    return 0;
}
