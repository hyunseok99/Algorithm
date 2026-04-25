#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<double> s;
string str;

int main() {
	int n;
	cin >> n>>str;
	double* arr = new double[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < str.size(); i++) {
		double x, y;

		if (str[i] >= 'A' && str[i] <= 'Z') {//피연산자 대응 값 push
			s.push(arr[str[i] - 'A']);
		}
		else { //계산 해야 할 두 값 계산해서 push
			x = s.top();
			s.pop();
			y = s.top();
			s.pop();

			if (str[i] == '+') {
				s.push(x + y);
			}
			else if (str[i] == '-') {
				s.push(y - x);
			}
			else if (str[i] == '*') {
				s.push(x * y);
			}
			else if (str[i] == '/') {
				s.push(y / x);
			}
		}
	}
	printf("%0.2f", s.top());
}