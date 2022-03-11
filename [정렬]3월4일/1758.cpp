#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calTip(int n, vector<int> &tips) { 
	long long ans = 0;
	for (int i = 0; i < n; i++) { //��� �� n��ŭ �ݺ�
		int cur_tip = tips[i] - i;//  �� �մ��� ��ȣ���� ���� �ַ��� �����ߴ� �� - (���� ��� - 1)
		if (cur_tip < 0) //������ ���� ������ �ʴµ� ó���� �������� ���������Ƿ� �ƿ� break
			break;
		ans += cur_tip;
	}
	return ans;
}

/**
 * ��ȣ�� ���� �� �ִ� ���� �ִ��� �Ƿ��� ���� ���� ����� ������ ���ƾ���
 * !����! �־����� N�� �ִ� ũ�Ⱑ 100,000�̰� ���� �ִ� ũ�Ⱑ 100,000�̹Ƿ�
 *       ������ �ִ��� 10^5 * (10^5+1) / 2�� int ������ �ѱ� ������ long long �� ��� ��
 */

int main() {
	int n;

	//�Է�
	cin >> n; //n�� �Է¹޴´�
	vector<int> tips(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> tips[i]; //��� �� n�� ��ŭ �� �մ��� ��ȣ���� ���� �ַ��� ������ ���� �Է¹���
	}
	//����
	sort(tips.begin(), tips.end(), greater<>()); //�������� ����
	//���
	cout << calTip(n, tips) << '\n'; //calTip ���
	return 0;
}