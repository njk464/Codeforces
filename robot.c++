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
vector<bool> visit;
string s;
void reverse()
{
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'L')
			s[i] = 'R';
		else
			s[i] = 'L';
	}
}
void reset()
{
	for (int i = 0; i < visit.size(); i++) {
		visit[i] = false;
	}
}
bool valid(int right) {
	reset();
	int rob = s.length();
	visit[rob] = true;
	// cout << "new\n";
	for (int i = 0; i < s.length(); i++) {
		// cout << rob << "\n";
		if (s[i] == 'L')
			rob--;
		else if (rob + 1 != right + s.length())
			rob++;
		if (i == s.length()-1)
			return !visit[rob];
		visit[rob] = true;
	}
	return true;

}
int main() {
	cin >> s;
	visit = vector<bool>(s.length()*2, false);
	if (valid(visit.size()))
	{
		cout << 1;
		return 0;
	}
	if (s[s.length() - 1] == 'R')
		reverse();
	int low = 0;
	int high = visit.size();
	while (low + 1 < high) {
		int mid = low + (high - low) / 2;
		if (valid(mid))
			low = mid;
		else
			high = mid;
		// cout << "high=" << high <<"\n";
	}
	cout << low;
}

