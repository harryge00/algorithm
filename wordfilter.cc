class WordFilter {
private:
    vector<string> records;
public:
    WordFilter(vector<string>& words) {
        records = words;
        return;
    }
    
    int f(string prefix, string suffix) {
        for(int i = records.size() - 1; i >= 0; i++) {
            string str = records[i];
            if(str.substr(0, prefix.size()) == prefix && str.substr(records[i].size() - suffix.size(), records[i].size()) == suffix) {
                return i;
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */