#include <iostream>
#include <queue>
using namespace std;
int n;
vector <int> v[100001];
bool visit[100001];
int ans[100001];
void bfs(int x) {
	visit[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			if (!visit[v[cur][i]]) {
				visit[v[cur][i]] = true;
				ans[v[cur][i]] = cur;
				q.push(v[cur][i]);
			}
		}
	}
	for (int i = 2; i <= n; i++) cout << ans[i] << '\n';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(1);
}