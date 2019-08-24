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

//https://open.kattis.com/problems/clockpictures

//For each clock, read all the angles and put them into a vector and sort it in ascending order
//Then calculate all the angles between every adjacent hand and put it into a vector
//Compare the two vectors with the adjacent angles to see if they are the same
//Note that the two vectors don't have to be identical, one vector will probably be offset from the other.

//E.g, if these two vectors represents the angles between each adjacent hand for both clocks, then the clocks are identical;
//[1000, 1500, 5000, 4000, 7000, 10000, 50000, 281500], [4000, 7000, 10000, 50000, 281500, 1000, 1500, 5000]


int main()
{
	int hands;
	cin >> hands;
	
	vector<int> clock1Hands, clock2Hands;
	for (int i = 0; i < hands; i++) {
		int angle;
		cin >> angle;
		clock1Hands.push_back(angle);
	}
	for (int i = 0; i < hands; i++) {
		int angle;
		cin >> angle;
		clock2Hands.push_back(angle);
	}
	sort(clock1Hands.begin(), clock1Hands.end());
	sort(clock2Hands.begin(), clock2Hands.end());

	//pair<angle, amountOfTimes>
	vector<pair<int, int>> adjacentHandsAngles1, adjacentHandsAngles2;

	int angle1 = clock1Hands[0] - clock1Hands[clock1Hands.size() - 1] + 360000;
	int angle2 = clock2Hands[0] - clock2Hands[clock2Hands.size() - 1] + 360000;

	adjacentHandsAngles1.push_back(pair<int, int>(angle1, 1));
	adjacentHandsAngles2.push_back(pair<int, int>(angle2, 1));

	for (int ind = 1; ind < clock1Hands.size(); ind++) {
		angle1 = clock1Hands[ind] - clock1Hands[ind - 1];
		angle2 = clock2Hands[ind] - clock2Hands[ind - 1];

		if (adjacentHandsAngles1[adjacentHandsAngles1.size() - 1].first == angle1) {
			adjacentHandsAngles1[adjacentHandsAngles1.size() - 1].second++;
		}
		else {
			adjacentHandsAngles1.push_back(pair<int, int>(angle1, 1));
		}

		if (adjacentHandsAngles2[adjacentHandsAngles2.size() - 1].first == angle2) {
			adjacentHandsAngles2[adjacentHandsAngles2.size() - 1].second++;
		}
		else {
			adjacentHandsAngles2.push_back(pair<int, int>(angle2, 1));
		}
	}
	
	if (adjacentHandsAngles1[0].first == adjacentHandsAngles1[adjacentHandsAngles1.size() - 1].first) {
		adjacentHandsAngles1[0].second += adjacentHandsAngles1[adjacentHandsAngles1.size() - 1].second;
		adjacentHandsAngles1.pop_back();
	}

	if (adjacentHandsAngles2[0].first == adjacentHandsAngles2[adjacentHandsAngles2.size() - 1].first) {
		adjacentHandsAngles2[0].second += adjacentHandsAngles2[adjacentHandsAngles2.size() - 1].second;
		adjacentHandsAngles2.pop_back();
	}

	if (adjacentHandsAngles1.size() != adjacentHandsAngles2.size()) {
		cout << "impossible";
		return 0;
	}

	for (int offset = 0; offset <= adjacentHandsAngles1.size(); offset++) {
		bool possible = true;
		for (int index = 0; index < adjacentHandsAngles1.size(); index++) {
			pair<int, int> *angleClock1 = &adjacentHandsAngles1[(index + offset) % adjacentHandsAngles1.size()];
			pair<int, int> *angleClock2 = &adjacentHandsAngles2[index];

			if (angleClock1->first != angleClock2->first || angleClock1->second != angleClock2->second) {
				possible = false;
				break;
			}
		}

		if (possible) {
			cout << "possible";
			return 0;
		}
	}

	cout << "impossible";

	return 0;
}
