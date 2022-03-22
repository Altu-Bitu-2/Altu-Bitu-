#include <iostream>
#include <vector>
#include <algorithm>    // sort() ���
#include <numeric>      // accumulate() ���
#include <cmath>        // floor() || round() ���

using namespace std;

typedef pair<int, int> ci;  // pair<int, int>�� ci��� ��Ī �ο�

// ���Լ�
bool cmp(const ci &a, const ci &b) {
	if (a.second == b.second) { //a.second�� b.second�� ���� ��
		return a.first < b.first;
	}
	return a.second > b.second;
}

int findMode(int n, vector<int> &arr) {
	// ���ĵ� ���Ϳ��� �ֺ��� ã�� ��ȯ�ϰ�, ���� �ֺ��� ��������� �ι�°�� ���� ���� ��ȯ�ϴ� �Լ�
	vector<ci> count;   // ������ ���� �ش� ���� ������ pair�� ��� �����ϴ� ����
						// first: ��, second: ����

	int current_idx = 0;    // ������ �ε����� �����ϴ� ����
	count.push_back({ arr[0], 1 });   // ù��° ���� �Է��Ͽ� for������ index ���� ����

	for (int i = 1; i < n; i++) {
		// ���� ���� ���� ���� ���̶��
		if (arr[i] == arr[i - 1]) {
			count[current_idx].second++;
		}
		else {
			// �׷��� �ʴٸ�, ���ο� ���� count ���Ϳ� ����
			count.push_back({ arr[i], 1 });
			current_idx++;
		}
	}

	// ���� ���� �� �������, �ٷ� ���� -> �Ʒ����� �ε��� ���� ����
	if (current_idx == 0) {
		return arr[0];
	}

	// ����
	// 1. ����(first)�� ���� ��������
	// 2. ��(second)�� ���� ��������
	sort(count.begin(), count.end(), cmp);

	// �ֺ� ���� ���������� Ȯ��
	if (count[0].second == count[1].second) {
		return count[1].first;
	}
	return count[0].first;
}

/**
 * [�����]
 * 1. ��� ��� ��� �� �Ǽ� �ڷ��� ���, �ݿø��� ����
 * 2. n�� Ȧ�� �̹Ƿ� �߾Ӱ��� �׻� (n/2)��° �ε���
 * 3. �ֺ��� ������ �󵵼� ������ �� ��°�� '����' ��
 * 4. �ֺ��� ������ ��� ���
 */

int main() {
	int n;
	cin >> n; //n�� �Է�

	// n �ִ� 500,000 * �Է°� �ִ� 4,000 = 2,000,000,000 <- int ���� ��
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; //arr�迭 0~n���� ���Է�
	}
	sort(arr.begin(), arr.end());
	// ������
	int sum = accumulate(arr.begin(), arr.end(), 0);
	// round() �Լ��� ����� ���� �־��. �ٸ� -0�� ������ �ʵ��� ���ǹ��� ����ؾ� �մϴ�.
	cout << floor((double)sum / n + 0.5) << '\n'; //floor�� ���

	// �߾Ӱ�
	cout << arr[n / 2] << '\n'; //�߾Ӱ� ���

	// �ֺ�
	cout << findMode(n, arr) << '\n'; //�ֺ� ���

	// ����
	cout << arr[n - 1] - arr[0] << '\n'; //���� ���
}