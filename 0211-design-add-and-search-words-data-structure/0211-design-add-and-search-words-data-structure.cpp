class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool isEnd = false;
};
class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
      TrieNode *curr = root;
      
      for(char ch:word){
        if(curr->children.find(ch) == curr->children.end()){
         
          curr->children[ch] = new TrieNode();
        }
        curr = curr->children[ch];
      }
      curr->isEnd = true;
    }
    bool searchInNode(string word, TrieNode* node){
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(!node->children.count(ch)){
                if(ch == '.'){
                    for(auto nodes:node->children){
                        TrieNode *child = nodes.second;
                        if(searchInNode(word.substr(i+1),child)){
                            return true;
                        }
                    }
                }
                    return false;
            }
            else {
                node = node->children[ch];
            }
        }
        return node->isEnd;
    }
    bool search(string word) {
        return searchInNode(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */