#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int parent[1001];
string value[1001];

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}



vector<string> solution(vector<string> data, string word) {
	vector<string> answer;
	int vSize = data.size();
	for (int i = 0; i < vSize; i++) {
		vector<string> v = split(data[i], ' ');
		parent[stoi(v[0])] = stoi(v[2]);
		value[stoi]
	}





	if (answer.empty()) {
		answer.push_back("Your search for (" + word + ") didn't return any results");
	}
	return answer;
}

int main() {
	string line = "Thank you for visiting my Blog.";


}