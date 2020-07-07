public class Solution {
    public ArrayList<Integer> solve(ArrayList<Integer> A) {
        PriorityQueue<Integer> pqMx=new PriorityQueue<Integer>(Collections.reverseOrder());
        PriorityQueue<Integer> pqMn=new PriorityQueue<Integer>();
        int n=A.size();
        int median;
        
        ArrayList<Integer> res=new ArrayList<Integer>();
        median=0;
        for(int i=0;i<n;i++) {
            if(pqMx.size()==pqMn.size()) {
                if(A.get(i)<median) {
                    pqMx.add(A.get(i));
                    median=pqMx.peek();
                } else {
                    pqMn.add(A.get(i));
                    median=pqMn.peek();
                }
            } else if(pqMx.size()<pqMn.size()) {
                if(A.get(i)<median) {
                    pqMx.add(A.get(i));
                } else {
                    int top=pqMn.poll();
                    pqMx.add(top);
                    pqMn.add(A.get(i));
                }
                median=pqMx.peek();
            } else if(pqMx.size()>pqMn.size()) {
                if(A.get(i)<median) {
                    int top=pqMx.poll();
                    pqMn.add(top);
                    pqMx.add(A.get(i));
                } else {
                    pqMn.add(A.get(i));
                }
                median=pqMx.peek();
            }
            
            res.add(median);
        }
        
        return res;
    }
}
