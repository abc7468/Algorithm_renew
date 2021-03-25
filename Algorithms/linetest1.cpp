#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;
//flag_rule�� �����Ͽ� �������ִ� map.
map<string, string> rule;

//string�� delimiter �������� split�ϴ� �Լ�
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}
//program : ������ ���α׷��� �̸�
//flag_rules : flag�� ��Ģ�� ������ �迭
//command : ������� �Է°�
vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
	vector<bool> answer;	
	int rulesSize = flag_rules.size(); //�Է¹��� ���� ����
	int commandsSize = commands.size(); //�Է¹��� Ŀ�ǵ��� ����


	//flag_rules�� rule�� map���� �����ϱ� ���� �ݺ���
	for (int i = 0; i < rulesSize; i++) {
		vector<string> sep = split(flag_rules[i], ' ');
		rule[sep[0]] = sep[1];
	}


	//������� �Է°��� �ٸ��� Ȯ���ϱ� ���� �ݺ���
	//���� �ٸ��� �ʴٸ� isOK�� false
	for (int t = 0; t < commandsSize; t++) {
		//������� �Է°��� �����̽��� �и���Ų ����
		vector<string> sep = split(commands[t], ' ');
		int sepSize = sep.size();
		bool isOK = true;
		//����� ���α׷��� �Է��� ���α׷��� �ٸ� ��� false.
		if (sep[0] != program) {
			answer.push_back(false);
			isOK = false;

			continue;
		}

		//���α׷� ������ �Էµ� command���� �˻�.
		for (int i = 1; i < sepSize; i++) {
			string flag;
			//�ùٸ��� �ʴٰ� �Ǹ� �ƴٸ� �ݺ��� ����.
			if (!isOK) {
				break;
			}
			//flag�� -�� �������� �ʴ´ٸ� false.
			if (sep[i][0] == '-') {
				flag = sep[i];
				i++;
			}
			else {
				answer.push_back(false);
				isOK = false;

				break;
			}

			//rule�� ����� flag��� ����. ������� ���� flag��� false.
			if (rule.find(flag) != rule.end()) {
				if (rule[flag] == "NULL") {
					//�ٽ� ����Ʈ�� �������� ���� '-'�� �����ϴ� flag�� �ƴ϶�� false.
					i--;
				}
				else if (rule[flag] == "NUMBER") {
					string command = sep[i];
					int commandSize = command.size();
					for (int j = 0; j < commandSize; j++) {
						//command�� ���ڰ� �ƴ϶�� false
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
						//command�� ���� �ҹ��� �Ǵ� ���� �빮�ڰ� �ƴ϶�� false

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
					
					bool isFirst = true; //flag�� ���ڷ� ���� ������ �ʰ� flag�� �ٷ� ���� ��츦 ó���ϱ� ���� bool ����
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
							//command�� ���ڰ� �ƴ϶�� false
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
					bool isFirst = true; //flag�� ���ڷ� ���� ������ �ʰ� flag�� �ٷ� ���� ��츦 ó���ϱ� ���� bool ����
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
							//command�� ���� �ҹ��� �Ǵ� ���� �빮�ڰ� �ƴ϶�� false

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