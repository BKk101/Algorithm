#include <string>
#include <vector>
#include <cmath>

using namespace std;
int num[10];
int len;
int ans[10000000];
int answer;

bool isPrime(int n) {
	int sq = floor(sqrt(n));
	if (n == 1 || n == 0) return false;
	if (n == 2) return true;
	for (int i = 2; i <= sq; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int combination(int depth, int * numb, int n) {
	if (depth > 1) {
		if (isPrime(n) && ans[n] == 0) {
			++answer;
			ans[n] = 1;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (numb[i] > 0) {
			--numb[i];
			combination(depth + 1, numb, 10 * n + i);
			++numb[i];
		}
	}
	return 0;
}

int solution(string numbers) {
	answer = 0;
	len = numbers.size();
	for (char s : numbers) {
		num[s - '0']++;
	}
	combination(1, num, 0);

	return answer;
}

int main() {
	string s = "011";
	solution(s);
}