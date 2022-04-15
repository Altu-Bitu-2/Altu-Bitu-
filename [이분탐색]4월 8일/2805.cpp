#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int> &tree) { //���� �ڸ��� �Լ�
	ll sum = 0; //�ڸ� ������ �� ������ sum ���� ����
	for (int i = 0; i < tree.size(); i++) {
		if (height >= tree[i]) { //���� �ڸ����� ���̰� ���� ���̺��� ũ�ٸ�
			return sum; //sum ����
		}
		sum += (tree[i] - height); //�ڸ����� sum ����
	}
	return sum; //sum ����
}

int upperSearch(int left, int right, int target, vector<int> &tree) { //�߶���� �������� ���� Ž�� 
	while (left <= right) { //left�� right���� �������� �ݺ�
		int mid = (left + right) / 2; //mid�� ����
		ll tree_cnt = cntTree(mid, tree); //mid ��ŭ �ڸ� ���̸� tree_cnt ������ ����

		if (tree_cnt >= target) { //���� tree_cnt�� target���̺��� ũ�ٸ� �� �ڸ� ���
			left = mid + 1; //left ������ ������
		}
		else {//�� �ڸ� ���
			right = mid - 1; //right ������ ��������
		}
	}
	return left - 1; //left-1��ȯ
}

/**
 * [���� �ڸ���]
 *
 * ��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ� ������ �ִ���?
 * -> ���ܱ��� ���̰� k(������ ��)�� ��, M������ ������ ���� ������ �� �ִ°�?
 *
 * left: ���ܱ��� �ּ� ���� -> 0
 * right: ���ܱ��� �ִ� ���� -> �־��� ���� �� ���� ���� ���� ����
 *
 * !����! int �ڷ��� ������ �Ѿ�Ƿ� long long��� ��
 */

int main() {
	int n, m;

	//�Է�
	cin >> n >> m; //n,m �Է� ����
	vector<int> tree(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	sort(tree.begin(), tree.end(), greater<>()); //�������� ����

	//���� & ���
	cout << upperSearch(0, tree[0], m, tree); //���
	return 0;
}