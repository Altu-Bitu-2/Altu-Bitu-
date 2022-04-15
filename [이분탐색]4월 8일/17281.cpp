#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings; //2���� �迭
vector<int> order(10, 0); //Ÿ��
vector<bool> check(10, false); //���� ���� ���� ���� �迭
int n, ans;

//�� ��Ÿ���� ��� ����
int hitScore(int hit, vector<bool> &baseman) {
	int score = 0; //���� �ʱ�ȭ
	for (int i = 3; i >= 0; i--) {
		if (!baseman[i]) { //���� ����� ������ ������
			continue; //�ݺ�
		}
		if (i + hit >= 4) { //������ ���� ���� ����� ���� ���� 4���� ũ��
			score++; //score ����
		}
		else {
			baseman[i + hit] = true; //����� ������������ ǥ��
		}
		baseman[i] = false; //����� ���� ���� ǥ��
	}
	if (hit == 4) { //Ȩ���̸�
		score++; //���� ����
	}
	else {
		baseman[hit] = true; //���ο� ������ Ȩ�� ����
	}
	return score; //���� ����
}

//���� ��ġ�� ����
int calcScore() {
	int score = 0; //�� ����
	int idx = 1; //Ÿ�� ����� order �ε��� ��ȣ
	for (int i = 0; i < n; i++) { //i: �̴�
		vector<bool> baseman(4, 0); //�� ������� ������ �ִ���
		int out = 0; //�ƿ� ���� ī��Ʈ
		while (out < 3) { //3out���� �ݺ�
			int state = innings[i][order[idx++]]; //���� ������ ���� ����
			if (idx == 10) { //�������� �� ���� ��������
				idx = 1; //ù Ÿ��
			}
			if (state == 0) { //���� ������ ���ݻ��°� 0�϶�
				out++; //out ����
			}
			else {
				score += hitScore(state, baseman); //hit�Լ� ȣ��
			}
		}
	}
	return score; //���� ��ȯ
}

//������ ��ġ ��� ���ϱ�
void array(int cnt) { //cnt: Ÿ�ڼ���
	if (cnt == 4) { //4�� Ÿ�ڴ� ������ �����Ƿ�
		array(cnt + 1);
		return;
	}
	if (cnt == 10) { //9�� Ÿ�ڱ��� ������ (��������)
		int score = calcScore(); //���� ���
		ans = max(ans, score);
		return;
	}
	for (int i = 2; i <= 9; i++) {
		if (!check[i]) { //i�� ���� ������ �������� �ʾҴٸ�
			order[cnt] = i; //cnt�� Ÿ��: i�� ����
			check[i] = true; //i�� ���� ���� ������
			array(cnt + 1); //���� Ÿ��
			check[i] = false; //i�� ���� ���� �������� ����
		}
	}
}

/**
 * ���� + ���Ʈ ����, ��Ʈ��ŷ
 * 1. �켱 ������ Ÿ���� ��� ���Ѵ�. (�̶�, 4�� Ÿ�ڴ� �׻� 1�� �������� ��) (���Ʈ ����, ��Ʈ��ŷ)
 * 2. ���� Ÿ���� ���� ������ ������ ���ϸ� �ִ� ������ �����Ѵ�. (����)
 */

int main() {
	//�Է�
	cin >> n; //n�� �Է� ����
	innings.assign(n, vector<int>(10, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> innings[i][j];
		}
	}

	//����
	order[4] = 1; //4�� Ÿ�ڴ� 1�� ����
	check[1] = true; //1�� ������ ���� ������
	array(1);

	//���
	cout << ans;
	return 0;
}