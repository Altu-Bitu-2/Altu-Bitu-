#include <iostream>
#include <vector>

using namespace std;

int findRanking(int n, int new_score, int p, vector<int> &ranking) {
	int idx = 1; //�ε���
	int ans = 1; //���
	//���ο� ������ ��� ��ġ�� ������ Ž��
	while (idx <= n) { //n���ϱ��� �ݺ�
		if (new_score > ranking[idx]) { //���ο� ������ �ε��� ��ŷ���� ���� ���
			break; //����
		}
		if (new_score < ranking[idx]) { //���ο� ������ �ε��� ��ŷ���� ���� ���
			ans = idx + 1; //�ε���+1�� ���
		}
		idx++; //�ε��� ����
	}
	if (idx == p + 1) { //��ŷ ����Ʈ�� ���� ���ϴ� ���
		return -1; //-1��ȯ
	}
	return ans;//��� ��ȯ
}

/**
 * [��� ���ϱ�]
 *
 * 1. n = 0�� ��, ���
 * 2. ����� p���� ������, ������ �� ���� ���� ��ŷ�� ���ŵǹǷ� ��ŷ ����Ʈ�� ���� ���ϴ� ��� ��� (����)
 *
 * ���� ��ŷ�� �ö� n���� ����� ���ο� ������ ���ϸ� ���ο� ���� �� ������ ���
 * ���ο� ������ ���� Ž�� ����� �������� �۴ٸ� -> ���� Ž�� ��� + 1
 * ������ ��� -> �� �� ��� �״�� ��� -> �ƹ� ó���� ���� ����!
 */

int main() {
	int n, new_score, p;

	//�Է�
	cin >> n >> new_score >> p; //n, ����, p �Է� ����
	vector<int> ranking(p + 1, 0); //���� p+1�� ���� 0���� �ʱ�ȭ
	for (int i = 1; i <= n; i++) { //n�� �ݺ�
		cin >> ranking[i]; // ��ŷ ���� �Է�
	}

	//���� & ���
	cout << findRanking(n, new_score, p, ranking); 
	return 0;
}