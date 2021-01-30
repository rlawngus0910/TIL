#include <iostream>
#include <string>
#include <set>
using namespace std;
int start, finish,ans;
set<string> result;
void dfs(string s,int cnt) {
	unsigned long long num = 0;
	if (s != "") {
		num = stoull(s);
	}

	if (num != 0 && num <= finish && num >= start) {
		ans++;
	}
	else if (num > finish)
		return;

	if (result.find(s + "4") == result.end())
		dfs(s + "4", cnt + 1);
	if (result.find(s + "7") == result.end())
		dfs(s + "7", cnt + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> start >> finish;
	string s = "";
	dfs(s,0);
	cout << ans;
}