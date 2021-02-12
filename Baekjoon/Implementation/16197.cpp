#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int fcx, fcy, scx, scy;
int ans = 9999;
char map[21][21];
bool visit[21][21][21][21];
int dx[4] = { -1,0,1,0 },dy[4] = { 0,1,0,-1 };
bool isVaild(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m;
}
void dfs(int fx, int fy, int sx, int sy, int cnt) {
	if (cnt >= 10) {
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int tx = fx + dx[i];
		int ty = fy + dy[i];
		int tx2 = sx + dx[i];
		int ty2 = sy + dy[i];
		if (isVaild(tx, ty) && isVaild(tx2, ty2)) {
			if (map[tx][ty] == '#' && map[tx2][ty2] != '#' && !visit[fx][fy][tx2][ty2]) {
				visit[fx][fy][tx2][ty2] = true;
				dfs(fx, fy, tx2, ty2, cnt + 1);
				visit[fx][fy][tx2][ty2] = false;
			}
			else if (map[tx][ty] != '#' && map[tx2][ty2] == '#' && !visit[tx][ty][sx][sy]) {
				visit[tx][ty][sx][sy] = true;
				dfs(tx, ty, sx, sy, cnt + 1);
				visit[tx][ty][sx][sy] = false;
			}
			else if (map[tx][ty] != '#' && map[tx2][ty2] != '#' && !visit[tx][ty][tx2][ty2]) {
				visit[tx][ty][tx2][ty2] = true;
				dfs(tx, ty, tx2, ty2, cnt + 1);
				visit[tx][ty][tx2][ty2] = false;
			}
		}
		else if (isVaild(tx, ty) && !isVaild(tx2, ty2)) {
			ans = min(ans, cnt + 1);
			return;
		}
		else if (!isVaild(tx, ty) && isVaild(tx2, ty2)) {
			ans = min(ans, cnt + 1);
			return;
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
			if (map[i][j] == 'o') {
				if (fcx == 0 && fcy == 0) {
					fcx = i; fcy = j;
				}
				else {
					scx = i; scy = j;
				}
			}
		}
	}
	visit[fcx][fcy][scx][scy] = true;
	dfs(fcx, fcy, scx, scy, 0);
	if (ans == 9999) cout << "-1";
	else
		cout << ans;

}