#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int A[11][11];
int yang[11][11];
int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int N, M, K;
vector <int> tree[11][11];
vector<pair<pair<int, int>, int>> dtree;
vector<pair<pair<int, int>, int>> gtree;

bool isVaild(int x, int y) {
	return x > 0 && x <= N && y > 0 && y <= N;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	while (M--) {
		int treeX, treeY, treeOld;
		cin >> treeX >> treeY >> treeOld;
		tree[treeX][treeY].push_back(treeOld);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			yang[i][j] = 5;
		}
	}

	while (K--) {
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (tree[i][j].empty()) continue;

				else {
					//cout << i << ' ' << j << ' '<< tree[i][j].size() << '\n';
					vector <int> vec;
					sort(tree[i][j].begin(), tree[i][j].end());
					for (int k = 0; k < tree[i][j].size(); k++) {
						int age = tree[i][j][k];

						if (age > yang[i][j]) {
							dtree.push_back({ {i,j},age });
						}
						else if (age <= yang[i][j]) {
							yang[i][j] -= age;
							vec.push_back(age + 1);

							if ((age + 1) % 5 == 0) {
								gtree.push_back({ {i,j},age + 1 });
							}
						}
					}
					tree[i][j] = vec;
				}
			}
		}

		for (int i = 0; i < dtree.size(); i++) {
			int dtx = dtree[i].first.first;
			int dty = dtree[i].first.second;
			int old = dtree[i].second;
			yang[dtx][dty] += (old / 2);
		}

		for (int i = 0; i < gtree.size(); i++) {
			int gtx = gtree[i].first.first;
			int gty = gtree[i].first.second;
			//cout << "gtx : " << gtx << ' ' << "gty : " << gty << '\n';
			for (int j = 0; j < 8; j++) {
				int ntx = gtx + dx[j];
				int nty = gty + dy[j];
				//cout << j << ' '<< ntx << ' ' << nty << '\n';
				if (isVaild(ntx, nty)) {
					//cout << ntx << ' ' << nty << '\n';
					tree[ntx][nty].push_back(1);
				}
			}
		}
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				yang[i][j] += A[i][j];
			}
		}
		dtree.clear();
		gtree.clear();
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += tree[i][j].size();
		}
	}
	cout << ans;
}