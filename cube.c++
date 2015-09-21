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
	vector<long long int> lengths;
	for (long long int i = 0; i < 8; i++)
	{
		for (long long int k = i+1; k < 8; k++) {
			lengths.push_back(distance(i, k));
		}
	}
	// cout << lengths.size() <<"\n";
	if (lengths.size() != 28)
		return;
	sort (lengths.begin(), lengths.end());
	// for (long long int i = 0; i < 28; i++) {
	// 	cout << lengths[i] << " ";
	// }
	// cout << "\n";
	long long int min = lengths[0];
	for (long long int i = 1; i < 12; i++)
	{
		if (lengths[i] != min)
			return;
	}
	if (lengths[12] == min)
		return;
	min = lengths[12];
	for (long long int i = 12; i < 24; i++)
	{
		if (lengths[i] != min)
			return;
	}
	if (lengths[24] == min)
		return;
	min = lengths[24];
	for (long long int i = 24; i < 28; i++)
	{
		if (lengths[i] != min)
			return;
	}

	cout << "YES\n";
	print_cube();
	exit(0);
	return;

}
void recur_try2(int where, long long int coor, long long int x, long long int y, long long int z) {
	if (coor >= 8)
		return;
	temp[coor][0] = grid[coor][x];
	temp[coor][1] = grid[coor][y];
	temp[coor][2] = grid[coor][z];
	is_cube();
	recur_try2(0, ++coor, 0, 1, 2);
	switch (where){
		case 0: recur_try2(1, coor, 0, 2, 1);
		case 1: recur_try2(2, coor, 1, 0, 2);
		case 2: recur_try2(3, coor, 1, 2, 0);
		case 3: recur_try2(4, coor, 2, 1, 0);
		case 4: recur_try2(5, coor, 2, 0, 1);
		case 5: return;
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
	recur_try2(0, 0, 0, 1, 2);
	cout << "NO";
}
