#include <iostream>
using namespace std;
char a[50][50], b[50][50];
bool check[50][50];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
			if (a[i][j] != b[i][j]) {
				check[i][j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (check[i][j]) {
				ans++;
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						check[k][l] = !check[k][l];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j]) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << ans;
}