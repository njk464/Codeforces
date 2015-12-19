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
char rf[1000][1000];
char rt[1000][1000];
int t[1000][1000];
int f[1000][1000];

int twos(int t) {
	if (t == 0) return 0;
	int count = 0;
	while( t % 2 == 0)
	{
		count++;
		t /= 2;
	}
	return count;
}
int fives(int t) {
	if (t == 0) return 0;
	int count = 0;
	while( t % 5 == 0)
	{
		count++;
		t /= 5;
	}
	return count;
}
string patht(int a, int b) {
	if (rt[a][b] == 'N')
		return "";
	if (rt[a][b] == 'R')
		return patht(a, b-1) + "R";
	return patht(a-1,b) + "D";
}
string pathf(int a, int b) {
	if (rf[a][b] == 'N')
		return "";
	if (rf[a][b] == 'R')
		return pathf(a, b-1) + "R";
	return pathf(a-1,b) + "D";
}
void bestt(int i, int j) {
	if (i == 0 && j == 0) {
		rt[i][j] = 'N';
		return;
	}
	if (i == 0)
	{
		t[i][j] += t[i][j-1];
		rt[i][j] = 'R';
		return;
	}
	if (j == 0)
	{
		t[i][j] += t[i-1][j];
		rt[i][j] = 'D';
		return;
	}
	if (t[i-1][j] < t[i][j-1]) {
		t[i][j] += t[i-1][j];
		rt[i][j] = 'D';
	}
	else {
		t[i][j] += t[i][j-1];
		rt[i][j] = 'R';
	}
}
void bestf(int i, int j) {
	if (i == 0 && j == 0) {
		rf[i][j] = 'N';
		return;
	}
	if (i == 0)
	{
		f[i][j] += f[i][j-1];
		rf[i][j] = 'R';
		return;
	}
	if (j == 0)
	{
		f[i][j] += f[i-1][j];
		rf[i][j] = 'D';
		return;
	}
	if (f[i-1][j] < f[i][j-1]) {
		f[i][j] += f[i-1][j];
		rf[i][j] = 'D';
	}
	else {
		f[i][j] += f[i][j-1];
		rf[i][j] = 'R';
	}
}
int main() {
	cin >> n;
	int zx = 0;
	bool z = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int next;
			cin >> next;
			t[i][j] = twos(next);
			f[i][j] = fives(next);
			if (next == 0) {
				zx = i;
				z = true;
			}
		}
	}
	// cout << zx << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bestt(i,j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bestf(i,j);
		}
	}
	int l = min(t[n-1][n-1], f[n-1][n-1]);
	if (z && 1 < l)
	{
		cout << "1\n";
		for (int i = 0; i < zx; i++) 
			cout << "D";
		for (int i = 0; i < n-1; i++) 
			cout << "R";
		for (int i = 0; i < n-zx-1; i++) 
			cout << "D";
		return 0;
	}
	if (t[n-1][n-1] < f[n-1][n-1]) {
		cout << t[n-1][n-1] << "\n";
		cout << patht(n-1, n-1);
	}
	else
	{
		cout << f[n-1][n-1] << "\n";
		cout << pathf(n-1, n-1);	
	}

}