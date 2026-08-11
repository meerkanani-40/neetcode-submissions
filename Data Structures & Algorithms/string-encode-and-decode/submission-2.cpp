class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto str : strs){
            string size = to_string(str.length());
            s += size;
            s += '#';
            s += str;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        while(!s.empty()){
            if(s.find('#') != string::npos){
                int found = s.find('#');
                int size = stoi(s.substr(0, found));
                strs.push_back(s.substr(found+1, size));
                s.erase(0, s.substr(0, found).length() + 1 + size);
            }
        }
        

        return strs;
    }
};
