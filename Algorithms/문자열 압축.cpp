#include <string>
#include <vector>
#include<iostream>
using namespace std;
void get(string &str, int start, int len, vector<char> &v) {
	for (int i = start; i < start + len; i++) {
		v.push_back(str[i]);
	}
}

int solution(string s) {
	int answer = 0;
	string tmp;
	int sSize = s.size();
	answer = sSize;
	for (int i = 1; i <= sSize / 2; i++) {
		vector<char> v;
		int count = 1;
		tmp = "";
		int p = 0;
		int endPoint = sSize / i;
		for (p; p < endPoint; p++) {
			if (v.empty()) {
				get(s, p*i, i, v);
			}
			
			int check = 0;
			for (int j = p * i + i; j < p * i + i + i; j++) {
				if (s[j] == v[j%i]) {
					check++;
					if (check == i) {
						count++;
					}
				}
				else {
					if (count != 1) {
						string y = to_string(count);
						for (int u = 0; u < y.size(); u++) {
							tmp.push_back(y[u]);

						}
					}			
					for (int m = 0; m < i; m++) {
						tmp.push_back(v[m]);
					}
					v.clear();
					count = 1;
					break;
					
				}

			}
		}
		if (endPoint*i != sSize) {
			for (int j = endPoint * i; j < sSize; j++) {
				tmp.push_back(s[j]);
			}
		}
		if (answer > tmp.size())answer = tmp.size();
	}




	return answer;
}

int main() {
	cout << solution("xxxxxxxxxxyyy") << '\n';

	cout << solution("a") << '\n';
	cout << solution("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx") << '\n';
	cout << solution("abcabcabcabcdededededede") << '\n';
	cout << solution("xababcdcdababcdcd") << '\n';

}