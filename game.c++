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
int main() {
	set<int> fun;
	int n;
	cin >> n;
	if ( n <= 3 )
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	if (!(n%2)){
		cout << "1 * 4 = 4\n";
		cout << "2 * 3 = 6\n";
		cout << "6 * 4 = 24\n";
		for (int i = 5; i < n; i+=2)
		{
			cout << i + 1 << " - " << i << " = 1\n";
			cout << "24 * 1 = 24\n";
		}
	}
	else {
		cout << "5 * 4 = 20\n";
		cout << "2 - 1 = 1\n";
		cout << "20 + 3 = 23\n";
		cout << "23 + 1 = 24\n";
		for (int i = 6; i < n; i+=2)
		{
			cout << i + 1 << " - " << i << " = 1\n";
			cout << "24 * 1 = 24\n";
		}
	}
}

/*4
1 * 4 = 4
2 * 3 = 6
6 * 4 = 24

6
1 * 4 = 4
2 * 3 = 6
6 * 4 = 24
6 - 5 = 1
24 * 1 = 24

5
1, 2, 3, 4, 5
5 * 4 = 20
2 - 1 = 1
20 + 3 = 23
23 + 1 = 24

7
1, 2, 3, 4, 5
5 * 4 = 20
2 - 1 = 1
20 + 3 = 23
23 + 1 = 24
7 - 6 = 1
24 * 1 = 24*/


