#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string input;
string temp;
string ans;
bool check;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	getline(cin, input);
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '<') {
			check = true;
			if (temp.empty()) {
				ans += input[i];
			}
			else {
				reverse(temp.begin(), temp.end());
				ans += temp;
				ans += input[i];
				temp.clear();
			}
			continue;
		}
		else if (input[i] == '>') {
			check = false;
			ans += input[i];
			continue;
		}
		else if (input[i] == ' ') {
			reverse(temp.begin(), temp.end());
			ans += temp;
			ans += input[i];
			temp.clear();
			continue;
		}
		if (!check)
			temp += input[i];
		else
			ans += input[i];
		
	}

	if (!temp.empty()) {
		reverse(temp.begin(), temp.end());
		ans += temp;
	}
	for (int i = 0; i < ans.length(); i++)
		cout << ans[i];

}