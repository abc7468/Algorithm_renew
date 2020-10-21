#include<iostream>
#include<vector>
#include<string>
using namespace std;



int main() {
	string s;
	cin >> s;
	int val = 0;
	bool isMinus = false;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {


		int tmp = 0;
		if (s[i] == '+' && isMinus == false) {
			ans += val;
			val = 0;
			continue;
		}
		else if (s[i] == '+' && isMinus == true) {
			ans -= val;
			val = 0;
			continue;
		}
		else if (s[i] == '-') {
			if (isMinus == false) {
				ans += val;
				isMinus = true;
			}
			else if (isMinus == true) {
				ans -= val;
			}
			val = 0;
			continue;
		}
		else {
			tmp = s[i] - '0';
		}
		val = val*10 + tmp;
	}
	if (isMinus) {
		ans -= val;
	}
	else {
		ans += val;
	}
	cout << ans;
	return 0;
}