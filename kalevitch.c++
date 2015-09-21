#include <iostream>
#include <string>
#include <set>
#include <map>
#include <list>
#include <utility> // for pair
#include <limits>
#include <iterator>
#include <vector>
#include <string>
using namespace std;
char grid[8][8];
int main() {
	int strokes = 0;
	for(int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		bool row = true;
		for (int k = 0; k < 8; k++) {
			grid[i][k] = s[k];
			if (s[k] != 'B')
				row = false;
		}
		if (row)
			strokes++;
	}
	if (strokes == 8) {
		cout << 8;
		return 0;
	}
	for (int i = 0; i < 8; i++){
		bool col = true;
		for (int k = 0; k < 8; k++) {
			if (grid[k][i] != 'B') {
				col = false;
				break;
			}
		}
		if (col)
			strokes++;
	}
	cout << strokes;

}
