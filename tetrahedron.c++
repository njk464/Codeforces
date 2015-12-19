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
// vector<long long int> D;
// vector<long long int> A;
int main() {
	cin >> n;
	// D.push_back(0);
	// D.push_back(0);
	// D.push_back(3);
	// A.push_back(0);
	// A.push_back(1);
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	if (n == 2)
	{
		cout << 3;
		return 0;
	}
	long long int D2 = 0;
	long long int A2 = 0;
	long long int D1 = 3;
	long long int A1 = 1;
	long long int A, D;
	for (int i = 3; i <= n; i++)
	{
		A = (2*A1 + D2)%1000000007;
		D = (A*3)%1000000007;
		A1 = A;
		D2 = D1;
		D1 = D;
	}
	cout << D%1000000007;
}
// D 0:0
// D 1:0
// A 0:0
// D 2:3
// A 1:1
// D 3:6
// A 2:2
// D 4:21
// A 3:7 = 2*A[2] + D[2] 