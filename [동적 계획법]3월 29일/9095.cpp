#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10; //MAX�� ��� 10���� ����

//bottom-up ��� dp �迭 ä���
vector<int> numberOfAllCases() { //vector<int>�� ��ȯ�ϴ� �Լ�
	vector<int> dp(MAX + 1, 0); 

	dp[0] = dp[1] = 1; //0,1�϶� 1�� �ʱ�ȭ
	dp[2] = 2; //2�϶��� �ΰ��� ��
	for (int i = 3; i <= MAX; i++) { //MAX-3�� �ݺ�
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp;
}

/**
 * [bottom-up ����]
 * �� ���� �ε����� �Ἥ ���� n���� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ��������!
 *
 * �켱 3���� 1, 2, 3�� ������ ��Ÿ���� ����� �� �ʱ�ȭ ��
 * �ش� �ε������� -1, -2, -3 �� �ε����� +1, +2, +3�� ����ٰ� �����ϸ� ��
 *
 * -> dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3] (n >= 3)
 *
 * �ش� Ǯ�̴� �ε��� ������ ���ϰ� �ϱ� ���� 0�� ���� �ε����� �༭ �ε��� 3���� ����
 * �׽�Ʈ���̽��� �Է��� ������, �Է� ������ 11�� �۱� ������ �̸� dp �迭 ä��� �����ϴ� ���� �� ȿ����
 */

int main() {
	int t, n;

	//�̸� dp ä���
	vector<int> dp = numberOfAllCases(); 

	//�Է�
	cin >> t; //t �Է� �ޱ�
	while (t--) { //t�� 0�� �ɶ�����
		cin >> n; //n�Է� �ޱ�

		//���
		cout << dp[n] << '\n';
	}
	return 0;
}