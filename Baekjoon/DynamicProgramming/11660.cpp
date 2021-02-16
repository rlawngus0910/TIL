#include <iostream>
using namespace std;
int map[1025][1025];
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			map[i][j] += map[i][j - 1];
		}
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			map[i][j] += map[i][j - 1];
		}
	}*/
	while (m--) {
		int x1, y1, x2, y2;
		int ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i <= x2; i++) {
			ans += map[i][y2] - map[i][y1 - 1];
		}
		cout << ans << '\n';
	}
}