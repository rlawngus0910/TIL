#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y, k;
int map[21][21];
int dx[5] = { 0,0,0,-1,1 }, dy[5] = { 0,1,-1,0,0 };
vector <int> dice(7);
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0,dir; i < k; i++) {
		cin >> dir;
		int tx = x + dx[dir];
		int ty = y + dy[dir];

		if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;

		if (dir == 1) {
			dice = { 0,dice[4],dice[2],dice[1],dice[6],dice[5],dice[3] };
		}

		if (dir == 2) {
			dice = { 0,dice[3],dice[2],dice[6],dice[1],dice[5],dice[4] };
		}

		if (dir == 3) {
			dice = { 0,dice[5],dice[1],dice[3],dice[4],dice[6],dice[2] };
		}

		if (dir == 4) {
			dice = { 0,dice[2],dice[6],dice[3],dice[4],dice[1],dice[5] };
		}

		cout << dice[1] << '\n';

		if (map[tx][ty] == 0) map[tx][ty] = dice[6];
		else {
			dice[6] = map[tx][ty];
			map[tx][ty] = 0;
		}

		x = tx;
		y = ty;
	}
}