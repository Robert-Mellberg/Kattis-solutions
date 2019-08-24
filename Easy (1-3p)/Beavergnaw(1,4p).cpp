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

//https://open.kattis.com/problems/beavergnaw



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		double diameter, volume;
		cin >> diameter >> volume;
		if (diameter == 0) {
			break;
		}
		double d = pow(pow(diameter, 3) - (volume * 6 / 3.14159265358979323846264338327), 1.0 / 3);
		printf("%.10f", d);
		printf("\n");
	}
	return 0;
}
