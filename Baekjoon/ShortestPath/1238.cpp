#include <iostream>
#include <algorithm>
using namespace std;
int n, m, x;
int map[1001][1001];
const int INF = 1e9;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++)
		fill(map[i], map[i] + n + 1, INF);
	for (int i = 0,s,f,c; i < m; i++) {
		cin >> s >> f >> c;
		map[s][f] = min(map[s][f], c);
	}
	for (int i = 1; i <= n; i++)
		map[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, map[i][x] + map[x][i]);
	}
	cout << ans;
}