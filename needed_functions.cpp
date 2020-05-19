#include "needed_functions.h"
void indexFile(string filePath, Trie* head){
    string line;
    ifstream file(filePath,ios_base::in);

    while (!file.eof()) {
        getline(file, line);
        regex reg("\\W+");
        sregex_token_iterator iter(line.begin(), line.end(), reg, -1);
        sregex_token_iterator end;
        vector<string> vec(iter, end);
        for(int i=0;i<vec.size();i++){
            head->insert(vec[i],filePath.substr(filePath.find_last_of("/")+1));
        }
    }
}
