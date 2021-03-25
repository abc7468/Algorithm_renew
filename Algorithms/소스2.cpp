#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;
map<string, string> rule; //flag_rule을 정리하여 가지고있는 map.
map<string, string> alias; //rule과 alias를 이어주는 map
map<string, bool> used; //alias가 이미 사용 됐는지 확인하는 map

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

//alias로 연결된 flag인지 확인
bool checkAlias(string str) {
	//alias로 연결된 flag라면  true 반환
	if (alias.find(str) != alias.end()) {
		return true;
	}
	else {
		return false;
	}
}


//사용된 flag의 alias값을 사용 하지 못하도록 update
void updateAlias(string str) {
	used[alias[str]] = true;
}

bool canUse(string str) {
	//만약 이미 used에 저장된 값이라면 사용 불가.
	if (used.find(str) != used.end()) {
		return false;
	}
	else {
		return true;
	}
}

//program : 실행할 프로그램의 이름
//flag_rules : flag의 규칙을 저장한 배열
//command : 사용자의 입력값
vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
	vector<bool> answer;
	int rulesSize = flag_rules.size(); //입력받은 룰의 갯수
	int commandsSize = commands.size(); //입력받은 커맨드의 갯수
	vector<vector<string>> ruleTmp; //ALIAS 처리를 위한 임시 벡터
	//flag_rules을 rule에 map으로 저장하기 위한 반복문
	for (int i = 0; i < rulesSize; i++) {
		vector<string> sep = split(flag_rules[i], ' ');
		int sepSize = sep.size();
		if (sepSize == 2) {
			rule[sep[0]] = sep[1];

		}
		//sepSize가 3이면 ALIAS이기 때문에 ruleTmp벡터에 해당 sep을 임시로 저장 후 처리.
		else if (sepSize == 3) {
			ruleTmp.push_back(sep);
			
		}
	}

	int aliasSize = ruleTmp.size();
	//ruleTmp 처리 반복문
	for (int i = 0; i < aliasSize; i++) {
		vector<string> tmp = ruleTmp[i];
		rule[tmp[0]] = rule[tmp[2]];
		alias[tmp[0]] = tmp[2];
		alias[tmp[2]] = tmp[0];
	}

	//사용자의 입력값이 바른지 확인하기 위한 반복문
	//만약 바르지 않다면 isOK를 false
	for (int t = 0; t < commandsSize; t++) {
		vector<string> sep = split(commands[t], ' '); //사용자의 입력값을 스페이스로 분리시킨 벡터
		int sepSize = sep.size(); //command를 스페이스로 split시킨 벡터의 크기
		bool isOK = true; //옳은 값인지 상태를 체크하는 변수

		//사용할 프로그램과 입력한 프로그램이 다른 경우 false.
		if (sep[0] != program) {
			answer.push_back(false);
			isOK = false;

			continue;
		}

		//프로그램 다음에 입력된 command부터 검사.
		for (int i = 1; i < sepSize; i++) {
			string flag;
			//바르지 않다고 판명 됐다면 반복문 종료.
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
			//Alias값을 가진 flag인지 확인
			if (checkAlias(flag)) {
				//사용할 수 있는 flag라면 연결된 flag를 사용 불가로 만든 후 진행.
				if (canUse(flag)) {
					updateAlias(flag);
				}
				//사용할 수 없는 flag라면 false.
				else {
					answer.push_back(false);
					isOK = false;

					break;
				}
			}

			//rule에 저장된 flag라면 진행. 저장되지 않은 flag라면 false.
			if (rule.find(flag) != rule.end()) {
				if (rule[flag] == "NULL") {
					//argument가 없는 flag이기 때문에 포인트를 이전으로
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

						if (command[0] == '-' && isFirst == false) {
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
		//command의 끝까지 진행 됐고 isOK가 여전히 true라면 true.
		if (isOK) {
			answer.push_back(true);
		}
		isOK = true;
		//사용불가의 alias로 연결된 flag 초기화
		used.clear();
	}

	return answer;
}

int main() {
	solution("line", { "-s STRING", "-num NUMBER", "-e NULL", "-n ALIAS -num" }, { "line -n 100 -s hi -e", "line -n 100 -e -num 150" });
	solution("line", { "-s STRING", "-n NUMBER", "-e NULL" }, { "line -n 100 -s hi -e", "lien -s Bye" });



	return 0;
}