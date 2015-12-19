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
int n, a, b, c;
vector<int> max_cuts;
bool good(int i) {
	if (max_cuts[i] != 0 || i == a || i == b || i == c || i == 0)
		return true;
	return false;
}
int maximum(int i) {
	int ma = 0;
	if (i >= c && good(i-c))
		ma = max(ma, max_cuts[c] + max_cuts[i-c]);
	if (i >= b && good(i-b))
		ma = max(ma, max_cuts[b] + max_cuts[i-b]);
	if (i >= a && good(i-a))
		ma = max(ma, max_cuts[a] + max_cuts[i-a]);
	return ma;
}
int main() {
	cin >> n >> a >> b >> c;
	int i = 1;
	max_cuts = vector<int>(n+1,0);
	if (a <= n)
		max_cuts[a] = 1;
	if (b <= n)
		max_cuts[b] = 1;
	if (c <= n)
		max_cuts[c] = 1;
	while (i <= n)
	{
		max_cuts[i] = maximum(i);
		i++;
	}
	// i = 0;
	// while (i <= n)
	// {
	// 	cout << i << ": "<< max_cuts[i] << "\n";
	// 	i++;
	// }
	cout << max_cuts[n];

}
