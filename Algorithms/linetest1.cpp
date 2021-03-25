#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;
//flag_rule을 정리하여 가지고있는 map.
map<string, string> rule;

//string을 delimiter 기준으로 split하는 함수
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}
//program : 실행할 프로그램의 이름
//flag_rules : flag의 규칙을 저장한 배열
//command : 사용자의 입력값
vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
	vector<bool> answer;	
	int rulesSize = flag_rules.size(); //입력받은 룰의 갯수
	int commandsSize = commands.size(); //입력받은 커맨드의 갯수


	//flag_rules을 rule에 map으로 저장하기 위한 반복문
	for (int i = 0; i < rulesSize; i++) {
		vector<string> sep = split(flag_rules[i], ' ');
		rule[sep[0]] = sep[1];
	}


	//사용자의 입력값이 바른지 확인하기 위한 반복문
	//만약 바르지 않다면 isOK를 false
	for (int t = 0; t < commandsSize; t++) {
		//사용자의 입력값을 스페이스로 분리시킨 벡터
		vector<string> sep = split(commands[t], ' ');
		int sepSize = sep.size();
		bool isOK = true;
		//사용할 프로그램과 입력한 프로그램이 다른 경우 false.
		if (sep[0] != program) {
			answer.push_back(false);
			isOK = false;

			continue;
		}

		//프로그램 다음에 입력된 command부터 검사.
		for (int i = 1; i < sepSize; i++) {
			string flag;
			//올바르지 않다고 판명 됐다면 반복문 종료.
			if (!isOK) {
				break;
			}
			//flag가 -로 시작하지 않는다면 false.
			if (sep[i][0] == '-') {
				flag = sep[i];
				i++;
			}
			else {
				answer.push_back(false);
				isOK = false;

				break;
			}

			//rule에 저장된 flag라면 진행. 저장되지 않은 flag라면 false.
			if (rule.find(flag) != rule.end()) {
				if (rule[flag] == "NULL") {
					//다시 포인트를 이전으로 돌려 '-'로 시작하는 flag가 아니라면 false.
					i--;
				}
				else if (rule[flag] == "NUMBER") {
					string command = sep[i];
					int commandSize = command.size();
					for (int j = 0; j < commandSize; j++) {
						//command가 숫자가 아니라면 false
						if (command[j] - '0' >= 0 && command[j] - '0' <= 9) {

						}
						else {
							answer.push_back(false);
							isOK = false;

							break;
						}
					}
				}
				else if (rule[flag] == "STRING") {
					string command = sep[i];
					int commandSize = command.size();
					for (int j = 0; j < commandSize; j++) {
						//command가 영어 소문자 또는 영어 대문자가 아니라면 false

						if ((command[j] - 'a' >= 0 && command[j] - 'a' <= 26) || (command[j] - 'A' >= 0 && command[j] - 'A' <= 26)) {

						}
						else {
							answer.push_back(false);
							isOK = false;

							break;
						}
					}
				}
				else if (rule[flag] == "NUMBERS") {
					
					bool isFirst = true; //flag의 인자로 값이 들어오지 않고 flag가 바로 들어올 경우를 처리하기 위한 bool 변수
					while (1) {
						if (!isOK) break;
						string command = sep[i];
						int commandSize = command.size();
						if (command[0] == '-' && isFirst == false) {
							i--;
							break;
						}
						if (i == sepSize) {
							break;
						}
						for (int j = 0; j < commandSize; j++) {
							//command가 숫자가 아니라면 false
							if (command[j] - '0' >= 0 && command[j] - '0' <= 9) {

							}
							else {
								answer.push_back(false);
								isOK = false;

								break;
							}
						}
						i++;
						isFirst = false;

					}
				}
				else if (rule[flag] == "STRINGS") {
					bool isFirst = true; //flag의 인자로 값이 들어오지 않고 flag가 바로 들어올 경우를 처리하기 위한 bool 변수
					while (1) {
						if (!isOK) break;
						string command = sep[i];
						int commandSize = command.size();

						if (command[0] == '-' && isFirst==false) {
							i--;
							break;
						}
						if (i == sepSize) {
							break;
						}
						for (int j = 0; j < commandSize; j++) {
							//command가 영어 소문자 또는 영어 대문자가 아니라면 false

							if ((command[j] - 'a' >= 0 && command[j] - 'a' <= 26) || (command[j] - 'A' >= 0 && command[j] - 'A' <= 26)) {

							}
							else {
								answer.push_back(false);
								isOK = false;

								break;
							}
						}
						i++;
						isFirst = false;
					}
				}
			}
			else {
				answer.push_back(false);
				isOK = false;
				break;
			}
		}
		
		if (isOK) {
			answer.push_back(true);
		}
		isOK = true;
	}








	return answer;
}

int main() {
	solution("line", { "-s STRINGS", "-n NUMBERS", "-e NULL" }, { "line -n 100 102 -s hi -e", "line -n id pwd -n 100" });
	solution("line", { "-s STRING", "-n NUMBER", "-e NULL" }, { "line -n 100 -s hi -e", "lien -s Bye" });



	return 0;
}