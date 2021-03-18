#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n;
vector <string> v;
map <string, int> m;
string s;
bool cmp(const string& a, const string& b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (m[s] != 0) continue;
		v.push_back(s);
		m[s]++;
	}
	sort(v.begin(), v.end(),cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}