class Solution {
private:
   bool checkEqual(int a[26], int b[26]){
     for(int i =0; i<26; i++){
        if(a[i] != b[i])
          return false;
     }
     return true;
   }
public:
    bool checkInclusion(string s1, string s2) {
        //character count array
        int count1[26]= {0};
        for(int i =0; i<s1.length(); i++){
            int index = s1[i] - 'a';
            count1[index]++;
        
        }
        //traversing s1 string with size of s1 and compare with s2
        int i =0;
        int window_size = s1.length();
        int count2[26] = {0};

        //running for first window
        while(i<window_size && i<s2.length()){
           int index = s2[i] - 'a';
           count2[index]++;
           i++;
        }
        if(checkEqual(count1,count2))
           return true;
        //aage ka window process kro
        while(i<s2.length()){
            char new_char = s2[i];
            int index= s2[i]-'a';
            count2[index]++;

            char old_char = s2[i-window_size];
             index= s2[i-window_size]-'a';
            count2[index]--;

            i++;

           if(checkEqual(count1,count2))
           return true;
        }
       return false; 
    }
};
