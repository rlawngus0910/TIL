#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n, m,cnt;
string s;
map<string, int> c;
vector <string> ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (n--) {
		cin >> s;
		c[s]++;
	}
	while (m--) {
		cin >> s;
		if (c[s] != 0) {
			cnt++;
			c[s]++;
		}
	}
	cout << cnt << '\n'; 
	for (auto iter = c.begin(); iter != c.end(); ++iter) {
		if (iter->second == 2) cout << iter->first << '\n';
	}
}