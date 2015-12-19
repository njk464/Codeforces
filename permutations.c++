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
int n, k, small = 100000000;
int nums[8][8];
int nums2[8][8];
int temp[8];
void smallest() {
	for (int i = 0; i < n; i++) {
		temp[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
		{
			temp[i] *= 10;
			temp[i] += nums2[i][j];
		}
	}
	int minn = temp[0];
	int maxx = temp[0];
	// cout << "nums: " << temp[0];
	for (int i = 1; i < n; i++) {
		// cout << ", " << temp[1];
		if (temp[i] < minn) {
			minn = temp[i];
		}
		if (temp[i] > maxx) {
			maxx = temp[i];
		}
	}
	// cout << "\n";
	if (small > maxx-minn)
		small = maxx-minn;
}
void permutations(list<int> ways, int spot) {
	if (ways.empty())
		return;
	list<int>::iterator its = ways.begin();
	for (; its != ways.end(); its++) {
		int sw = *its;
		for (int i = 0; i < n; i++) {
			nums2[i][spot] = nums[i][sw];
		}
		// cout << "spot: " << spot << " switch: " << sw << "\n";
		if (spot == k-1)
			smallest();
		list<int> wow (ways);
		wow.remove(sw);
		// list<int>::iterator it = wow.begin();
		// cout << "ways " << *it;
		// it++;
		// for(; it != wow.end(); it++)
		// 	cout << ", " << *it;
		// cout << "\n";
		permutations (wow, spot+1);
	}
}
int main() {
	cin >> n >> k;
	list<int> ways;
	for (int i = 0; i < n; i++) {
		int next;
		cin >> next;
		for (int j = 0; j < k; j++) {
			nums[i][k-j-1] = next%10;
			nums2[i][k-j-1] = next%10;
			next/=10;
		}
	}
	for (int i = 0; i < k; i++) {
		ways.push_back(i);
	}
	// list<int>::iterator it = ways.begin();
	// cout << "ways " << *it;
	// it++;
	// for(; it != ways.end(); it++)
	// 	cout << ", " << *it;
	// cout << "\n";
	permutations(ways, 0);
	cout << small;
}


