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
using namespace std;
long long int grid[8][3];
long long int temp[8][3];
long long int x[] = {0,0,1,1,2,2};
long long int y[] = {1,2,0,2,1,0};
long long int z[] = {2,1,2,0,0,1};
long long int square(long long int a, long long int b) {
	return (a-b)*(a-b);
}
long long int distance(long long int i, long long int k) {
	return square(temp[i][0], temp[k][0]) + square(temp[i][1], temp[k][1]) + square(temp[i][2], temp[k][2]);
}
void print_cube() {
	for (long long int i = 0; i < 8; i++) {
		cout << temp[i][0] << " ";
		cout << temp[i][1] << " ";
		cout << temp[i][2] << "\n";
	}
}
void is_cube() {
	map<long long int, int> mapping;
	for (long long int i = 0; i < 8; i++)
	{
		for (long long int k = i+1; k < 8; k++) {
			long long int d = distance(i,k);
			if (d == 0)
				return;
			mapping[d]++;
			if (mapping.size() > 3 || mapping[d] > 12)
				return;
		}
	}
	if (mapping.size() != 3)
		return;
	map<long long int, int>::iterator it = mapping.begin();
	if(it->second != 12)
		return;
	it++;
	if(it->second != 12)
		return;
	it++;
	if(it->second != 4)
		return;
	cout << "YES\n";
	print_cube();
	exit(0);
	return;

}
void recur_try2(long long int coor) {
	if (coor >= 8)
		return;
	for (int i=0; i < 6; i++) {
		temp[coor][0] = grid[coor][x[i]];
		temp[coor][1] = grid[coor][y[i]];
		temp[coor][2] = grid[coor][z[i]];
		// print_cube();
		// cout <<"\n";
		is_cube();
		recur_try2(coor+1);
	}

}
int main() {
	for (long long int i = 0; i < 8; i++) {
		cin >> grid[i][0];
		temp[i][0] = grid[i][0];
		cin >> grid[i][1];
		temp[i][1] = grid[i][1];
		cin >> grid[i][2];
		temp[i][2] = grid[i][2];
	}
	// cout << (-337 +193088)*(-337 +193088) +(577079 +683216)*(577079 +683216) + (887691+342950)*(887691+342950)<<"\n";
	// cout << "\n" << distance(0,1) << "\n";
	is_cube();
	recur_try2(0);
	cout << "NO";
}
