class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n,0));
        int startX=0,startY=0;
        int offset=1;
        int count=1;
        int loop=n/2;
        while(loop--){
            int i=startX,j=startY;
            for(;j<n-offset;j++)res[i][j]=count++;
            for(;i<n-offset;i++)res[i][j]=count++;
            for(;j>startY;j--)res[i][j]=count++;
            for(;i>startX;i--)res[i][j]=count++;
            startX++;
            startY++;
            offset++;
        }
        if(n%2==1)res[n/2][n/2]=count;
        return res;
    }
};