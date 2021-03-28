#include <iostream>
#include <algorithm>
using namespace std;
int v, e;
int map[401][401];
bool visit[401];
int ans = 1e7;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		fill(map[i], map[i] + v + 1, 1e7);
	}
	for (int i = 0,s,f,c; i < e; i++) {
		cin >> s >> f >> c;
		map[s][f] = min(map[s][f], c);
	}
	for (int i = 1; i <= v; i++) map[i][i] = 0;

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (map[i][j] != 1e7 && map[j][i] != 1e7 && map[i][j] != 0 && map[j][i] != 0)
				ans = min(ans, map[i][j] + map[j][i]);
		}
	}
	if (ans == 1e7) cout << "-1";
	else cout << ans;
}