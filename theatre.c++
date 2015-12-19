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
long long n, m, k;
long long fact_div (long long a, long long b) {
	if (b > a)
		return 0;
	long long here = 1;
	int small = min(b, a-b);
	for (int i = 1; i <= small; i++)
	{
		here *= a--;
		here /= i;
	}
	return here;
}
int main() {
	cin >> n >> m >> k;
	long long ways = 0;
	for (long long i = 4; i <= k-1; i++) {
		ways += fact_div(n,i) * fact_div(m,k-i);
	}
	cout << ways;
}


