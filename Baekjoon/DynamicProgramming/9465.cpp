#include <iostream>
#include <algorithm>
using namespace std;
int t,n;
int d[100001][3],stick[2][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> stick[i][j];
			}
		}
		d[1][0] = 0;
		d[1][1] = stick[0][1];
		d[1][2] = stick[1][1];
		for (int i = 2; i <= n; i++) {
			d[i][0] = max(d[i - 1][1], d[i - 1][2]);
			d[i][1] = max(d[i - 1][2] + stick[0][i], d[i - 1][0] + +stick[0][i]);
			d[i][2] = max(d[i - 1][1] + stick[1][i], d[i - 1][0] + +stick[1][i]);
		}
		cout << max({ d[n][0],d[n][1],d[n][2] }) << '\n';
	}
}