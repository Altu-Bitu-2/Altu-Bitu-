#include <iostream>

using namespace std;

// ��Ŭ���� ȣ����
int gcdRecursion(int a, int b) {
	// a > b �� ��, a�� b�� �ִ������� ����
	if (b == 0) {
		return a;
	}
	return gcdRecursion(b, a % b);
}

int main() {
	string s;

	//�Է�
	cin >> s;

	//����(�Է����κ��� n, m �����ϱ�)
	int index = s.find(':'); //':' ��ġ ã��
	int n = stoi(s.substr(0, index)); //: ������ ���ڸ� ���ڷ� ����
	int m = stoi(s.substr(index + 1, s.length())); //: ���� ���ڸ� ���ڷ� ����

	//�ִ����� ���ϱ�
	int g = gcdRecursion(max(n, m), min(n, m));

	//���
	cout << n / g << ':' << m / g << '\n';

	return 0;
}