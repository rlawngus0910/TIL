#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string num;
int mx, mn = 1e9;
int cal(string s) {
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if ((s[i] - '0') % 2 != 0) cnt++;
	}
	return cnt;
}
void split(string s, int temp) {
	if (s.length() >= 3) {
		for (int i = 1; i < s.length(); i++) {
			for (int j = i + 1; j < s.length(); j++) {
				string a = s.substr(0, i);
				string b = s.substr(i, j - i);
				string c = s.substr(j);
				int m = stoi(a) + stoi(b) + stoi(c);
				split(to_string(m), temp + cal(to_string(m)));
			}
		}
	}
	if (s.length() == 2) {
		int nxtStr = s[0] - '0' + s[1] - '0';
		split(to_string(nxtStr), temp + cal(to_string(nxtStr)));
	}
	if (s.length() == 1) {
		mx = max(mx, temp + cal(num));
		mn = min(mn, temp + cal(num));
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> num;
	split(num, 0);
	cout << mn << ' ' << mx;
}