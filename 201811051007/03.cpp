//3.1
#include <iostream>
#include <algorithm>

using namespace std;

struct student {
	int chinese;//���ĳɼ�
	int math;//��ѧ�ɼ�
	int english;//Ӣ��ɼ�
	int num;//���
	int sum;//�ܷ�
}s[301];

int cmp(student p1, student p2) {//�ṹ��
	if (p1.sum == p2.sum && p1.chinese != p2.chinese) {//�ܷ���ͬ�����ĳɼ�������ǰ
		return p1.chinese > p2.chinese;
	}
	if (p1.sum == p2.sum && p1.chinese == p2.chinese) {//�ܷ���ͬ�����ĳɼ���ͬ�����С��ǰ
		return p1.num < p2.num;
	}
	else {//�����ܷ�Խ����Խǰ
		return p1.sum > p2.sum;
	}
}

int n;//����

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		s[i].num = i;
		cin >> s[i].chinese >> s[i].math >> s[i].english;
		s[i].sum = s[i].chinese + s[i].math + s[i].english;
	}
	sort(1 + s, 1 + n + s, cmp);//����

	for (int j = 1; j <= 5; j++) {//���ǰ5��
		cout << s[j].num << " " << s[j].sum << endl;;
	}
	return 0;
}
