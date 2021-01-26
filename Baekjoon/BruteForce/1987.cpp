#include <iostream>
#include <algorithm>
using namespace std;
int r, c,ans;
bool alphabet[26];
char g[20][20];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool isVaild(int x, int y) {
	return x >= 0 && x < r && y >= 0 && y < c;
}
void dfs(int x, int y,int cnt) {
	ans = max(ans, cnt);
	for (int i = 0,tx,ty; i < 4; i++) {
		tx = x + dx[i];
		ty = y + dy[i];
		if (isVaild(tx, ty)&&!alphabet[g[tx][ty] - 'A']) {
			alphabet[g[tx][ty] - 'A'] = true;
			dfs(tx, ty, cnt + 1);
			alphabet[g[tx][ty] - 'A'] = false;
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> g[i][j];
		}
	}
	alphabet[g[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << ans;
}