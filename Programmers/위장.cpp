#if 0

#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	map<string, vector<string>> m;
	for (auto c : clothes) {
		m[c[1]].push_back(c[0]);
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		answer *= iter->second.size() + 1;
	}
	answer--;
	return answer;
}

int main() {

}

#endif
