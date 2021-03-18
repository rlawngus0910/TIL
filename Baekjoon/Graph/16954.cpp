#include <iostream>
#include <queue>
using namespace std;
char map[9][9];
bool visit[9][9][65];
bool check;
queue <pair<pair<int, int>,int>> q;
//vector <pair<int, int>> v;
int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,1,1,1,0,-1,-1,-1 };
bool isVaild(int x, int y) {
	return x > 0 && x <= 8 && y > 0 && y <= 8;
}
void moveWall() {
	for (int i = 8; i > 0; i--) {
		for (int j = 1; j <= 8; j++) {
			if (map[i][j] == '#' && i == 8) {
				map[i][j] = '.';
			}
			else if (map[i][j] == '#') {
				map[i + 1][j] = '#';
				map[i][j] = '.';
			}
		}
		
	}
}
void bfs(int x, int y,int sec) {
	visit[x][y][sec] = true;
	q.push({ { x,y },sec });
	while (!q.empty()) {
		int curx = q.front().first.first;
		int cury = q.front().first.second;
		int cursec = q.front().second;
		if (curx == 1 && cury == 8) {
			check = true;
			cout << "1";
			return;
		}
		q.pop();
		if (cursec > sec) {
			moveWall();
			sec = cursec;
		}
		if (map[curx][cury] == '#') continue;
		
		for (int i = 0; i < 8; i++) {
			int tx = curx + dx[i];
			int ty = cury + dy[i];
			if (isVaild(tx, ty) && !visit[tx][ty][cursec + 1]) {
				if (map[tx][ty] == '.') {
					q.push({ { tx,ty },cursec + 1 });
					visit[tx][ty][cursec + 1] = true;
				}
			}
		}
		if (!visit[curx][cury][sec + 1])
			q.push({ {curx,cury},sec + 1 });
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			cin >> map[i][j];
		}
	}
	bfs(8, 1, 0);
	if (!check) cout << "0";
}