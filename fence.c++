#include <stdio.h>
#include <stdlib.h> 
#include <map>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;
int main(void) 
{
	vector<long long int> fences;
    long long int n;
    long long int min = numeric_limits<long long int>::max();
    long long int max = numeric_limits<long long int>::min();
    cin >> n;
    for (long long int i = 0; i < n; i++) {
        long long int c;
        cin >> c;
        max = max(c, max);
        min = min(c, min);
        fences.push_back(c);
    }
    if (max == min) {
        cout << min(fences.size(), min);
        return 0;
    }
    

}