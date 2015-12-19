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
int n, k;
vector<int> primes;
bool is_prime(int l) {
	int root = ceil(sqrt(l));
	if (l == 2 || l == 3)
		return true;
	if (l % 2 == 0 || l == 1)
		return false;
	for (int i = 3; i <= root; i+=2) {
		if (l%i == 0)
			return false;
	}
	return true;
}
int main() {
	cin >> n >> k;
	if (k == 0 && n == 1) {
		cout << 1;
		return 0;
	}
	if (k < n/2 || n < 2) {
		cout << -1;
		return 0;
	}
	int i = 3;
	primes.push_back(2);
	while (primes.size() < n) {
		if (is_prime(i))
			primes.push_back(i);
		i++;
	}
	int gcd = k - (n/2) + 1;
	if (gcd == 1)
		cout << primes[n-2] << " " << primes[n-1];
	else
		cout << gcd*3 << " " << gcd*2;
	for (int i = 0; i < n-2; i++) {
		cout << " " << primes[i];
	}
}