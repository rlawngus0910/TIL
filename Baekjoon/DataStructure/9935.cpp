#include <iostream>
#include <string>
using namespace std;
string str;
string boom;
char ans[1000001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	cin >> boom;
	int idx = 0;
	for (int i = 0; i < str.length(); i++) {
		ans[idx++] = str[i];

		if (idx >= boom.length() && ans[idx - 1] == boom[boom.length() - 1]) {
			bool check = true;
			for (int j = 1; j <= boom.length() - 1; j++) {
				if (ans[idx - 1 - j] != boom[boom.length() - 1 - j]) {
					check = false;
					break;
				}
			}
			if (check) idx -= boom.length();
		}
	}
	if (idx == 0) cout << "FURLA";
	else {
		for (int i = 0; i < idx; i++) {
			cout << ans[i];
		}
	}
}