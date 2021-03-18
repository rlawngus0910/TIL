#include <iostream>
using namespace std;
int n, m, k;
int map[1025][1025];
int dp[1025][1025];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i][j-1] + map[i][j];
		}
	}
	cin >> k;
	while (k--) {
		int ans = 0;
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		for (int i = x1; i <= y1; i++) {
			ans += (dp[i][y2] - dp[i][x2 - 1]);
		}
		cout << ans << '\n';	
	}
}