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

int main() {
	long long int n, m, k;
	cin >> n;
	cin >> m;
	cin >> k;
	long long int bot = 0;
	long long int top = n*m +1;
	long long int mid = 0;
	while (bot + 1 < top) {
		mid = (bot + top)/2;
		long long int cnt = 0;
		for (long long int i = 0; i < n; i++) {
			if (m*(i+1) <= mid)
				cnt += m;
			else
				cnt += mid/(i+1);
		}
		if (cnt >= k)
			top = mid;
		else
			bot = mid;
	}
	cout << top;
}
