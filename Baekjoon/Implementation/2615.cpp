#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int omok[21][21];
int ansX, ansY;
int dx[4] = { 1,1,1,0 },dy[4] = { -1,0,1,1 };
bool isVaild(int tx, int ty) {
	return tx > 0 && tx <= 19 && ty > 0 && ty <= 19;
}
bool dfs(int x, int y, int value, int cnt,int dir) {
	if (cnt == 1) {
		if (isVaild(x - dx[dir], y - dy[dir]) && omok[x - dx[dir]][y - dy[dir]] == value)
			return false;
	}
	int tx = x + dx[dir];
	int ty = y + dy[dir];
	if (cnt == 5){
		ansX = x; ansY = y;
		if (!isVaild(tx, ty)) return true;
		if (omok[tx][ty] != value) {
			return true;
		}
		else if(omok[tx][ty] == value)
			return false;
	}
	if (isVaild(tx,ty)&&omok[tx][ty] == value) {
		return dfs(tx, ty, value, cnt + 1, dir);
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++)
			cin >> omok[i][j];
	}
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			if (omok[i][j] != 0) {
				for (int k = 0; k < 4; k++) {
					if (dfs(i, j, omok[i][j], 1, k) == true) {
						if (k == 0)
							cout << omok[i][j] << '\n' << ansX << ' ' << ansY;
						else
							cout << omok[i][j] << '\n' << i << ' ' << j;
						return 0;
					}
				}
			}
		}
	}
	cout << "0";
}