class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> sol= new ArrayList<>();
        
        for(int i=0 ; i<numRows ; i++){
            int one=1;
            List<Integer> p = new ArrayList<>();
            
            for(int j=0 ; j<=i ; j++){
                if(j==0 || j==i){
                    p.add(1);
                    continue;

                }
                int num = (sol.get(i-1).get(j-1) ) + (sol.get(i-1).get(j)) ;
                p.add(num);
            }
            sol.add(p);
        }
        return sol;
    }
}