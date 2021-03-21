#include <iostream>
#include <queue>
using namespace std;
vector <pair<int, int>> adj[20001];
int dist[20001];
int v, e, st;
const int INF = 6e9 + 10;
void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater <pair<int, int>>> pq;
	fill(dist, dist + v + 1, INF);
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int di = cur.first;
		int idx = cur.second;
		if (dist[idx] != di) continue;
		for (auto nxt : adj[idx]) {
			int cost = nxt.first;
			int nIdx = nxt.second;
			if (dist[nIdx] > cost + di) {
				dist[nIdx] = cost + di;
				pq.push({ dist[nIdx],nIdx });
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> st;
	for (int i = 0,s,f,d; i < e; i++) {
		cin >> s >> f >> d;
		adj[s].push_back({ d,f });
	}
	dijkstra(st);
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout <<  dist[i] << '\n';
	}
}