#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string inp_str) {
	vector<int> answer;
	map<char, int> charList;
	map<char, int>::iterator iter;
	int strSize = inp_str.size();
	if (strSize < 8 || strSize>15) {
		answer.push_back(1);
	}
	bool is = false;
	bool three[4] = { false, false, false, false };
	for (int i = 0; i < strSize; i++) {
		char check = inp_str[i];
		if (charList.find(check) == charList.end()) {
			charList[check] = 1;
		}
		else {
			charList[check]++;
		}



		if (check - 'a' >= 0 && check - 'a' < 27) {
			three[0] = true;
			continue;
		}
		else if (check - 'A' >= 0 && check - 'A' < 27) {
			three[1] = true;
			continue;
		}
		else if (check - '0' >= 0 && check - '0' <= 9) {
			three[2] = true;
			continue;
		}
		else if (check == '~' || check == '!' || check == '@' || check == '#' || check == '$' || check == '%' || check == '^' || check == '&' || check == '*') {
			three[3] = true;
			continue;
		}
		else {
			if (!is) {
				answer.push_back(2);
				is = true;
			}
		}
	}
	int threeCount = 0;
	for (int i = 0; i < 4; i++) {
		if (three[i] == true) {
			threeCount++;
		}
	}
	if (threeCount < 3) answer.push_back(3);

	bool is4 = false;
	for (int i = 0; i < strSize-4; i++) {
		int count = 1;
		if (is4) break;
		for (int j = i+1; j < i + 4; j++) {
			if (inp_str[j] == inp_str[i]) {
				count++;
			}
			else {
				break;
			}
			if (count >= 4) {
				answer.push_back(4);
				is4 = true;
			}
		}
	}



	for (iter = charList.begin(); iter != charList.end(); iter++) {
		if (iter->second >= 5) {
			answer.push_back(5);
		}
	}



	if (answer.empty())answer.push_back(0);


	return answer;
}

int main() {

	solution("+++++");
	return 0;
}