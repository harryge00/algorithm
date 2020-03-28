class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i < word.size()) {
            if(word[i] == abbr[j]) {
                i++;
                j++;
                continue;
            }
            if(isdigit(abbr[j])) {
                cnt = abbr[j] - '0';
                while(isdigit(abbr[++j])) {
                    cnt = cnt * 10 + abbr[j] - '0';
                }
                i += cnt;
            } else {
                return false;
            }
        }
        return true;
    }
};