//�������� ����������
#define E 0.0000001

/*
������� ���������� ��������, ������� ����� ����������� �� ��������� �� ����� ��� �� 0.0001
*/

double sqrt(double x) {
	double min, max, guess;

	min = 0;
	max = x;

	while (max - min > E) {
		guess = (min + max) * 0.5;
		if (guess * guess > x)
			max = guess;
		else min = guess;
	}

	return max;
}

double fabs(double x) {
	if (x > 0)
		return x;
	else return x * -1;
}

/*
������� ���������� 0, ���� ��� ����� ������ �������, � 1 � ��������� ������
*/
int test_sqrt() {
	int r;

	r = 0;

	r = r || (fabs(sqrt(25) - 5.0) >= E);
	r = r || (fabs(sqrt(1) - 1.0) >= E);
	r = r || (fabs(sqrt(0) - 0.0) >= E);
	r = r || (fabs(sqrt(10000) - 100.0) >= E);

	return r;
}

int main(int argc, char** argv) {
	return test_sqrt();
}