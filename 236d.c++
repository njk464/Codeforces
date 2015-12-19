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
#include <stdio.h>
#include <memory.h>
#include <iomanip>      // std::setprecision
using namespace std;
double prob[100000];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> prob[i];
	}
	double total = 0;
	double prev = 0;
	for (int i = 0; i < n; i++) {
		total += prev * prob[i]*2 + prob[i];
		prev = prev*prob[i]+prob[i];
	}
	cout << setprecision(20) << total;
}