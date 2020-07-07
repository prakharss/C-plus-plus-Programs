#include <bits/stdc++.h>
using namespace std;

void segmentUtil(int a[],int start, int end, int *seg, int index) {
	if(start==end) { //leaf node
		seg[index]=a[start];	
		return ;
	}
	
	int mid=start+(end-start)/2;
	segmentUtil(a,start,mid,seg,2*index+1);
	segmentUtil(a,mid+1,end,seg,2*index+2);
	
	seg[index]=min(seg[2*index+1],seg[2*index+2]);
}

int *buildSegmentTreeForRMQ(int a[], int n) {
	/*
		total leaf node in segment tree to make it perfect binary tree = 2^(ceil(log2 N)) i.e next square root of n 
		n = 10 -> 16, n = 20 -> 32  n = 8 -> 8
		
		Now total space required to make a segment tree is 2*(total leaf node in segment tree to make it perfect binary tree) - 1
		i.e 2*(2^(ceil(log2 N)))-1  or 4*N (we can easily proof that both are equal)
	*/
	int mxSz=4*n;
	
	int *seg=new int[mxSz];
	for(int i=0;i<mxSz;i++) {
		seg[i]=INT_MAX;
	}
	
	segmentUtil(a,0,n-1,seg,0);
	return seg;
	
}

int query(int l, int r, int start, int end, int *seg, int index) {
	if(l<=start && end<=r) { //(start,end) is inside (l,r) //total overlapping
		return seg[index];
	}
	
	if(end<l || start>r) { //(start,end) is totally outside (l,r) //no overlapping
		return INT_MAX;
	}
	
	//partial overlappng
	int mid=start+(end-start)/2;
	int leftMin=query(l,r,start,mid,seg,2*index+1);
	int rightMin=query(l,r,mid+1,end,seg,2*index+2);
	
	return min(leftMin,rightMin);  
}

//query and buildSegmentTree should use same kind of traversal (mid=start+(end-start)/2)
int main() {
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	int *seg=buildSegmentTreeForRMQ(a,n);
	/*for(int i=0;i<4*n;i++) {
		cout<<seg[i]<<" ";
	}*/
	
	int q,l,r;
	cin>>q;
	while(q--) {
		cin>>l>>r;
		cout<<query(l,r,0,n-1,seg,0)<<"\n";
	}
		
	return 0;
}
