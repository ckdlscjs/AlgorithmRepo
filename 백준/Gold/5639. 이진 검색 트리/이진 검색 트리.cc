#include <bits/stdc++.h>
int node;
std::vector<int> trees;
void PostOrder(int s, int e)
{
	if(s >= e) return;
	int delim = s+1;
	while(delim < e)
	{
		if(trees[s] < trees[delim]) break;
		delim++;
	}
	PostOrder(s+1, delim);
	PostOrder(delim, e);
	std::cout << trees[s] << '\n';
}
int main() 
{
	while(std::cin >> node)
		trees.push_back(node);
	PostOrder(0, trees.size());
	return 0;
}