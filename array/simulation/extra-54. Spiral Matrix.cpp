class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int startX=0,EndX=matrix.size()-1;
        int startY=0,EndY=matrix[0].size()-1;
        while(true){
            for(int j=startY;j<=EndY;j++)res.push_back(matrix[startX][j]);
            if(++startX>EndX)break;

            for(int i=startX;i<=EndX;i++)res.push_back(matrix[i][EndY]);
            if(--EndY<startY)break;

            for(int j=EndY;j>=startY;j--)res.push_back(matrix[EndX][j]);
            if(--EndX<startX)break;

            for(int i=EndX;i>=startX;i--)res.push_back(matrix[i][startY]);
            if(++startY>EndY)break;
            
        }
        return res;
    }
};