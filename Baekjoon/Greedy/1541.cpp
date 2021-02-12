#include <iostream>
#include <string>
using namespace std;
string s;
bool check;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	string temp = "";
	int ans = 0;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
		}
		else {
			//cout << temp << '\n';
			if (check) {
				ans -= stoi(temp);
			}
			else {
				ans += stoi(temp);
			}
			if (s[i] == '-') check = true;
			temp = "";
			//cout << ans << '\n';
		}
	}
	cout << ans;
}