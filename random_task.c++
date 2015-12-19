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
unsigned long long m;
int k;
unsigned long long A[65][65];
unsigned long long fact_div (unsigned long long a, unsigned long long b) {
	if (b > a)
		return 0;
	unsigned long long here = 1;
	int small = min(b, a-b);
	for (int i = 1; i <= small; i++)
	{
		here *= a--;
		here /= i;
	}
	return here;
}
int count_bits(unsigned long long c) {
	int bits = 0;
	while (c > 0) {
		bits++;
		c >>= 1;
	}
	return bits;
}
unsigned long long check(unsigned long long c, int k2, int bits) {
	unsigned long long count = 0;
	while(c > 0) {
		unsigned long long bm = 1ULL << (bits - 1);
		if (bm & c)  {
			if (k2 == 1) {
				count += bits;
				c = 0;
			}
			else
				count += A[bits-1][k2];
			k2--;
		}
		bm--;
		c &= bm;
		bits--;
	}
	return count;
}
void fill() {
	for (int i = 0; i <= 64; i++) {
		for (int j = 0; j <= i; j++) {
			A[i][j] = fact_div(i,j);
		}
	}
}
int main() {
	cin >> m >> k;
	fill();
	unsigned long long bot = 1;
	unsigned long long top = 1000000000000000000;
	while (bot <= top) {
		unsigned long long mid = (top+bot)/2;
		unsigned long long count = 0;
		count = check(mid*2, k, count_bits(mid*2)) - check(mid, k, count_bits(mid));
		if (count > m){
			top = mid-1;
		}
		else if (count < m){
			bot = mid+1;
		}
		else {
			cout << mid;
			return 0;
		}
	}
}