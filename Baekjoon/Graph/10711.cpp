#include <iostream>
#include <queue>
using namespace std;
int h, w;
char map[1001][1001];
bool visit[1001][1001];
int check[1001][1001];
queue <pair<int, int>> q;
vector <pair<int, int>> v;
int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,1,1,1,0,-1,-1,-1 };
bool isVaild(int x, int y) {
	return x > 0 && x <= h && y > 0 && y <= w;
}
int bfs() {
	int ans = 0;
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0,tx,ty; i < 8; i++) {
			tx = curx + dx[i];
			ty = cury + dy[i];
			if (isVaild(tx, ty) && !visit[tx][ty]) {
				if (map[tx][ty] != '.') {
					check[tx][ty]++;
				}
				if (check[tx][ty] >= map[tx][ty] - '0') {
					v.push_back({ tx,ty });
					visit[tx][ty] = true;
				}
			}
		}
		if (q.empty() && v.size() != 0) {
			ans++;
			for (auto nxt : v) {
				map[nxt.first][nxt.second] = '.';
				q.push({ nxt.first, nxt.second });
			}
			v.clear();
		}
	}
	return ans;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> map[i][j];
			if (map[i][j] == '.') {
				visit[i][j] = true;
				q.push({ i,j });
			}
		}
	}
	cout << bfs();
}
