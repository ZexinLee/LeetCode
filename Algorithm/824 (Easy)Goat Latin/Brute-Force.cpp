class Solution {
public:
    string toGoatLatin(string S) {
        std::set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        
        string goatLatinWord = "";
        char* pch = nullptr;
        pch = strtok((char*)S.c_str()," ");
        int count = 1;
        
        while (pch != nullptr) {
            std::string str((const char*)pch);
            if (vowels.find(tolower(str[0])) != vowels.end())    str += "ma";
            else str = std::string(str.begin()+1, str.end()) +  std::string(1, str[0]) + std::string("ma");
            for (int i=0; i<count; i++)     str += "a";
            pch = strtok(nullptr, " ");
            goatLatinWord += str + ((pch != nullptr) ? " " : "");
            ++count;
        }
    
        return goatLatinWord;
    }
};
