#include <iostream>
#include <string>

using namespace std;

char input[10000][11];

struct TRIE {
	
	bool Finish;
	TRIE *Node[10];
	TRIE() {
		Finish = false;
		for (int i = 0; i < 10; i++) {
			Node[i] = NULL;
		}
	}

	void insert(char *str) {
		if (*str == '\0') {
			Finish = true;
			return;
		}
		int Cur = *str - '0';
		if (Node[Cur] == NULL) Node[Cur] = new TRIE();
		Node[Cur]->insert(str + 1);
	}

	bool find(char *str) {
		//끝까지 도달하면 return false
		if (*str == '\0') {
			return false;
		}
		//중간에 finish가 있으면 일관성 x (어떤 전화번호가 다른 전화번호의 접두어가 되면)
		if (Finish == true)
			return true;

		int Cur = *str - '0';
		if (Node[Cur] == NULL) return false;
		return Node[Cur]->find(str + 1);
	}


};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		TRIE *Root = new TRIE();
		for (int i = 0; i < n; i++) {
			cin >> input[i];
			Root->insert(input[i]);
		}
		int i;
		for(i=0; i<n;i++){
			if (Root->find(input[i])) {
				cout << "NO\n";
				break;
			}
		}
		if (i == n)
			cout << "YES\n";
	}

	return 0;
}