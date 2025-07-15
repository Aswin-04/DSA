#include<regex>
class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool hasAlphaNum = false;
        bool hasVowel = false;
        bool hasConsonant = false;

        for(char chr: word) {
            char ch = tolower(chr);
            if(!(isalnum(ch))) return false;
            if(isdigit(ch)) {
                hasAlphaNum = true;
                continue;
            }
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                hasVowel = true;
            }
            if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                hasConsonant = true;
            }
            hasAlphaNum = true;
        }

        return hasAlphaNum && hasVowel && hasConsonant;
    }
};