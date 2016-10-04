class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      vector<int> res;
      map<string, int> dict;
      for(string word : words) {
        dict[word]++;
      }
      int num = words.size(), len = words[0].length(), slen = s.length(), tlen = len * num;
      for(int i = 0; i <= slen - tlen; i++) {
        int j = i;
        map<string, int> tmpdict = dict;
        while(j < slen && j < i + tlen) {
          string tmp = s.substr(j, len);
          if(!tmpdict[tmp]) {
            break;
          }
          tmpdict[tmp]--;
          j += len;
        }
        if(j == i + tlen) {
          res.push_back(i);
        }
      }
      return res;
    }
};
