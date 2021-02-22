#include <iostream>
#include <algorithm>
using namespace std;
int n, k, w, v;
int d[101][100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w >> v;
		d[i][w] = max(d[i][w], v);
		for (int j = 1; j <= k; j++) {
			if (j < w) d[i][j] = d[i - 1][j];
			else
				d[i][j] = max(d[i - 1][j], v + d[i - 1][j - w]);
		}
	}
	cout << d[n][k];
}