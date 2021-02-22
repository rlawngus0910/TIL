#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
int c[101], d[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= k; i++) {
		d[i] = 100000;
	}
	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		d[c[i]] = 1;
		for (int j = c[i]; j <= k; j++) {
			d[j] = min(d[j], d[j - c[i]] + 1);
			//cout << j << ' ' << d[j] << '\n';
		}
	}
	if (d[k] == 100000) cout << "-1";
	else cout << d[k];
}