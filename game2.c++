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
int part[200];
set<int> prev[200];
set<int> after[200];
int matrix[200][200];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> part[i];
	}
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j++) {
			int next;
			cin >> next;
			prev[i].insert(next-1);
			after[next-1].insert(i);
		}
	}
	
}