 public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
         unordered_map<char, int> charCount;
    for(char ch: s1) 
        charCount[ch] += 1;
  
    for(char ch: s2) 
        charCount[ch] -= 1;
  
    for (auto& pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }
    
    return true;
}
    

    //M 2 ->
    class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        else return false;

        
    }
};