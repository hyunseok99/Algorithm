#include <iostream>
#include <vector>
using namespace std;

int a, d, q;

void calc(int method, int l, int r) {
	if (l == r) {
		cout << a + (l - 1) * d << "\n";
		return;
	}

	if (method == 1) {
		// ex) 1 1 2 -> a + a+d -> 1*2/2 - 0
		// ex) 1 4 8 -> sum of a+3d ~ a+7d  -> 7*8/2 - 2*3/2
		// ex) 1 x y -> a+(x-1)d + a+(x)d + a(x+1)d ... +a(y-1)d
		// -> a * (y-x+1) + (y-1)*y/2 - (x-2)*(x-1)/2 
		long long ans = a * (r - l + 1) + ((r - 1) * r / 2 - ((l - 2) * (l - 1)) / 2) * d;
		cout << ans << "\n";
		return;
	}
	else {
        	// d = 0 인 경우
        if (d == 0) {
            cout << a << "\n";
            return;
        }
		// ex) 2 4 8 -> min divisor of a+3d ~ a+7d
		// 최소 공약수가 x 
		// 4 6 8 10 12-> 2*2 , 2*3 , 2*2*2 ,2*5, 2*3*2
		// 4 10 16 22 ->  2 5 8 11  -> d:6, x:2 -> 몫들의 등차는 d/x 3
		// 5 10 15 20 -> 1 2 3 4 -> d:5, x:5 -> 등차 1
		// 15 17 19 21 -> d:2, x:1
		// |4| 8 12 16 -> d:4, x:4 -> 등차 1 
		// -> 기존 등차의 약수중에 공약수 존재: 초항과 공차의 최대 공약수 
		// a와 d의 최대 공약수가 l~r까지의 최대 공약수
		int a0 = a;
		int d0 = d;
		if (a < d) {
			int tmp = a;
			a0 = d;
			d0 = a;
		}
		// 최대 공약수: a%d의 나머지가 0인 경우가 될 때까지
		// 11 4 -> 4 3 -> 3 1 -> 1
		// 8 4 -> 4 
		while (1) {
			int remain = a0 % d0;
			if (remain != 0) {
				a0 = d0;
				d0 = remain;
			}
			else {
				cout << d0 << "\n";
				break;
			}
		}
	}

}

int main() {
	cin >> a >> d >> q;
	for (int i = 0; i < q; i++) {
		int method, l, r;
		cin >> method >> l >> r;
		calc(method, l, r);
	}

	return 0;
}