#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dist[201][201];
int map[201][201];
int n, m;
const int INF = 2e6 + 10;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fill(dist[i], dist[i] + n + 1, INF);
	}
	for (int i = 0,s,f,d; i < m; i++) {
		cin >> s >> f >> d;
		dist[s][f] = min(dist[s][f], d);
		dist[f][s] = min(dist[f][s], d);
		map[s][f] = f;
		map[f][s] = s;
	}
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		map[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k]) {
					dist[j][k] = dist[j][i] + dist[i][k];
					map[j][k] = map[j][i];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0) cout << "- ";
			else cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}