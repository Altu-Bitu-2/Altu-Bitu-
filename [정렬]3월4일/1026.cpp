#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�Լ� S�� ���
int calcS(int n, vector<int> a, vector<int> b) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += (a[i] * b[i]); //S = A[0] �� B[0] + ... + A[N-1] �� B[N-1]
	}
	return s;
}

/**
 * �������� B�� ��迭���� ����� ������, �ؾ��ϴ� ����
 * �� �迭���� ���� ū ���� ���� ���� ���� ���ؾ� �ּڰ��� ����!
 */

int main() {
	int n;
	vector<int> a, b;

	//�Է�
	cin >> n; //n�� �Է¹���
	a.assign(n, 0);
	b.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; //��° �ٿ� a�� n���� ���� �Է¹���
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i]; //��° �ٿ��� b�� n���� ���� �Է¹���
	}

	//����
	sort(a.begin(), a.end()); //�������� ����
	sort(b.begin(), b.end(), greater<>()); //�������� ����
	int result = calcS(n, a, b); 

	//���
	cout << result; //result�� ���
	return 0;
}