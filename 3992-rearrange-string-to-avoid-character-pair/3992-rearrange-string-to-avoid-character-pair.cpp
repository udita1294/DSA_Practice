class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ans ;
        int countx = 0;
        int county = 0;

        for(int i=0;i<s.size();i++){
            if(s[i] == x){
                countx++;
            }else if(s[i] == y){
                county++;
            }else{
                ans += s[i];
            }
        }

        return string(county,y) + ans + string(countx,x);
    }
};