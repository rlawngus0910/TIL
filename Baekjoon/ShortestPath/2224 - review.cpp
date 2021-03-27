#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int INF = 1e9 + 10;
int n;
int cnt;
string m;
int map[53][53];
bool ans[53][53];
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i <= 52; i++)
		fill(map[i], map[i] + 52, INF);
	cin.ignore(1);
	for (int i = 0; i < n; i++) {
		getline(cin, m);
		char a = m[0];
		char b = m[m.length() - 1];
		int ta, tb;
		if (a >= 'A' && a <= 'Z') {
			ta = a - 'A';
		}
		else {
			ta = a - 71;
		}
		if (b >= 'A' && b <= 'Z') {
			tb = b - 'A';
		}
		else {
			tb = b - 71;
		}
		
		map[ta][tb] = 1;

	}
	for (int i = 0; i <= 51; i++) {
		map[i][i] = 0;
	}
	for (int i = 0; i <= 51; i++) {
		for (int j = 0; j <= 51; j++) {
			for (int k = 0; k <= 51; k++) {
				if(map[j][i] != INF && map[i][k] != INF)
					map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}
	for (int i = 0; i <= 51; i++) {
		for (int j = 0; j <= 51; j++) {
			if (map[i][j] != INF && map[i][j] != 0) cnt++;
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i <= 51; i++) {
		for (int j = 0; j <= 51; j++) {
			char aa, ab;
			if (map[i][j] != INF && map[i][j] != 0) {
				if (i >= 0 && i <= 25) {
					aa = i + 'A';
				}
				else {
					aa = i + 71;
				}
				if (j >= 0 && j <= 25) {
					ab = j + 'A';
				}
				else {
					ab = j + 71;
				}
				cout << aa << " => " << ab << '\n';
			}
		}
	}
}