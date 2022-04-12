#if 0

#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string regExp = "abcdefghijklmnopqrstuvwxyz0123456789-_.";

string solution(string new_id) {
	string answer = "";

	for (int i = 0; i < new_id.size();i++) {
		new_id[i] = tolower(new_id[i]);
	}
	for (int i = 0; i < new_id.size(); i++) {
		if (find(regExp.begin(), regExp.end(), new_id[i]) == regExp.end()) {
			new_id.erase(new_id.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < new_id.size(); i++) {
		if ((i < (new_id.size() - 1)) && (new_id[i] == '.') && (new_id[i + 1] == '.')) {
			new_id.erase(new_id.begin() + i);
			i--;
		}
	}
	if (*new_id.begin() == '.') new_id.erase(new_id.begin());
	if (*(new_id.end() - 1) == '.') new_id.erase(new_id.end() - 1);
	if (new_id.empty()) new_id = 'a';
	if (new_id.size() >= 16) new_id = new_id.substr(0, 15);
	if (*(new_id.end() - 1) == '.') new_id.erase(new_id.end() - 1);
	while (new_id.size() <= 2) {
		new_id.append(new_id.substr(new_id.size()-1));
	}
	answer = new_id;
	return answer;
}


int main() {
	solution("...!@BaT#*..y.abcdefghijklm");
}
#endif