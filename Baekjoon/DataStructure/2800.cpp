#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;
string s;
set <string> v;
stack<int> st;
string ans;
int erasing[230];
bool check[230];
void dfs(int idx) {
	if (idx == s.length()) {
		if (ans.length() != s.length())
			v.insert(ans);
		return;
	}
	if (s[idx] == '(') {
		check[erasing[idx]] = true;
		dfs(idx + 1);
		check[erasing[idx]] = false;
	}
	if (s[idx] == ')' && check[idx] == true) {
		dfs(idx + 1);
	}
	else {
		ans += s[idx];
		dfs(idx + 1);
		ans.resize(ans.size() - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else if (s[i] == ')') {
			erasing[st.top()] = i;
			erasing[i] = st.top();
			st.pop();
		}
	}
	dfs(0);
	set<string>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << '\n';
	}
}