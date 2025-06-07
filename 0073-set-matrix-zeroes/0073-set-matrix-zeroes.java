class Solution {
    public void setZeroes(int[][] matrix) {
        int row=matrix.length;
        int col=matrix[0].length;
        int[] rowZero= new int[row];
        int[] colZero= new int[col];

        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                if(matrix[i][j]==0){
                    rowZero[i]=1;
                    colZero[j]=1;
                }
            }
        }

        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                if(rowZero[i]==1 || colZero[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
        System.out.println(matrix[row-1][col-1]);
        System.out.println(matrix);
    }
}