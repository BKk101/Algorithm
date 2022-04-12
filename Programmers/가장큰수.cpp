#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string sa, string sb) {
	if (sa[0] > sb[0]) return true;
	else if (sa[0] < sb[0]) return false;
	else if (sa[0] == sb[0]) {
		int la = sa.length();
		int lb = sb.length();
		if (la < lb) return true;
		else if (la > lb) return false;
		else if (la == lb) check(sa.substr(1), sb.substr(1));
	}
}

bool comp(int a, int b) {

	string sa = to_string(a);
	string sb = to_string(b);

	check(sa, sb);
}


string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), comp);
	for (int i = 0; i < numbers.size(); i++) {
		answer.append(to_string(numbers[i]));
	}
	return answer;
}

int main() {
	vector<int> num = { 6, 10, 2 };
	solution(num);
}