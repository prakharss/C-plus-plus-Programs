import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Solution {
	
	static int cnt=0;
	static ArrayList<Integer> postorder=new ArrayList<>(); 
	static Map<Integer,Integer> mp=new HashMap<>(); 
	
	static void util(int preorder[],int inorder[],int l, int r) //preorder = 1 2 4 5 3 6 7 //inorder = 4 2 5 1 6 3 7
	{
		if(l>r)
		{
			return ;
		}
		
		int mid=mp.get(preorder[cnt]);
		cnt++;
		
		util(preorder,inorder,l,mid-1);
		util(preorder,inorder,mid+1,r);
		
		postorder.add(inorder[mid]);
		return ; 
	}
	
	public static void main(String[] args)
	{
		int n,i;
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		
		int preorder[]=new int[n];
		for(i=0;i<n;i++)
			preorder[i]=sc.nextInt();
		
		int inorder[]=new int[n];
		for(i=0;i<n;i++)
			inorder[i]=sc.nextInt();
		
		for(i=0;i<n;i++)
			mp.put(inorder[i], i);
		
		util(preorder,inorder,0,n-1);
		for(i=0;i<postorder.size();i++)
			System.out.print(postorder.get(i)+" ");
		
		sc.close();
	}
}
