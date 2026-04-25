#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
long long res = 3000000001;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	vector<long long> solvent(n);
	for(int i=0; i<n; i++){
		cin >> solvent[i];
	}
	// 정렬
	sort(solvent.begin(), solvent.end());

	// 0에 가까워지도록 

	vector<int> idx;
	for(int i=0; i<=n-3; i++){
		int fix = i;
		int left = i+1;
		int right = n-1;
		while(left < right){
			long long sum = solvent[fix] + solvent[left] + solvent[right];
			long long absSum = abs(sum);
			if(absSum < res){
				res = absSum;
				idx.clear();
				idx.push_back(i);
				idx.push_back(left);
				idx.push_back(right);
			}
			if(sum > 0){
				// 산성 감소 필요
				right--;
			}else if(sum < 0){
				// 알칼리 감소 필요
				left++;
			}else{
				// 0인 경우 끝
				break;
			}
		}
	}

	for(int i=0; i<3; i++){
		cout << solvent[idx[i]] << " ";
	}
	
	return 0;
}