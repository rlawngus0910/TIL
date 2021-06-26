#include <iostream>
#include <set>
#include <map>
using namespace std;
int n,c;
map <int, set<int>> m;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0,p,l; i < n; i++) {
		cin >> p >> l;
		m[l].insert(p);
	}

	cin >> c;
	for (int i = 0,x,p,l; i < c; i++) {
		string com;
		cin >> com;
		if (com == "recommend") {
			cin >> x;
			if (x == 1) {
				auto iter = --(m.end());
				cout << *(--(iter->second.end())) << '\n';
			}
			else {
				auto iter = m.begin();
				cout << *(iter->second.begin()) << '\n';
			}
		}
		else if (com == "add") {
			cin >> p >> l;

			m[l].insert(p);
		}
		else if (com == "solved") {
			cin >> p;
			for (auto iter = m.begin(); iter != m.end(); iter++) {
				if ((iter->second).find(p) != iter->second.end()) {
					iter->second.erase(p);
					if (iter->second.empty()) {
						m.erase(iter);
					}
					break;
				}
			}
		}
	}
}