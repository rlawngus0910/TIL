#include <iostream>
#include <string>
using namespace std;
string str[10000];
bool check[10000][26];
int know[10000];
int n, m;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		for (int j = 0; j < str[i].length(); j++) {
			check[i][str[i][j] - 'a'] = true;
		}
	}
	int ans = n;
	for (int i = 0; i < m; i++) {
		int num;
		char a;
		cin >> num >> a;
		if (num == 1) {
			for (int j = 0; j < n; j++) {
				if (check[j][a - 'a']) {
					if (know[j] == 0)
						ans--;
					know[j]++;
				}
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				if (check[j][a - 'a'] && know[j] > 0) {
					know[j]--;
					if (know[j] == 0)
						ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}