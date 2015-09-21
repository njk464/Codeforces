#include <iostream>
#include <string>
#include <set>
#include <map>
#include <list>
#include <utility> // for pair
#include <limits>
#include <iterator>
using namespace std;
struct node {
	int data;
	int weight;
	node (int d, int w) {
		data = d;
		weight = w;
	}
};
void cities (int start, int di);
int roads(int di);
map<int, list<pair<int, int> > > adjacency_list;
int* dist;
int v, e, c;
int main() {
	cin >> v >> e >> c;
	dist = new int[v];
	for (int i = 0; i < v; i++) {
		dist[i] = 1 << 30;
	}
	for (int i = 0; i < e; i++)
	{
		int start, stop, weight;
		cin >> start >> stop >> weight;
		adjacency_list[start-1].push_back(pair<int, int> (stop -1, weight));
		adjacency_list[stop-1].push_back(pair<int, int> (start -1, weight));
	}
	int d;
	dist[c-1]= 0;
	cin >> d;
	if (d == 0) {
		cout << 1;
		return 0;
	}
	// cout << 3/2 <<"\n";
	cities(c-1, d);
	cout << roads(d);

}
void cities (int start, int di) {
	set<pair<int, int> > d;
	d.insert(make_pair(0, start));
	while (!d.empty()) {
		int distance = d.begin()->first;
		int n = d.begin()->second;
		d.erase(*(d.begin()));
		list<pair<int, int> >::iterator i = adjacency_list[n].begin();
		for (i; i != adjacency_list[n].end(); i++) {
			int next = i->first;
			int w = i->second;
			int temp = distance + w;
			if (temp < dist[next])
			{
				d.erase(make_pair(dist[next], next));
				// cout << d.size() << "\n";
				dist[next] = temp;
				d.insert(make_pair(dist[next], next));
			}
		}
	}
}
int roads (int di) {
	int count = 0;
	for ( int n = 0; n < v; n++) {
		if (dist[n] == di)
			count++;
		list<pair<int, int> >::iterator i = adjacency_list[n].begin();
		for (i; i != adjacency_list[n].end(); i++) {
			int next = i->first;
			int w = i->second;
			if (n < next)
				continue;
			int low = min(dist[n], dist[next]);
			int high = max(dist[n], dist[next]);
			if (di <= low)
				continue;
			if (di < high) {
				count++;
				continue;
			}
			if (di == high) {
				if (low + w != high)
					count++;
				continue;
			}
			if ( low + high + w == 2 * di){
				count++;
				continue;
			}
			if (low + high + w > 2 * di) {
				count += 2;
			}
		}
	}
	return count;
}