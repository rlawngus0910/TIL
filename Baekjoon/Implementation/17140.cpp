#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int r, c, k;
int map[201][201];
int counting[101];
vector <pair<int, int>> v;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	int row = 3; int col = 3;
	int ans = 0;
	int maxCol = 0;
	int maxRow = 0;
	while (map[r - 1][c - 1] != k) {

		ans++;
		
		//cout << row << ' ' << col << '\n';
		if (row >= col) {
			//cout << "R연산";
			//if (col >= 100) continue;
			for (int i = 0; i < row; i++) {
				int maxValue = -1;
				for (int j = 0; j < col; j++) {
					if (j >= 100) break;
					int x = map[i][j];
					map[i][j] = 0;
					if (x == 0) continue;
					maxValue = max(x, maxValue);
					counting[x]++;
				}

				int newCol = 0;

				for (int j = 0; j <= maxValue; j++) {
					if (counting[j] != 0) {
						v.push_back({ j,counting[j] });
					}
				}

				sort(v.begin(), v.end(), cmp);
				//memset(map[i], 0, sizeof(map[i]));
				for (int j = 0; j < v.size(); j++) {
					//cout << i << ' ' << newCol << '\n';
					//if (newCol >= 99) break;
					map[i][newCol++] = v[j].first;
					if (newCol >= 100) break;
					map[i][newCol++] = v[j].second;
					if (newCol >= 100) break;
				}
				maxCol = max(newCol, maxCol);
				memset(counting, 0, sizeof(counting));
				v.clear();
			}
			col = maxCol;
			//cout << "R연산끝";
		}
		else {
			//cout << "C연산";
			//if (row >= 100) continue;
			for (int i = 0; i < col; i++) {
				int maxValue = -1;
				for (int j = 0; j < row; j++) {
					if (j >= 100) break;
					int x = map[j][i];
					map[j][i] = 0;
					if (x == 0) continue;
					maxValue = max(x, maxValue);
					counting[x]++;
				}

				int newRow = 0;

				for (int j = 0; j <= maxValue; j++) {
					if (counting[j] != 0) {
						v.push_back({ j,counting[j] });
					}
				}

				sort(v.begin(), v.end(), cmp);

				for (int j = 0; j < v.size(); j++) {
					//cout << i << ' ' << newRow << '\n';
					//if (newRow >= 99) break;
					map[newRow++][i] = v[j].first;
					if (newRow >= 100) break;
					map[newRow++][i] = v[j].second;
					if (newRow >= 100) break;
				}
				maxRow = max(newRow, maxRow);
				memset(counting, 0, sizeof(counting));
				v.clear();
			}
			row = maxRow;
			//cout << "C연산끝";
		}
		if (ans > 100) break;
	}
	if (ans > 100) cout << "-1";
	else cout << ans;
}