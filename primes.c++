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
int a, b, k;
int primes[10000000];
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
	cin >> a >> b >> k;
	if (is_prime(a))
		primes[0] = 1;
	for (int i = 1; i < b-a+1; i++) {
		primes[i] = primes[i-1];
		if (is_prime(a+i))
			primes[i]++;
	}
	int l = 1;
	int i = 0;
	if (primes[b-a] < k){
		cout << -1;
		return 0;
	}
	while (i <= b-a+1-l) {
		if ((i == 0 && primes[i+l-1] >= k) || primes[i+l-1] - primes[i-1] >= k)
			i++;
		else
			l++;
	}
	cout << l;
}