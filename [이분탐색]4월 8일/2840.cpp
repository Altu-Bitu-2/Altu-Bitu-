#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci;

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {
	string ans = "";//바퀴에 적힌 문자들을 문자열로 표현하기 위한 ans 선언
	int start = arrow_point; //넘겨받은 마지막 idx를 시작으로 
	do {
		ans += wheel[arrow_point]; //현재 화살표가 가리키는 문자부터 ans 추가
		arrow_point = (arrow_point + 1) % n; //화살표 한 칸씩 옆으로
	} while (arrow_point != start); //화살표가 처음으로 돌아오면 멈추기
	return ans;//바퀴에 적힌 문자열 리턴
}

//행운의 바퀴 구하는 함수
string makeWheel(int n, vector<ci> &record) { 
	vector<char> wheel(n, '?'); //바퀴의 상태
	vector<bool> is_available(26, false); //알파벳 중복 체크

	int idx = 0; //화살표가 가리키는 인덱스
	for (int i = 0; i < record.size(); i++) {//record 크기 만큼 반복
		int rot = record[i].first; //record에 적힌 글자 변경 횟수를 rot에 저장
		char alpha = record[i].second; //record에 적힌 현재 글자를 alpha에 저장
		idx = (idx - rot % n + n) % n; //화살표 위치 변경
		if (wheel[idx] == alpha) { //idx 가리키는 곳에 적힌 문자가 alpha와 같으면
			continue; //반복
		}
		if (wheel[idx] != '?' || is_available[alpha - 'A']) { //idx가 가리키는 곳에 이미 alpha와 다른 문자가 적혀있거나 다른 곳에 적힌 문자면
			return "!"; //!리턴
		}
		wheel[idx] = alpha;//idx위치에 alpha 넣기
		is_available[alpha - 'A'] = true; //alpha 사용했다고 확인
	}
	return arrowStartWheel(idx, n, wheel);
}

/**
 * [행운의 바퀴]
 *
 * 바퀴가 돌아갈 필요 X
 * 화살표가 가르키는 인덱스를 회전 정보에 따라 바꿔줌
 *
 * 1. 화살표가 가르키는 칸이 결정되지 않았으면 알파벳을 바퀴에 적는다.
 * 2. 이미 알파벳이 써 있는 경우, 같은 알파벳이 아닌 경우 조건에 해당하는 바퀴 만들 수 없다.
 * 3. 바퀴에 쓰여있는 알파벳은 중복되지 않으므로 동일한 알파벳이 여러 자리에 있을 수 없다.
 */

int main() {
	int n, k;

	//입력
	cin >> n >> k; //n,k 입력 받음
	vector<ci> record(k, { 0, 0 }); //바퀴 회전 기록
	for (int i = 0; i < k; i++) { //k번 반복
		cin >> record[i].first >> record[i].second;

	//연산 & 출력
	cout << makeWheel(n, record); //출력
	return 0;
}