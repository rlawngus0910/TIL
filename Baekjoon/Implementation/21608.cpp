#include <iostream>
#include <vector>
using namespace std;
int n;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int map[21][21];
bool like[401][401];
bool visit[21][21];
int emptyCnt = -1;
int likeCnt = -1;
vector <int> v;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0,x; i < n * n; i++) {
		cin >> x;
		v.push_back(x);
		for (int j = 0, y; j < 4; j++) {
			cin >> y;
			like[x][y] = true;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int tar = v[i];
		int ltarx = 0;
		int ltary = 0;
		int etarx = 0;
		int etary = 0;
		emptyCnt = -1;
		likeCnt = -1;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (visit[j][k]) continue;
				int lcnt = 0;
				int ecnt = 0;
				for (int l = 0; l < 4; l++) {
					int tx = j + dx[l];
					int ty = k + dy[l];
					if (tx > 0 && tx <= n && ty > 0 && ty <= n) {
						if (map[tx][ty] == 0) {
							ecnt++;
						}
						else {
							if (like[tar][map[tx][ty]]) lcnt++;
						}
					}
				}
				
				if (lcnt > likeCnt) {
					ltarx = j;
					ltary = k;
					likeCnt = lcnt;
					emptyCnt = ecnt;
				}

				else if (lcnt == likeCnt) {
					if (ecnt > emptyCnt) {
						emptyCnt = ecnt;
						ltarx = j;
						ltary = k;
					}
				}
			}
		}
		map[ltarx][ltary] = tar;
		visit[ltarx][ltary] = true;
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tar = map[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int tx = i + dx[k];
				int ty = j + dy[k];
				
				if (tx > 0 && tx <= n && ty > 0 && ty <= n) {
					if (like[tar][map[tx][ty]]) cnt++;
				}
			}

			if (cnt == 1) ans += 1;
			else if (cnt == 2) ans += 10;
			else if (cnt == 3) ans += 100;
			else if (cnt == 4) ans += 1000;
		}
	}

	cout << ans;
}