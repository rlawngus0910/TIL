#include <iostream>
#include <algorithm>
#include <queue>;
using namespace std;
int n, m;
int map[101][101];
int visit[101][101];
queue<pair<int, int>>q;
vector<pair<int, int>> v;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool isVaild(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m;
}
bool checkAir(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (isVaild(tx, ty) && visit[tx][ty] == 1 && map[tx][ty] == 0) {
			cnt++;
			if (cnt == 2) return true;
		}
	}
	return false;
}
void airTracking(int x, int y) {
	visit[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (isVaild(tx, ty) && visit[tx][ty] == 0 && map[tx][ty] == 0) {
				visit[tx][ty] = 1;
				q.push({ tx,ty });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	airTracking(1, 1);
	while (1) {
		ans++;
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout  <<  map[i][j] << ' ';
			}
			cout << '\n';
		}*/
		//cout << '\n';
		bool check = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 1) {
					check = true;
					if (checkAir(i, j) == true)
						v.push_back({ i,j });
				}
			}
		}
		if (!check) break;
		for (int i = 0; i < v.size(); i++) {
			int nx = v[i].first;
			int ny = v[i].second;
			map[nx][ny] = 0;
			airTracking(nx, ny);
		}
		v.clear();
	}
	cout << ans - 1;
}
