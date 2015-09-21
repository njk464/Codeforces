#include <iostream>
#include <string>
#include <set>
#include <map>
#include <list>
#include <utility> // for pair
#include <limits>
#include <iterator>
#include <vector>
using namespace std;
void dijkstra (int start, int stop);
map<int, vector<pair<int, int> > > adjacency_list;
int* dist;
int* p;
bool* seen;
int v, e;
int main() {
	cin >> v >> e;
	dist = new int[v];
	p = new int[v];
	seen = new bool[v];
	for (int i = 0; i < v; i++) {
		p[i] = -1;
		dist[i] = 1e32;
		seen[i] = false;
	}
	// cout << dist[0] << "\n";
	dist[0]= 0;
	for (int i = 0; i < e; i++)
	{
		int start, stop, weight;
		cin >> start >> stop >> weight;
		adjacency_list[start-1].push_back(pair<int, int> (stop -1, weight));
		adjacency_list[stop-1].push_back(pair<int, int> (start -1, weight));
	}
	dijkstra(0, v-1);
	// if (v == 100000) {
	// 	int i = v-1;
	// 	while ( p[i] == -1) i--;
	// 	cout << i << ": " << dist[i] << "\n";
	// 	cout << i+1 << ": " << dist[i+1] << "\n";
	// }
	// adjacency_list.clear();
	int top = p[v-1];
	if (top == -1)
	{
		cout << -1;
		return 0;
	}
	list<int> l;
	l.push_front(v);
	l.push_front(top+1);
	while (p[top] != -1)
	{
		top = p[top];
		l.push_front(top+1);
	}
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
	delete[] dist;
	delete[] p;
	delete[] seen;
	return 0;
}
void dijkstra (int start, int stop) {
	set<pair<int, int> > d;
	d.insert(make_pair(0,start));
	while (!d.empty()) {
		int weight = d.begin()->first;
		int n = d.begin()->second;
		if (n == stop){
			return;
		}
		d.erase(*d.begin());
		seen[n] = true;
		vector<pair<int, int> >::iterator i = adjacency_list[n].begin();
		for (i; i != adjacency_list[n].end(); ++i)
		{
			int next = i->first;
			int w = i->second;
			// adjacency_list[n].pop_back();
			int temp = weight + w;
			if (!seen[next] && temp < dist[next])
			{
				d.erase(pair<int, int>(dist[next], next));
				// if (v == 100000 && d.size() != 0) {
				// 	cout << d.size() << " ";
				// }
				// cout << d.size();
				dist[next] = temp;
				p[next] = n;
				d.insert(pair<int, int>(temp, next));
			}
		}
		adjacency_list[n].clear();
	}
}

