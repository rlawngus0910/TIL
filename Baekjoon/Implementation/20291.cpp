#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
map <string, int> m;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '.') {
				m[s.substr(j + 1)]++;
				break;
			}
		}
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) 
		cout << iter->first << ' ' << iter->second << '\n';
}