#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n;
vector <int> g[123457];
int number[123457];
bool visit[123457];
map<int, string> m;
long long go(int idx) {
	if (g[idx].size() == 0) {
		if (m[idx] == "S") return number[idx];
		else return 0;
	}

	long long temp = 0;
	for (int cur : g[idx]) {
		temp += go(cur);
	}

	if (m[idx] == "W") {
		temp -= number[idx];
		if (temp < 0) temp = 0;
	}
	else {
		temp += number[idx];
	}

	return temp;

}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 2,num,x; i <= n; i++) {
		string s;
		cin >> s >> num >> x;
		//g[i].push_back(x);
		g[x].push_back(i);
		m[i] = s;
		number[i] = num;
	}

	cout << go(1);
}