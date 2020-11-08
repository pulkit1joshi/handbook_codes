
// Most Basic implementation of segment tree and properly commmented  :

#include <bits/stdc++.h>
using namespace std;

// Original Array that stores the input
int A[200000]={INT_MAX};
// Array that stores the segment tree
int tree[800005] = {INT_MAX};

// Segment tree have 3 parts
// 1. Build Tree
// 2. Query the Tree
// 3. Update the tree and array

// Building tree using recursion 
// L = left boundary of the input array
// R = right boundary of the input array
// Now if L==R then this is the leaf for the tree of end of the array
// l>r then it is invalid case
// If not lead, divide the array into two, and save there sum to tree[2*node] and tree[2*node+1]
// Finally save tree[node] = tree[node*2]+tree[node*2+1];

void build(int treenode,int l,int r)
{

	if(l==r) {tree[treenode] = A[l];return;}
	if(l>r) return;
	int mid = (l+r)/2;
	build(treenode*2,l,mid);
	build(treenode*2+1,mid+1,r);
	tree[treenode] = min(tree[treenode*2],tree[treenode*2+1]);

}

// Querying the segment tree
// L and R store the range of the segment tree being checked.
// ql and qr the are query ranges
// if L and R are withign the query ranges just return the segment value (why do down?)
// If L and R are outside the query range (not overlaping at all) simply return the int max
// Else if partial overlapping is present, just divide the tree into two sides and traverse

int query(int node,int l,int r,int ql,int qr)
{
	if(l>qr || r<ql) return INT_MAX;
	if(ql<=l && qr >= r) return tree[node];
	int mid = (l+r)/2;
	int left = query(2*node,l,mid,ql,qr);
	int right = query(2*node+1,mid+1,r,ql,qr);
	return min(left,right);
}

// Updating the tree

void update(int node,int l,int r,int pos,int val)
{
	if(l==r){ tree[node]=val,A[pos]=val;return; }
	if(l>r) return;
	int mid=(l+r)/2;
	if(pos>=l && pos<=mid)
		update(node*2,l,mid,pos,val);
	else update(node*2+1,mid+1,r,pos,val);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}



int main() {

	// Taking input 
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n;i++) A[i]=INT_MAX;
	for(int i=0;i<n;i++) cin >> A[i];
	for(int i=0;i<=4*n+1;i++) tree[i] = INT_MAX;
	//-------------------------------------
	build(1,0,n-1);
	//for(int i=0;i<4*n;i++) cout << tree[i] << " ";
	while(q--)
	{
		char x;int l;int r;
		cin >> x >> l >> r;
		if(x=='q')
			cout << query(1,0,n-1,l-1,r-1) << endl;
		else update(1,0,n-1,l-1,r);
	}
	
}

