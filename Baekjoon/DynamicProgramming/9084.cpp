#include <iostream>
#include <cstring>
using namespace std;
int t, n,m, c[21];
long long d[10001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		memset(d, 0, sizeof(d));
		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> c[i];
		cin >> m;
		d[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = c[i]; j <= m; j++) {
				d[j] += d[j - c[i]];
			}
		}
		cout << d[m] << '\n';
	}
}