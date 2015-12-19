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
int n;
pair<int, int> trees[100000];
int amount[100000];
bool r[100000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> trees[i].first;
		cin >> trees[i].second;
		// cout << "[" << trees[i].first << ", " << trees[i].second << "]";
	}
	amount[0] = 1;
	r[0] = false;
	for (int i = 1; i < n-1; i++) {
		int x1 = trees[i-1].first;
		int h1 = trees[i-1].second;
		int x2 = trees[i].first;
		int h2 = trees[i].second;
		int x3 = trees[i+1].first;
		amount[i] = amount[i-1];
		if (x1 + h1 < x2 - h2 || (x1 < x2 - h2 && !r[i-1]))
			amount[i]++;
		else if (x2 + h2 < x3) {
			amount[i]++;
			r[i] = true;
		}

	}
	cout << amount[n-2] + 1;
}