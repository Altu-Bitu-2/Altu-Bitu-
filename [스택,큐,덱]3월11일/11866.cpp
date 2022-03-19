#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> simulation(int k, queue<int> &q) {
	vector<int> result; //요세푸스 순열
	int cnt = 0; //카운트 변수

	while (!q.empty()) { //원소가 있을 경우 
		int x = q.front(); //맨 앞 원소에 저장
		q.pop(); //앞에 있는 원소 삭제
		cnt++;
		if (cnt == k) { //k번째 pop하는 원소라면
			result.push_back(x); //결과에 x 넣기
			cnt = 0; //0으로 초기화
			continue;
		}
		q.push(x); //pop한 원소 다시 push
	}
	return result;
}

/**
 * 1. 큐에 1 ~ N까지 값 초기화
 * 2. 이후 k 번째 사람 찾기 위해 pop, push 반복
 * 3. k번째 pop 일 경우 요세푸스 순열에 저장, 이후 원소 제거 (다시 push 하지 않음!)
 */

int main() {
	int n, k;
	queue<int> q;

	//입력
	cin >> n >> k; //n,k값 입력
	for (int i = 1; i <= n; i++) { //큐 초기화
		q.push(i); //q뒤에 i원소 삽입
	}
	//연산
	vector<int> result = simulation(k, q);
	//출력
	cout << '<'; //괄호 출력
	for (int i = 0; i < result.size() - 1; i++) {
		cout << result[i] << ", "; //result 출력
	}
	cout << result[result.size() - 1] << '>'; //괄호 출력
	return 0;
}