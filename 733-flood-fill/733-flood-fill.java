class Solution {
    int[][] images;
    int currColor;
    int newColor,colorNeeded,row,col;
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        images=image;
        this.newColor=newColor;
        colorNeeded=images[sr][sc];
        row=image.length;
        col=image[0].length;
        if(colorNeeded !=newColor)
        {
            dfs(sr,sc);
        }
        return images;
        
    }
    public void dfs(int sr,int sc)
    {
        if(sr<0 || sr>=row || sc<0 || sc>=col){
            return;
        }
        currColor=images[sr][sc];
        if(currColor !=colorNeeded)
            return;
        images[sr][sc]=newColor;
        dfs(sr+1,sc);
        dfs(sr-1,sc);
        dfs(sr,sc+1);
        dfs(sr,sc-1);
    }
}