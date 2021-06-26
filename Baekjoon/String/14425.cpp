#include <iostream>
#include <map>
using namespace std;
int n, m,ans;
map <string, int> str;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		str[s]++;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (str[s] == 1) ans++;
	}

	cout << ans;
}