#if 0
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<char> num;

bool comp(char a, char b) {
	return a > b;
}

int calc(char maxv, int idx, string number2) {
	int removed = 0;
	for (int i = idx; i < number2.length(); i++) {
		if (number2[i] == maxv) {
			break;
		}
		else {
			removed++;
		}
	}
	return removed;
}

string solution(string number, int k) {
	string answer = "";
	for (char s : number) {
		num.push_back(s);
	}
	sort(num.begin(), num.end(), comp);
	int maxi = 0;
	int remove = 0;


	for (int i = 0; i < number.size();) {
		int remove = calc(num[maxi], i, number);
		if (remove > k) {
			maxi++;
		}
		else {
			answer.push_back(number[i+remove]);
			i += remove + 1;
			k -= remove;
			maxi = 0;
		}
	}

	return answer;

}

int main() {
	solution("1924", 2);
}

#endif