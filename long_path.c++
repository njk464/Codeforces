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
long long int n;
long long int nextr[1000];
long long int cross[1001];
int main() {
	cin >> n;
	for (long long int i = 0; i < n; i++)
	{
		cin >> nextr[i];
		nextr[i]--;
	}
	cross[0] = 0;
	for (long long int i = 1; i < n+1; i++) {
		cross[i] = (2*cross[i-1] + 2 - cross[nextr[i-1]]) % 1000000007;
		if (cross[i] < 0) {
			cross[i] += 1000000007;
		}
		// cout << i << ": " << cross[i] << "\n";
	}
	cout << cross[n];
}
// 2
// 1 2

// 1 1 2 2 3

// 1       0  
// 1 2     2 2*0 + 2 - 0
//   2 3   4 2*2 + 2 - 2

// 4
// 1 1 2 3

// 1 1 2 1 1 2 3 2 1 1 2 3 4 3 2 1 1 2 3 4 5

// 1 1     0
// 2 2		2*0 + 2 - 0
// 3 6		2*2 + 2 - 0
// 4 12	2*6 + 2 - 2
// 5 20	2*12 + 2 - 6