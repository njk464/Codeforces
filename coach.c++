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
int n, m;
map<int, vector<int> > pairs;
set<int> students;
bool matrix[48][48];
int connections[48];
vector<int> c[48];
int main() {
	cin >> n >> m;
	for (int i = 0; i < 48; i++)
	{
		for (int j = 0; j < 48; j++)
		{
			matrix[i][j] = false;
		}
		matrix[i][i] = true;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		matrix[a-1][b-1] = true;
		matrix[b-1][a-1] = true;
		connections[a-1]++;
		connections[b-1]++;
		c[a-1].push_back(b-1);
		c[b-1].push_back(a-1);
		if (connections[a-1] > 2 || connections[b-1] > 2)
		{
			cout << -1;
			return 0;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][k] && matrix[k][j] && !matrix[i][j]) {
					connections[i]++;
					connections[j]++;
					if (connections[i] > 2 || connections[j] > 2){
						cout << -1;
						return 0;
					}
					matrix[i][j] = true;
					matrix[j][i] = true;
					c[i].push_back(j);
					c[j].push_back(i);
				}
			}
		}
	}
	vector<pair<int, int> > duple;
	vector<int> single;
	string s;
	for (int i = 0; i < n; i++) {
		// cout << connections[i];
		students.insert(i);
	}
	while (!students.empty()) {
		int top = *(students.begin());
		students.erase(top);
		if (connections[top] == 2) {
			students.erase(c[top][0]);
			students.erase(c[top][1]);
			// cout << "triple";
			s += to_string(top+1) + " " + to_string(c[top][0] + 1) + " " + to_string(c[top][1] + 1) + "\n";
		}
		if (connections[top] == 1)
		{
			students.erase(c[top][0]);
			// cout << "double:"<< top+1 << " " << c[top][0]+1 << "\n";
			duple.push_back(make_pair(top+1, c[top][0]+1));
		}
		if (connections[top] == 0)
		{
			// cout << "single:"<< top+1 << "\n";
			single.push_back(top+1);
		}
	}
	int i = 0;
	int j = 0;
	while (i < duple.size() || j < single.size()) {
		if (duple.size() > i && single.size() > j) {
			// cout << "there";
			s += to_string(duple[i].first) + " " + to_string(duple[i].second) + " " + to_string(single[j]) + "\n";
			i++;
			j++;
		}
		else if (single.size() > j+2) {
			// cout << "here";
			s +=  to_string(single[j++]) + " " + to_string(single[j++]) + " " + to_string(single[j++]) + "\n";
		}
		else {
			cout << -1;
			return 0;
		}
	}
	cout << s;
	return 0;
}