#include <stdio.h>
#include <stdlib.h> 
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;
vector<long long int> fences;
//method is working
struct chunk {
    long long int max;
    long long int min;
    long long int left;
    long long int right;
    chunk (long long int m, long long int mi, long long int l, long long int r): max(m), min(mi), left(l), right(r) {}
};
vector<chunk> next(long long int row, long long int front, long long int back) {
    vector<chunk> chunks;
    long long int curf = front;
    long long int curb = front;
    while (fences[curb] < row) {
        curb++;
    }
    curf = curb;
    long long int maxl = numeric_limits<long long int>::min();
    long long int minl = numeric_limits<long long int>::max();
    while (curb < back){
        if (fences[curb] < row) {
            chunks.push_back(chunk(maxl, minl, curf, curb));
            // cout << "(" << curf << ", " << curb << ") max = " << maxl << " min = " << minl << "\n";
            while (curb < back && fences[curb] < row) {
                curb++;
            }
            minl = numeric_limits<long long int>::max();
            maxl = numeric_limits<long long int>::min();
            curf = curb;
            curb--;
        }
        minl = min(fences[curb], minl);
        maxl = max(fences[curb], maxl);
        curb++;
    }
    if (curf != curb)
        chunks.push_back(chunk(maxl, minl, curf, curb));
    return chunks;
}
long long int strokes(long long int height, long long int left, long long int right) {
    vector<chunk> chunks = next(height, left, right);
    // cout << "check\n";
    long long int s = 0;
    // cout << chunks.size();
    for (int i = 0; i < chunks.size(); i++) {
        // cout << "(" << chunks[i].left << ", " << chunks[i].right << ") max = " << chunks[i].max << " min = " << chunks[i].min << "\n";
        if (chunks[i].right - chunks[i].left == 1) {
            // cout << "This one\n";
            s += 1;
        }
        else if (chunks[i].max == chunks[i].min)
            s += min(chunks[i].max-height+1, chunks[i].right - chunks[i].left);
        else
            s += min(chunks[i].right - chunks[i].left, chunks[i].min - height + 1 + strokes(chunks[i].min + 1, chunks[i].left, chunks[i].right));
        if (s >= right - left) {
            return right - left;
        }
    }
    s = min(s, right - left);
    return s;
}
int main(void) 
{
    long long int n;
    long long int minl = numeric_limits<long long int>::max();
    long long int maxl = numeric_limits<long long int>::min();
    cin >> n;
    // cout << "before\n";
    for (long long int i = 0; i < n; i++) {
        long long int c;
        cin >> c;
        maxl = max(c, maxl);
        minl = min(c, minl);
        fences.push_back(c);
    }
    // cout << "after\n";
    // vector<chunk> chunks = next(minl + 1, 0, n);
    // for (int i = 0; i < chunks.size(); i++) {
    //     cout << "(" << chunks[i].left << ", " << chunks[i].right << ") max = " << chunks[i].max << " min = " << chunks[i].min << "\n";
    // }
    if (maxl == minl) {
        cout << min(n, minl);
        // cout << "first\n";
        return 0;
    }
    if (minl > n) {
        cout << n;
        // cout << "second\n";
        return 0;
    }
    // if (maxl < n) {
    //     cout << maxl;
    //     cout << "third\n";
    //     return 0;
    // }
    cout << min(strokes(minl + 1, 0, n) + minl, n);
}