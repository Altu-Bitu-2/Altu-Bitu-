#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//함수 S의 계산
int calcS(int n, vector<int> a, vector<int> b) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += (a[i] * b[i]); //S = A[0] × B[0] + ... + A[N-1] × B[N-1]
	}
	return s;
}

/**
 * 문제에서 B를 재배열하지 말라곤 했지만, 해야하는 문제
 * 각 배열에서 가장 큰 값과 가장 작은 값을 곱해야 최솟값이 나옴!
 */

int main() {
	int n;
	vector<int> a, b;

	//입력
	cin >> n; //n을 입력받음
	a.assign(n, 0);
	b.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; //둘째 줄에 a에 n개의 수를 입력받음
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i]; //셋째 줄에는 b에 n개의 수를 입력받음
	}

	//연산
	sort(a.begin(), a.end()); //오름차순 정렬
	sort(b.begin(), b.end(), greater<>()); //내림차순 정렬
	int result = calcS(n, a, b); 

	//출력
	cout << result; //result값 출력
	return 0;
}