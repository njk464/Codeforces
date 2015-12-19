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
vector<long long int> nums;
long long int similar(long long int k){
	if (k % 2 == 0)
		return similar(k/2);
	if (k % 3 == 0)
		return similar(k/3);
	return k;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long int next;
		cin >> next;
		nums.push_back(next);
	}
	long long int cur = similar(nums[0]);
	for (int i = 1; i < n; i++) {
		if (cur != similar(nums[i]))
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}