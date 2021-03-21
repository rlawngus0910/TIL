#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, r,ans;
int item[101];
int dist[101] = { 0, };
vector <pair<int, int>>v[101];
void dijkstra(int start) {
	int temp = 0;
	fill(dist, dist + n + 1, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater <pair<int, int>> > pq;
	dist[start] = 0;
	pq.push({ dist[start], start });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		int di = cur.first;
		int idx = cur.second;
		if (dist[idx] != di) continue;
		for (auto nxt : v[idx]) {
			int cost = nxt.first;
			int nidx = nxt.second;
			if (dist[nidx] > di + cost) {
				dist[nidx] = di + cost;
				pq.push({ dist[nidx], nidx });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == 0 && i != start) continue;
		if (dist[i] <= m) temp += item[i];
	}
	ans = max(ans, temp);
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> item[i];
	for (int i = 1,s,f,d; i <= r; i++) {
		cin >> s >> f >> d;
		v[s].push_back({ d,f });
		v[f].push_back({ d,s });
	}
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	cout << ans;
}