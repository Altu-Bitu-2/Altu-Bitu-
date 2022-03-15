#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/**
 * [���ܾ� �켱����]
 * 1. ���� ������ �ܾ��ϼ��� �տ� ��ġ
 * 2. �ش� �ܾ��� ���̰� ����� �տ� ��ġ
 * 3. ���ĺ� ���� ������ �տ� �ִ� �ܾ��ϼ��� �տ� ��ġ
 */

map<string, int> word_cnt;

bool cmp(const string &a, const string &b) {
	if (word_cnt[a] != word_cnt[b]) { //���� ������ �ܾ��ϼ��� �տ� ��ġ
		return word_cnt[a] > word_cnt[b];
	}
	if (a.length() != b.length()) { //�ش� �ܾ��� ���̰� ����� �տ� ��ġ
		return a.length() > b.length();
	}
	return a < b; //���ĺ� ���� ������ ��ġ
}

int main() {
	//����� �ӵ� ���
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> words;
	string word;
	int n, m;

	//�Է�
	cin >> n >> m; //n,m�� �Է� �޴´�

	//�Է� + ���ܾ� Ƚ�� ����
	while (n--) {
		cin >> word; //word �Է¹���
		if (word.length() < m) { //���̰� m �̸��̸� ���ܾ��忡 ���� ����
			continue;
		}
		//map�� key�� �����ϴ��� �� ���� �����ڷ� ��� �Ǵ��� �����ұ��? ����Ƽ�� "�̰͵� �˾ƺ�����"�� �����ص� ���ƿ�!
		if (!word_cnt[word]) { //�ߺ� ���ܾ� ���� �� ����
			words.push_back(word);
		}
		word_cnt[word]++; //word �ܾ� Ƚ�� ����
	}

	//���ǿ� �°� ����
	sort(words.begin(), words.end(), cmp); //cmp���Ǵ�� ����

	//���
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << '\n'; //words[]������� ���
	}
	return 0;
}