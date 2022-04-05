#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 8; //�迭 ũ��

int n, m;
vector<int> num(SIZE); //size�� ���Ҹ� ������ num���� ����
vector<int> ans(SIZE); //size�� ���Ҹ� ������ ans ���� ����
vector<bool> check(SIZE); //�ߺ� ���� ���� check ���� ����

void backtracking(int cnt) {
	if (cnt == m) { //���� m �̶�� (��������)
		for (int i = 0; i < m; i++) { //m�� �ݺ�
			cout << ans[i] << ' '; //ans ���
		}
		cout << '\n';
		return;
	}
	int prev = 0; //������ ������ ��
	for (int i = 0; i < n; i++) { //n�� �ݺ�
		if (!check[i] && prev != num[i]) { //�� ��ġ �ߺ� üũ && ������ Ž���� ���� �ƴ϶��
			prev = num[i]; //num�� ������ ������ ���� ����
			ans[cnt] = num[i]; //ans �迭�� �ֱ�
			check[i] = true; //check �迭 true�� �ؼ� �ߺ� üũ
			backtracking(cnt + 1);
			check[i] = false; ///check �迭 false�� ����
		}
	}
}

/**
 * 1. �켱 ������ ���� ������ �����ϴ� ������ ����ؾ� �ϹǷ� �־��� ������ �������� ����
 * 2. �� ���¿��� �켱, ���� ��ġ�� ���� �� �������� �ʵ��� �ߺ����� (check �迭 ���)�� ����
 * 3. �� ��, �ߺ��Ǵ� "����"�� �Ÿ��� ����� ������ ������ ���� ������ �����ؼ�, ������ ����� �ٽ� ��Ʈ ���� ���ƿ��� ��
 *    ������ ������ ���� ���� ���̸� �Ѿ�� ��! -> ������ ���� ���̹Ƿ� ���� ���� �ݺ��ؼ� �Ȱ��� ������ ���� ��
 */

int main() {
	//�Է�
	cin >> n >> m;
	for (int i = 0; i < n; i++) { //n�� �ݺ�
		cin >> num[i]; //n���� �� �Է� ����
	}

	//����
	sort(num.begin(), num.begin() + n); //��������

	//��Ʈ��ŷ & ���
	backtracking(0);
	return 0;
}