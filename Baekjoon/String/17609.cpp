#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int t;
string s;
bool checkStr(int start, int finish) {
	while (start < finish) {
		if (s[start] == s[finish]) {
			start++;
			finish--;
		}
		else return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> s;
		int start = 0;
		int finish = s.size() - 1;
		bool zero = true;
		bool one = false;
		while (start < finish) {
			if (s[start] == s[finish]) {
				start++;
				finish--;

			}
			else {
				zero = false;
				if (checkStr(start, finish - 1)) {
					one = true;
					break;
				}
				if (checkStr(start + 1, finish)) {
					one = true;
					break;
				}
				break;
			}
		}
		if (zero) cout << "0" << '\n';
		else if (one) cout << "1" << '\n';
		else cout << "2" << '\n';
	}
}