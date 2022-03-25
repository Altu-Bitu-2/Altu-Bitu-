#include <iostream>
#include <algorithm>

using namespace std;

string findNumber(string s) {
	bool isTen = false; //0�� �����ϴ��� Ȯ��
	int sum = 0; //3�� ������� Ȯ���ϱ� ���� �� ����

	//���鼭 3�� ����� 10�� ������� Ȯ��
	for (int i = 0; i < s.length(); i++) {
		sum += (s[i] - '0');
		if (s[i] == '0') {
			isTen = true;
		}
	}

	if (sum % 3 != 0 || !isTen) { //3�� ����� �ƴϰų�, 10�� ����� �ƴ϶��
		return "-1";
	}

	//���� ū �� ����� ���� �������� ����
	sort(s.begin(), s.end(), greater<>());
	return s;
}

/**
 * [30]
 * 30�� ��� = 10�� ��� && 3�� ���
 * 1. 10�� ��� -> �Էµ� ���� 0�� ���ԵǾ� �ִ��� Ȯ��
 * 2. 3�� ��� -> ��� �ڸ����� ���� 3�� ������� Ȯ��
 *
 * 30�� ������� Ȯ�� �Ǿ�����,
 * ���� ū ���� ����� ���� 9���� 0���� �������� �����Ѵ�.
 */

int main() {
	string s;

	//�Է�
	cin >> s;

	//���� & ���
	cout << findNumber(s);
	return 0;
}