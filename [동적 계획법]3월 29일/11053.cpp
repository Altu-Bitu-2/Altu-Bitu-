#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 1.
 *
 * �����ڷ� ��ȭ��
 *
 * �ð� ���⵵ O(n^2)
 */
int lis(int n, vector<int> &arr) { //���� ũ��, ���� ����
	vector<int> dp(n, 1); //������ ũ�⸸ŭ ���� ������ �� 1�� �ʱ�ȭ
	int ans = 1; 

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) { //�����ϴ� ������
				dp[i] = max(dp[i], dp[j] + 1); //j,i��° �� �� �� �� �����ϴ� ������ dp[i]�� ����
			}
		}
		ans = max(ans, dp[i]); //���� ���� ����
	}
	return ans;
}

/**
 * 2.
 *
 * dp[i] : �����ϴ� �κ� ������ ���̰� i�� �� �߿� ���� ���� ��
 * idx : ���� �� �����ϴ� �κ� ������ ����
 *
 * �ð� ���⵵ O(nk) (k�� idx�� ũ��)
 *
 * -> k�� n�� �� �� �����Ƿ� �̷л� �ð����⵵�� O(n^2)���� ����������,
 *    �����ϴ� ������ �� break�� �������ν� ���� ����Ƚ���� �� ��� 1�� �Լ����� ���� Ǯ��
 *
 * �ؼ� : https://myunji.tistory.com/214
 */
int lisAdv(int n, vector<int> &arr) {
	vector<int> dp(n + 1, 0); //dp[1]�� �����ϱ� ���� dp[0] = 0���� ����
	int idx = 0; //���� �� �����ϴ� �κ��� ���� ����

	for (int i = 0; i < n; i++) {
		for (int j = idx; j >= 0; j--) {
			if (arr[i] > dp[j]) { //�����ϴ� ������
				dp[j + 1] = arr[i];
				if (j == idx) { //���� ���� ����
					idx++;
				}
				break; //���� ���̰� �ƴϸ� �ߴ�
			}
		}
	}
	return idx;
}

/**
 * 3.
 *
 * lisAdv���� line 36~43�� ������ �̺�Ž������ ����
 *
 * �ð� ���⵵ O(nlogk) (k�� dp�� ũ��)
 * �ؼ� : https://myunji.tistory.com/270
 */
int lisFinal(int n, vector<int> &arr) {
	vector<int> dp;

	for (int i = 0; i < n; i++) {
		int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin(); //arr[i] �̻��� ���� ó�� ������ ��ġ
		if (pos == dp.size()) { //arr[i]�� ���� ũ�ٸ� pos ���� dp.size()�� ���� -> ���� ���� ����
			dp.push_back(arr[i]); //���� ���� ����
		}
		dp[pos] = arr[i]; //dp[pos]�� ���� arr[i]�̻��̹Ƿ� �� ���� arr[i]�� ���� �����
	}
	return dp.size();
}

int main() {
	int n;

	//�Է�
	cin >> n; //n�� �Է� ����
	vector<int> arr(n, 0); //���� �Է¹��� ����
	for (int i = 0; i < n; i++) { //���� �Է¹���
		cin >> arr[i];
	}

	//���� & ���
	cout << lis(n, arr);
	return 0;
}