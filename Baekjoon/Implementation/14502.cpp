#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n, m,ans;
int map[9][9];
bool visit[9][9];
bool selectComplete[9][9];
queue<pair<int, int>> q;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool isVaild(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m;
}
void bfs() {
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 2) {
				visit[i][j] = true;
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (isVaild(tx, ty) && !visit[tx][ty] && map[tx][ty] == 0) {
				visit[tx][ty] = true;
				q.push({ tx,ty });
			}
		}
	}
	int temp = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visit[i][j] && map[i][j] == 0) {
				temp++;
			}
		}
	}
	ans = max(ans, temp);
}
void selectWall(int x, int y, int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = x; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0 && !selectComplete[i][j]) {
				map[i][j] = 1;
				selectComplete[i][j] = true;
				selectWall(i, j, cnt + 1);
				selectComplete[i][j] = false;
				map[i][j] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				selectWall(i, j,1);
				selectComplete[i][j] = true;
				map[i][j] = 0;
			}
		}
	}
	cout << ans;
}