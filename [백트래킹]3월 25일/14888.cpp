#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9; //��� �ִ밪
const int SIZE = 11; //N�� �ִ� ����

int n;
vector<int> num(SIZE + 1);
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX; //�ִ�, �ּҰ�

void backtracking(int cnt, int sum) { //cnt: �� �ε���, sum: ���� ���
	if (cnt == n - 1) { //���� ��� �Ϸ��ߴٸ� (��������)
		max_value = max(max_value, sum); //���� ����� �ִ밪 ���ϱ�
		min_value = min(min_value, sum); //���� ����� �ּҰ� ���ϱ�
		return;
	}
	for (int i = 0; i < 4; i++) { //������ �˻�
		if (expression[i]) { //�������� ���� 0�̻��̸�
			expression[i]--; //�������� �� 1����
			int new_sum = 0; //�ϳ��� ���� ���� �����
			switch (i) { //������ ������ ����
			case 0: //���� ����
				new_sum = sum + num[cnt + 1];
				break;
			case 1: //���� ����
				new_sum = sum - num[cnt + 1];
				break;
			case 2: //���� ����
				new_sum = sum * num[cnt + 1];
				break;
			case 3: //������ ����
				new_sum = sum / num[cnt + 1];
				break;
			}
			backtracking(cnt + 1, new_sum); //���� �� ����
			expression[i]++; //�������� �� ���� ���·� ����
		}
	}
}

/**
 * ������ ��� �������鼭 ��ġ�� ��, �� �����ڿ� ���� �� ���
 */

int main() {
	//�Է�
	cin >> n; //n �Է� ����
	for (int i = 0; i < n; i++) { //n�� �ݺ�
		cin >> num[i];  //����
	}
	for (int i = 0; i < 4; i++) { //4�� �ݺ�
		cin >> expression[i]; //�������� ����
	}

	//����
	backtracking(0, num[0]);

	//���
	cout << max_value << '\n' << min_value;
	return 0;
}