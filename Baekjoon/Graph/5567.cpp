#include <iostream>
#include <queue>
using namespace std;
int n, m, ans;
vector <int> v[501];
bool visit[501];
bool fri[501];
bool done[501];
void bfs() {
	queue <int> q;
	visit[1] = true;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (done[cur]) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			if (!visit[v[cur][i]]) {
				if (cur == 1) {
					ans++;
					fri[v[cur][i]] = true;
				}
				if (fri[cur] == true) {
					done[v[cur][i]] = true;
					ans++;
				}
				q.push(v[cur][i]);
				visit[v[cur][i]] = true;
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0,x,y; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	bfs();
	cout << ans;
}