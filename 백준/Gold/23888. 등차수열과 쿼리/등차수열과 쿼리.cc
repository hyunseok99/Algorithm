#include <iostream>
#include <vector>
using namespace std;

long long a, d, q;

long long remain(long long x, long long y){
	if( x < y ){
		long long tmp = x;
		x = y;
		y = tmp; 
	}
	if(y == 0 ) return x;
	return remain(y, x%y);
}

void calc(int method, long long l, long long r) {	
	if(method == 1){
		// ex) 1 4 8 -> sum of a+3d ~ a+7d  
		// ex) 1 x y -> a+(x-1)d + a+(x)d + a(x+1)d ... +a(y-1)d
		// -> a * (y-x+1) + (y-1)*y/2 - (x-1)*x/2 
		// 등차수열의 합: n{2a+(n-1)d}/2
		long long ans = ((r*(2*a + (r-1)*d)) - ((l-1)*(2*a + (l-2)*d)))/2 ;
		cout << ans << "\n";
		return;
	}else{

		if(l == r){
			cout << a + (l-1)*d << "\n";
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
		cout << remain(a, d) << "\n";
	}

}

int main() {
	cin >> a >> d >> q;
	for (int i = 0; i < q; i++) {
		int method;
		long long l,r;
		cin >> method >> l >> r;
		calc(method, l, r);
	}
	
	return 0;
}