class Solution {
    void swap(int[][] mat , int i, int j){
        int temp ;
        temp = mat[i][j];
        mat[i][j] = mat[j][i];
        mat[j][i] = temp;
    } 
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        // System.out.println(n/2);

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<m ; j++){
                swap(matrix , i , j);
            }
        }   
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n/2 ; j++){
                int temp=matrix[i][n-1-j];
                matrix[i][n-1-j]=matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
}