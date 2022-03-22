#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int calc(string s) {
	stack<char> st;
	map<char, int> num; //괄호 값
	map<char, char> bracket; //괄호 쌍

	//괄호 쌍과 값 저장
	bracket[')'] = '(';
	bracket[']'] = '[';
	num['('] = 2; //()의 값=2
	num['['] = 3; //[]의 값=3

	int ans = 0, temp = 1;
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) { //s의 i번째 값이
		case '(': case '[': //여는 괄호일 경우
			st.push(s[i]); //push
			temp *= num[s[i]]; // 곱하기 연산
			break;
		case ')': case ']': //닫는 괄호일 경우
			if (st.empty() || st.top() != bracket[s[i]]) { //스택이 비어있거나 스택의 윗부분이 쌍이 되지 않을 경우 
				return 0; //0출력
			}
			if (s[i - 1] == bracket[s[i]]) { //짝이 맞으면
				ans += temp; //더하기 연산
			}
			temp /= num[bracket[s[i]]]; //이미 값을 더한 경우이므로 나누기
			st.pop(); //스택에 pop
			break;
		}
	}
	if (st.empty()) { //올바른 괄호라면
		return ans; //ans return
	}
	return 0;
}

/**
 * "분배법칙"을 활용!
 * ex. ([]([])): 2 x (3 + 2 x 3) == 2 x 3 + 2 x 2 x 3
 * =>                               (   [ ]     (   [   ]   )   )
 * =>                   임시변수값:  2   6 2     4  12   4   2   1
 * =>                        정답:        +6           +12        = 18
 *
 * 따라서, 우선 여는 괄호가 나오면 괄호의 값을 곱해줌
 * 닫는 괄호는, 이전 문자가 여는 괄호일 경우 지금까지 곱한 값을 더해줌 (값이 중복으로 더해지는 것을 방지하기 위해 이전 문자가 여는 괄호인지 꼭 체크!)
 *            한 괄호에 대한 연산이 끝났으므로 (곱하기 연산) 다시 괄호 값을 나눠줘서 연산 진행
 */

int main() {
	string s;

	//입력
	cin >> s; //s값 입력
	//연산 & 출력
	cout << calc(s); //calc(s)값 출력
	return 0;
}