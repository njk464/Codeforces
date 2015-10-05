#include <set>
#include <map>
#include <list>
#include <utility> // for pair
#include <limits>
#include <iterator>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
int main() {
	vector<int> boys;
	vector<int> girls;
	int b, g;
	int pairs = 0;
	cin >> b;
	for (int i = 0; i < b; i++) {
		int next;
		cin >> next;
		boys.push_back(next);
	}
	sort(boys.begin(), boys.end());
	cin >> g;
	for (int i = 0; i < g; i++) {
		int next;
		cin >> next;
		girls.push_back(next);
	}
	sort(girls.begin(), girls.end());
	int i = 0;
	int j = 0;
	while (i < boys.size() && j < girls.size()){
		if (girls[j] > boys[i] + 1)
			i++;
		else if (girls[j] < boys[i] - 1)
			j++;
		else
		{
			i++;
			j++;
			pairs++;
		}
	}
	cout << pairs;
}
