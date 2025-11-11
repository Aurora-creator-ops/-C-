class Solution {
public:
    string minWindow(string s, string t) {
        int count[128]{};//ASCII字符一共128个
        int less=0;//还有多少种字符没包含在s中
        for(char c:t){
            if(count[c]==0){//字符在 C++ 中会被自动转换为对应的 ASCII 码整数
                less++;
            }
            count[c]++;
        }

        int ans_left=-1,ans_right=s.size();
        int left=0;//滑动窗口左指针
        for(int right=0;right<s.size();right++){
            count[s[right]]--;
            if(count[s[right]]==0)less--;

            while(less==0){
                if(ans_right-ans_left>right-left){
                    ans_right=right;
                    ans_left=left;
                }
                if(count[s[left]]==0){
                    less++;
                }
                count[s[left]]++;//这个必须要有，而且这个在if条件判断的后面执行
                left++;
            }
        }
        return ans_left<0?"":s.substr(ans_left,ans_right-ans_left+1);
    }
};