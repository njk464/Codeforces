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
	int n, k;
	cin >> n;
	cin >> k;
	if (k > n)
	{
		cout << n;
		return 0;
	}
	// cout << pow(k,1);
	int min = 1;
	int max = n;
	int v = 0;
	int sum = 0;
	while ((min - max) / 2 != 0) {
		v = (min + max) / 2;
		sum = v;
		// cout << v <<"\n";
		int i = 1;
		while(sum < n) {
			if (floor(v/pow(k,i)) == 0)
				break;
			sum += floor(v/pow(k,i));
			i++;
		}
		if (sum >= n)
		{
			max = v;
		}
		else {
			min = v;
		}
	}
	if (sum >= n){
		// cout << "here\n";
		cout << v;
	}
	else{
		// cout << "there\n";
		cout << v+1;
	}
}
