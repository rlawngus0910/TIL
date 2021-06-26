#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int, int>;
int n, m, s, t;
int ans = 1e9;
int dist[5001];
vector <pair<pair<int, int>, int>> v;
vector <pair<int,int>> g[5001];

void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[s] = 0;
	pq.push({ dist[s],s });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int dst = cur.first, idx = cur.second;
		if (dist[idx] != dst) continue;
		for (auto nxt : g[idx]) {
			int cost = nxt.first, nidx = nxt.second;
			if (dist[nidx] > dst + cost) {
				dist[nidx] = dst + cost;
				pq.push({ dist[nidx], nidx });
			}
		}
	}

}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	fill(dist, dist + n + 1, 1e9);
	for (int i = 0,a,b,c; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}

	cin >> s >> t;

	for (int i = 0; i < m; i++) {
		int x = v[i].first.first;
		int y = v[i].first.second;
		int c = v[i].second;

		g[x].push_back({ c,y });
		g[y].push_back({ c,x });
	}

	dijkstra();

	cout << dist[t];
}