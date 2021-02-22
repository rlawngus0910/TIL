#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int r, c, startX, startY;
bool check;
queue <pair<int, int>> q;
queue <pair<int, int>> fq;
char map[1001][1001];
bool visit[1001][1001];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
void fireBFS(int x, int y) {
	fq.pop();
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx > 0 && tx <= r && ty > 0 && ty <= c) {
			if (map[tx][ty] != '#' && map[tx][ty] != 'F') {
				map[tx][ty] = 'F';
				fq.push({ tx,ty });
			}
		}
	}
}
void bfs(int x, int y) {
	visit[x][y] = true;
	q.pop();
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx > 0 && tx <= r && ty > 0 && ty <= c) {
			if (map[tx][ty] == '.' && !visit[tx][ty]) {
				q.push({ tx,ty });
			}
		}
		else {
			check = true;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				q.push({ i,j });
			}
			else if (map[i][j] == 'F') {
				fq.push({ i,j });
			}
		}
	}
	int ans = 0;
	while (1) {
		ans++;
		int sz = q.size();
		if (sz == 0) break;
		while (sz--) {
			if (map[q.front().first][q.front().second] == 'F') {
				q.pop();
				continue;
			}
			if (visit[q.front().first][q.front().second]) {
				q.pop();
				continue;
			}
			bfs(q.front().first, q.front().second);
			if (check) {
				cout << ans;
				return 0;
			}
		}
		int fqsz = fq.size();
		while (fqsz--) 
			fireBFS(fq.front().first, fq.front().second);
		
	}
	cout << "IMPOSSIBLE";
}