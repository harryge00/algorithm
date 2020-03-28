class Solution {
public:
    unordered_map<char, string> char2strMap;
    unordered_set<string> substrSet;
    bool wordPatternMatch(string pattern, string str) {
        if(!pattern.size()) {
            return str.size() == 0 ? true : false;
        }
        string substr = char2strMap[pattern[0]];
        if(substr != "") {
            if(str.substr(0, substr.size()) != substr) {
                return false;
            }
            return wordPatternMatch(pattern.substr(1), str.substr(substr.size()));
        }
        int limit = str.size() - pattern.size() + 1;
        // new pattern. We can define any substring as the new pattern
        for(int i = 1; i <= limit; i++) {
            substr = str.substr(0, i);
            if(substrSet.find(substr) != substrSet.end()) {
                continue;
            }
            char2strMap[pattern[0]] = substr;
            substrSet.insert(substr);
            if(wordPatternMatch(pattern.substr(1), str.substr(i))) {
                return true;
            }
            char2strMap[pattern[0]] = "";
            substrSet.erase(substr);
        }
        return false;
    }
};