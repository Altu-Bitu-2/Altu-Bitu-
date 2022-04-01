#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //�湮 �˻� �迭
vector<vector<int>> matrix; //��� ���
int n, ans = INF; //�ּ� ��� ���� ���� �̸� �ִ����� �ʱ�ȭ

/**
 * !�����غ���! �Լ��� �� ���ڴ� ���� � ������ �ϰ� �ֳ���?
 */
void backtracking(int cnt, int cur_city, int cost) { //�湮�� ���� ��, ���� �ִ� ����, ���
	if (cost >= ans) { //����� �ּҺ�뺸�� Ŭ ���
		return; 
	}
	if (cnt == n) { //���� ���� : n���� ���ø� ��ȸ����
		//��� ����(0)�� �ٽ� ���ƿ� �� �ִ��� Ȯ��
		if (matrix[cur_city][0] != 0) { //������ ���ÿ��� ��ߵ��÷� �� �� �ִٸ�
			ans = min(ans, cost + matrix[cur_city][0]); //������� ����
		}
		return;
	}
	for (int i = 0; i < n; i++) { //cur_city���� ���� i�� �̵�
		if (matrix[cur_city][i] && !visited[i]) { //���� �ְ�, ���� �湮���� ���� ����
			visited[i] = true; //�湮�ߴٰ� ����
			backtracking(cnt + 1, i, cost + matrix[cur_city][i]); //���� ���� ����
			visited[i] = false; //��ȸ�� �� ���� �湮���� ���·� ����
		}
	}
}

/**
 * ��Ʈ��ŷ Ǯ�� (4ms)
 *
 * �� ����Ŭ�� �����, ��� ���ÿ��� �����ϵ� ���� �����Ƿ� 0�� ���ú��� �����ϴ� ��츸 �˻��ϸ� �ȴ�.
 */

int main() {
	//�Է�
	cin >> n; //������ �� �Է� ����
	visited.assign(n, false); //�湮 ���� 
	matrix.assign(n, vector<int>(n, 0)); //�湮 ���
	for (int i = 0; i < n; i++) { //n�� ��
		for (int j = 0; j < n; j++) { //n�� ��
			cin >> matrix[i][j]; //��� ��� �Է¹޾� matrix�� ����
		}
	}

	//����
	visited[0] = true; //��� ����
	backtracking(1, 0, 0);

	//���
	cout << ans; //�ּ� ��� ���
	return 0;
}