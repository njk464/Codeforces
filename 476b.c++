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
int actual = 0;
long double received[22];
long double temp[22];
void add_one() {
	for (int i = 1; i < 21; i++) {
		if (temp[i] >= 1) {
			received[i+1]+=temp[i];
			received[i]=0;
		}
	}
	memcpy(&temp, &received, 22*sizeof(long double));
}
void minus_one() {
	for (int i = 1; i < 21; i++) {
		if (temp[i] >= 1) {
			received[i-1]+=temp[i];
			received[i]=0;
		}
	}
	memcpy(&temp, &received, 22*sizeof(long double));
}
void split() {
	for (int i = 1; i < 21; i++) {
		if (temp[i] >= 1) {
			received[i+1]+=temp[i];
			received[i-1]+=temp[i];
			received[i]=0;
		}
	}
	memcpy(&temp, &received, 22*sizeof(long double));
}
long double sum() {
	long double count = 0;
	for (int i = 0; i < 22; i++) {
		count += received[i];
	}
	return count;
}
void print() {
	for (int i = 0; i < 22; i++) {
		cout << temp[i] << ", ";
	}
	cout << "\n";
}
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < 22; i++)
	{
		received[i] = 0;
		temp[i] = 0;
	}
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == '+')
			actual++;
		else
			actual--;
	}
	cin >> s;
	received[11] = 1;
	temp[11] = 1;
	// cout << actual << "\n";
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		// print();
		if (c == '+')
			add_one();
		else if (c == '-')
			minus_one();
		else
			split();
	}
	// print();
	// cout << received[actual+11] << "\n";
	// cout << sum() << "\n";
	// cout << 210.0/1024.1 << "\n";
	cout << setprecision(9) << received[actual+11]/sum();
}
