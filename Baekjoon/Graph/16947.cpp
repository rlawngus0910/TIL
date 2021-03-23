#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n;
vector <int> v[3001];
bool visit[3001];
bool cycle[3001];
void dfs(int start, int cur, int cnt) {
	if (cur == start && cnt >= 2) {
		cycle[cur] = true;
		return;
	}
	visit[cur] = true;
	for (auto nxt : v[cur]) {
		if (!visit[nxt]) {
			dfs(start, nxt, cnt + 1);
		}
		else {
			if (start == nxt && cnt >= 2) dfs(start, nxt, cnt);
		}
	}
}
int bfs(int idx) {
	if (cycle[idx]) return 0;
	queue <pair<int,int>> q;
	visit[idx] = true;
	q.push({ idx,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();
		for (auto nxt : v[cur]) {
			if (cycle[nxt]) return dist + 1;
			if (!visit[nxt]) {
				visit[nxt] = true;
				q.push({ nxt, dist + 1 });
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0,x,y; i < n; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, i, 0);
		memset(visit, false, sizeof(visit));
	}
	for (int i = 1; i <= n; i++) {
		cout << bfs(i) << ' ';
		memset(visit, false, sizeof(visit));
	}
}