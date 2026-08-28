class Solution {
public:
    int halflen = 0;
    char midChar = '$';
    string result = "";
    bool solve(string &curr,vector<int>&count,string target,int i,bool greater){
        if(curr.length() == halflen){
            string candidate = curr;
            string righthalf = curr;
            reverse(righthalf.begin(),righthalf.end());

            if(midChar != '$'){
                candidate += midChar;
            }
            candidate += righthalf;
            if(candidate > target){
                result = candidate;
                return true;
            }
            return false;
        }
        for(char ch = 'a';ch <= 'z';ch++){
            if(count[ch - 'a'] == 0)continue;
            if(!greater && ch < target[i])continue;

            //do
            curr.push_back(ch);
            count[ch-'a']--;

            //explore
            bool isGreater = greater || ch > target[i];
            if(solve(curr,count,target,i+1,isGreater)){
                return true;
            }
            //undo
            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int>count(26,0);
        for(char &ch : s){
            count[ch - 'a']++;
        }
        int oddCount = 0;
        for(int c=0;c<26;c++){
            if(count[c] % 2 == 1){
                oddCount++;
                midChar = c + 'a';
            }
        }
        if(oddCount > 1){
            return "" ;// not possible to create palindrome
        }
        halflen = n/2;
        for(int c=0;c<26;c++){
            count[c] /= 2;
        }
        string curr;
        solve(curr,count,target,0,false);
        return result;
    }
};