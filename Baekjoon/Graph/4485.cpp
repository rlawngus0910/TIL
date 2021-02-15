#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int map[126][126];
int dp[126][126];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1, 0,-1 };
queue<pair<int, int>>q;
bool isVaild(int x,int y) {
	return x > 0 && x <= n && y > 0 && y <= n;
}
void bfs(int x, int y) {
	dp[x][y] = map[x][y];
	q.push({ x,y });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = cx + dx[i];
			int ty = cy + dy[i];
			if (isVaild(tx, ty) && dp[cx][cy] + map[tx][ty] < dp[tx][ty]) {
				dp[tx][ty] = dp[cx][cy] + map[tx][ty];
				q.push({ tx,ty });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int problem = 0;
	while (1) {
		problem++;
		cin >> n;
		if (n == 0) return 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				dp[i][j] = 150000;
		}

		bfs(1, 1);
		cout << "Problem " << problem << ": " << dp[n][n] << '\n';
	}
}