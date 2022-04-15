#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings; //2차원 배열
vector<int> order(10, 0); //타순
vector<bool> check(10, false); //선수 순서 결정 유무 배열
int n, ans;

//각 루타마다 얻는 점수
int hitScore(int hit, vector<bool> &baseman) {
	int score = 0; //점수 초기화
	for (int i = 3; i >= 0; i--) {
		if (!baseman[i]) { //현재 루수에 선수가 없으면
			continue; //반복
		}
		if (i + hit >= 4) { //선수들 값과 현재 루수를 더한 값이 4보다 크면
			score++; //score 증가
		}
		else {
			baseman[i + hit] = true; //루수에 선수있음으로 표시
		}
		baseman[i] = false; //루수에 선수 없음 표시
	}
	if (hit == 4) { //홈런이면
		score++; //점수 증가
	}
	else {
		baseman[hit] = true; //새로운 선수들 홈에 도착
	}
	return score; //점수 리턴
}

//현재 배치의 점수
int calcScore() {
	int score = 0; //총 점수
	int idx = 1; //타순 저장된 order 인덱스 번호
	for (int i = 0; i < n; i++) { //i: 이닝
		vector<bool> baseman(4, 0); //각 루수마다 선수가 있는지
		int out = 0; //아웃 선수 카운트
		while (out < 3) { //3out까지 반복
			int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
			if (idx == 10) { //선수들이 한 바퀴 돌았으면
				idx = 1; //첫 타자
			}
			if (state == 0) { //현재 선수의 공격상태가 0일때
				out++; //out 증가
			}
			else {
				score += hitScore(state, baseman); //hit함수 호출
			}
		}
	}
	return score; //점수 반환
}

//가능한 배치 모두 구하기
void array(int cnt) { //cnt: 타자순서
	if (cnt == 4) { //4번 타자는 정해져 있으므로
		array(cnt + 1);
		return;
	}
	if (cnt == 10) { //9번 타자까지 정해짐 (기저조건)
		int score = calcScore(); //점수 계산
		ans = max(ans, score);
		return;
	}
	for (int i = 2; i <= 9; i++) {
		if (!check[i]) { //i번 선수 순서가 정해지지 않았다면
			order[cnt] = i; //cnt번 타자: i번 선수
			check[i] = true; //i번 선수 순서 정해짐
			array(cnt + 1); //다음 타자
			check[i] = false; //i번 선수 순서 안정해진 상태
		}
	}
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() {
	//입력
	cin >> n; //n값 입력 받음
	innings.assign(n, vector<int>(10, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> innings[i][j];
		}
	}

	//연산
	order[4] = 1; //4번 타자는 1번 선수
	check[1] = true; //1번 선수는 순서 정해짐
	array(1);

	//출력
	cout << ans;
	return 0;
}