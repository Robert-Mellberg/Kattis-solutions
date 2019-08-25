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
#include <bitset>
using namespace std;

//https://open.kattis.com/problems/beekeeper

int main()
{
	unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
	int amountOfWords;
	while (cin >> amountOfWords) {
		string longestWord = "";
		int longestWordVowels = -1;

		for (int i = 0; i < amountOfWords; i++) {
			string word;
			cin >> word;
			int amountOfVowels = 0;

			for (int c = 1; c < word.size(); c++) {
				if (word[c] == word[c - 1] && vowels.find(word[c]) != vowels.end()) {
					amountOfVowels++;
				}
			}

			if (amountOfVowels > longestWordVowels) {
				longestWordVowels = amountOfVowels;
				longestWord = word;
			}
		}

		cout << longestWord << endl;
	}
	
	

	return 0;
}
