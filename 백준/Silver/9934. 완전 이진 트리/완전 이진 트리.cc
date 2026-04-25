#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector<int> v(1024);
vector<int> Comp_tree(1024); //완전이진트리 


void func(int , int);
int k;
int idx = 0;

int main() {
	cin >> k; //=depth
	for (int i = 0; i < pow(2, k)-1; i++) {
		cin >> v[i];
	}
	func(1, 1);
	idx = 1;
	for (int i= 0; i < k; i++) {
		int count = 1;
		for (int j = 0; j < i; j++) count *= 2;
		for (int j = 0; j < count; j++) {
			cout << Comp_tree[idx++] << " ";
		}
		cout << "\n";
	}

}

void func(int temp, int depth) {
	if (depth == k) Comp_tree[temp] = v[idx++];
	else {
		func(temp * 2, depth + 1); // left child
		Comp_tree[temp] = v[idx++]; 
		func(temp * 2 + 1, depth + 1); //right child
	}
}