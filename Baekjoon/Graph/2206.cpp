#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
string map[1001];
queue<pair<pair<int, int>, int>> q;
int visit[1001][1001][2];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool isVaild(int x, int y) {
	return x > 0 && x <= n && y >= 0 && y < m;
}
int bfs(int x, int y, int cnt) {
	visit[x][y][cnt] = 1;
	q.push({ { x,y }, cnt });
	while (!q.empty()) {
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int bc = q.front().second;
		q.pop();
		if (cx == n && cy == m - 1) {
			return visit[cx][cy][bc];
		}
		for (int i = 0; i < 4; i++) {
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (isVaild(tx, ty)) {
				if (map[tx][ty] == '1' && bc == 1) {
					visit[tx][ty][0] = visit[cx][cy][bc] + 1;
					q.push({ {tx,ty},0 });
			
				}
				if (map[tx][ty] == '0' && visit[tx][ty][bc] == 0) {
					visit[tx][ty][bc] = visit[cx][cy][bc] + 1;
					q.push({ {tx,ty},bc });
				}
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}
	cout << bfs(1, 0, 1);

}