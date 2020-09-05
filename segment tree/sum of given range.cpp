/*
We have an array arr[0 . . . n-1]. 
1) Find the sum of elements from index l to r 
where 0 <= l <= r <= n-1

2) Update a specified element of the array to a new value x. 
We need to do arr[i] = x where 0 <= i <= n-1.
*/

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
	
	seg[index]=seg[2*index+1]+seg[2*index+2];
}

int *buildSegmentTree(int a[], int n) {
	int mxSz=4*n;
	int *seg=new int[mxSz];
	for(int i=0;i<mxSz;i++) {
		seg[i]=0;
	}
	
	segmentUtil(a,0,n-1,seg,0);
	return seg;
}

int sumQuery(int l, int r, int start, int end, int *seg, int index) {
	if(l<=start && end<=r) { //(start,end) is inside (l,r) //total overlapping
		return seg[index];
	}
	
	if(end<l || start>r) { //(start,end) is totally outside (l,r) //no overlapping
		return 0;
	}
	
	//partial overlappng
	int mid=start+(end-start)/2;
	int leftSum=sumQuery(l,r,start,mid,seg,2*index+1);
	int rightSum=sumQuery(l,r,mid+1,end,seg,2*index+2);
	
	return leftSum+rightSum;  
}

void update(int i, int diff, int start, int end,int *seg, int segIndex) {
	if(start<=i && i<=end) { //if given index lies in our range
		seg[segIndex]+=diff;
		if(start!=end) {
			int mid=start+(end-start)/2;
			update(i,diff,start,mid,seg,2*segIndex+1);
			update(i,diff,mid+1,end,seg,2*segIndex+2);
		}
	}
	
	return ;
}

//query and buildSegmentTree should use same kind of traversal (mid=start+(end-start)/2)
int main() {
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	int *seg=buildSegmentTree(a,n);
	/*for(int i=0;i<4*n;i++) {
		cout<<st[i]<<" ";
	}*/
	
	int q,l,r;
	int choice;
	int i,val,diff;
	cin>>q;
	while(q--) {
		cin>>choice;
		if(choice==1) {
			cin>>l>>r;
			cout<<sumQuery(l,r,0,n-1,seg,0)<<"\n";
		}
		else {
			cin>>i>>val;
			diff=val-a[i];
			a[i]=val;
		 	update(i,diff,0,n-1,seg,0);
		}
	}
		
	return 0;
}
