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
bool matrix[100][100];
vector< pair<int, int> > intervals;
string output;
bool connect(int i, int j) {
	if (matrix[i][j])
		return true;
	int a = intervals[i].first;
	int b = intervals[i].second;
	int c = intervals[j].first;
	int d = intervals[j].second;
	if ((c < a && a < d) || (c < b && b < d))
	{
		matrix[i][j] = true;
		return true;
	}
	return false;
}
void test (int x, int y, int t) {
	for (int k = 0; k < t; k++) {
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < t; j++) {
				if (connect(i, k) && connect (k, j)) {
					matrix[i][j] = true;
				}
			}
		}
	}
	if (matrix[x][y])
		output += "YES\n";
	else
		output += "NO\n";
}
void print_it(int t) {
	cout << "\n";
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {
	cin >> n;
	int t = 0;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			intervals.push_back(make_pair(y,z));
			t++;
		}
		else if (x == 2) {
			test(y-1,z-1,t);
			// print_it(t);
		}
	}
	cout << output;
}
