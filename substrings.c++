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
string s;
int sub[100000];
int A[26];
vector<int> like[26];
int main() {
	for (int i = 0; i < 26; i++)
		cin >> A[i];
	cin >> s;
	sub[0] = 0;
	like[s[0]-'a'].push_back(1);
	for (int i = 1; i < s.size(); i++) {
		sub[i] = A[s[i-1] - 'a'];
		sub[i] += sub[i-1];
		like[s[i]-'a'].push_back(i+1);
	}
	int which = 0;
  	for (int i = 0; i < 26; i++) {
    	map<ll, int> num_sums;
    	for (int i = 0; i < pos[c].size(); i++) {
      		ways += num_sums[sumf[pos[c][i] - 1]];
      		num_sums[sumf[pos[c][i]]]++;
    	}
    	num_sums.clear();
  	}

  cout << ways << endl;
}