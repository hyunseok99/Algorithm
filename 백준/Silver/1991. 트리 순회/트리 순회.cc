#include <iostream>
#include <map>
#include <string>
using namespace std;
map<char, pair<char, char>>tree;

void preorder(char);
void inorder(char);
void postorder(char);

int main() {
	int n;
	char a,b,c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin>>a>>b>>c;
		tree[a] = make_pair(b, c);
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	return 0;
}

void preorder(char node) {
	cout << node;
	if (tree[node].first != '.'){
		preorder(tree[node].first);
	}
	if (tree[node].second != '.') {
		preorder(tree[node].second);
	}
}

void inorder(char node) {
	if (tree[node].first != '.') {
		inorder(tree[node].first);
	}
	cout << node;
	if (tree[node].second != '.') {
		inorder(tree[node].second);
	}
}

void postorder(char node) {
	if (tree[node].first != '.') {
		postorder(tree[node].first);
	}
	if (tree[node].second != '.') {
		postorder(tree[node].second);
	}
	cout << node;
}