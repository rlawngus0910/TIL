#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, m, sz;
int map[1001][1001];
bool visit[1001][1001];
int s[1000001];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool isVaild(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m;
}
void dfs(int x, int y,int cnt) {
	sz++;
	visit[x][y] = true;
	map[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (isVaild(tx, ty) && map[tx][ty] == 1 && !visit[tx][ty]) {
			map[tx][ty] = cnt;
			dfs(tx, ty,cnt);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1 && !visit[i][j]) {
				dfs(i, j,cnt);
				s[cnt] = sz;
				sz = 0;
				cnt++;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				int temp = 1;
				set <int> st;
				for (int k = 0; k < 4; k++) {
					int tx = i + dx[k];
					int ty = j + dy[k];
					if (isVaild(tx, ty) && map[tx][ty] != 0 && st.count(map[tx][ty]) == 0) {
						st.insert(map[tx][ty]);
						temp += s[map[tx][ty]];
					}
				}
				ans = max(ans, temp);
			}
		}
	}
	cout << ans;
}