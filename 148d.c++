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
double m[1001][1001][3];
double dragon(double w, double b);
double lose(double w, double b);
double princess(double w, double b) {
	if (w == 0)
		return 0;
	if (b == 0)
		return 1;
	if (m[(int)w][(int)b][0] == 0)
		m[(int)w][(int)b][0] = w/(w+b) + b/(w+b)*dragon(w,b-1);
	return m[(int)w][(int)b][0];
}
double dragon(double w, double b) {
	if (w == 0)
		return 0;
	if (b == 0)
		return 0;
	if (m[(int)w][(int)b][1] == 0)
		m[(int)w][(int)b][1] = b/(w+b)*lose(w,b-1);
	return m[(int)w][(int)b][1];
}
double lose(double w, double b) {
	if (w == 0)
		return 1;
	if (b == 0)
		return 1;
	if (m[(int)w][(int)b][2] == 0)
		m[(int)w][(int)b][2] = w/(w+b)*princess(w-1,b) + b/(w+b)*princess(w,b-1);
	return m[(int)w][(int)b][2];
}
int main() {
	double w, b;
	// memset(m, 0, 1001*1001*3*sizeof(m[0][0][0]));
	cin >> w >> b;
	cout << setprecision(9) << princess(w,b);

}