#include <stdio.h>
#include <stdlib.h> 
#include <map>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;
vector< pair<long long int, long long int> > next(long long int row, long long int front, long long int back) {
    vector< pair<long long int, long long int> > pairs;
    long long int curf = front;
    long long int curb = front;
    while (curb != back){
        if (fences[curb] > row) {
            pairs.push_back(make_pair(curf, curb));
            while (fences[curb] > row && curb != back) {
                curb++;
            }
            curf = curb;
            curb--;
        }
        curb++;
    }
    return pairs;
}
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
    if (min > fences.size()) {
        cout << fences.size();
        return 0;
    }
    if (max < fences.size()) {
        cout << max
    }
    vector<long long int> strokes;
    for (int i = 0; i < min; i++) {
        strokes.push_back(i+1);
    }
    int i = min;
    int front = 0;
    int back = fences.size() - 1;
    while (strokes.size() != max) {
        
    }


}
**      **
****  ****
****  ****
**********
**********