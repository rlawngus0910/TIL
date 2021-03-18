#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n, m;
vector <pair<string, int>> v;
map<int, string> mp;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (n--) {
		string s;
		int a;
		cin >> s >> a;
		v.push_back({ s,a });
		if (mp[a] == "")
			mp[a] = s;
	}
	while (m--) {
		int power;
		cin >> power;

		int start = 0;
		int finish = v.size() - 1;
		bool check = false;
		if (v[start].second > power) {
			cout << v[start].first << '\n';
			continue;
		}
		while (start < finish) {
			int mid = (start + finish) / 2;
			if (power > v[mid].second) {
				start = mid + 1;
			}
			else if(power < v[mid].second){
				finish = mid;
			}
			else {
				check = true;
				cout << mp[v[mid].second] << '\n';
				break;
			}
		}
		if (!check)
			cout << v[start].first << '\n';
	}

}