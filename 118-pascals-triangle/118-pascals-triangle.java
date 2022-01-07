class Solution {
    public List<List<Integer>> generate(int numRows) {
      List<List<Integer>> a = new ArrayList<>();
        List<Integer> subArr = new ArrayList<>();
        int[][] arr = new int[numRows][numRows];
        for (int i =0; i < numRows;i++)
        {
            for (int j = 0; j <= i ; j++) {
                if(j==0 || i==j)
                {
                    subArr.add(1);
                }
                else {
                    subArr.add( ((a.get(i-1))).get(j) + ((a.get(i-1))).get(j-1));
                }
            }
            a.add( new ArrayList<>(subArr));
            subArr.clear();
        }
         return a;  
    }
}