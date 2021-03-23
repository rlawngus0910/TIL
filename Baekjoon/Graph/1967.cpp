#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n,ans;
vector <pair<int,int>> v[10001];
queue <pair<int, int>> q;
bool visit[10001];
void bfs(int start){
	visit[start] = true;
	q.push({ start, 0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();
		ans = max(ans, dist);
		
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i].first;
			int nxtDist = v[cur][i].second;
			if (!visit[nxt]) {
				visit[nxt] = true;
				q.push({ nxt,dist + nxtDist });
			}
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({ y,z });
		v[y].push_back({ x,z });
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		bfs(i);
	}
	cout << ans;
}
