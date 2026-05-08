class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string s: strs){
            //encode strs into single string
            encoded+= to_string(s.size())+ "#" + s;
        }
      return encoded;

    }

    vector<string> decode(string s) {
        vector<string>decoded;
        int i =0;
        while(i<s.size()){
            int j = i;
            //for delemeter #
            while(s[j] != '#'){
               j++;
            }
            int len = stoi(s.substr(i,j-i));
            //actual word
            string word = s.substr(j+1,len);
            decoded.push_back(word);

            i = j+1+len;
        }
      return decoded;
    }
};
