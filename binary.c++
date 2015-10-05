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
long long int groups = 0;
long long int space = 0;
long long int cnt = 0;
void binToDec(string bin) {
	//11011
	if (bin[bin.length() - 1] == '1')
		cnt++;
	// cout << cnt << "\n";
	if (bin[bin.length() -1] == '1')
		groups++;
	for (int i = bin.length() -1; i > 0; i--)
	{
		// cout << dec;
		if (bin[i -1] == '1')
			cnt++;
		if (bin[i-1] == '1' && bin[i] == '0')
			groups++;
		if (bin[i-1] == '0' && bin[i] == '0' && cnt >= 1)
			space++;
	}
	// cout << cnt <<"\n";
}
int main() {
	string bin;
	long long int num;
	cin >> bin;
	if (bin == "1")
	{
		cout << 0;
		return 0;
	}
	binToDec(bin);
	if (cnt == 1)
		cout << bin.length() - 1;
	else
		cout << bin.length() + groups + space;
}

