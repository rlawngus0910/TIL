#include <iostream>
#include <algorithm>
using namespace std;
string a, b;
int d[1001][1001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	for (int i = 1; i <= b.length(); i++) {
		for (int j = 1; j <= a.length(); j++) {
			if (a[j - 1] == b[i - 1]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	cout << d[b.length()][a.length()];
}