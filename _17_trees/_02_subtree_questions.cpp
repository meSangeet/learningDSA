#include<bits/stdc++.h>
using namespace std;

int even_ct[10] = {0}, subtree_sum[10] = {0};

void dfs(vector<vector<int>> &tree, int vertex, int par = 0)
{
	subtree_sum[vertex] += vertex;
	if(vertex%2 == 0)
	{
		even_ct[vertex]++;
	}

	for(int child: tree[vertex])
	{
		if(par != child)
		{
			dfs(tree, child, vertex);
			subtree_sum[vertex] += subtree_sum[child];
			even_ct[vertex] += even_ct[child];
		}
	}
}

int main()
{
	int n; cin>>n;
	vector<vector<int>> tree(n+1);

	for(int i = 1; i<=n-1; i++)
	{
		int p,q; cin>>p>>q;
		tree[p].push_back(q);
		tree[q].push_back(p);
	}
	dfs(tree, 1);

	for(int i = 1; i<=n; i++)
	{
		cout<<i<<" - "<<even_ct[i]<<" "<<subtree_sum[i]<<endl;
	}
	return 0;
}