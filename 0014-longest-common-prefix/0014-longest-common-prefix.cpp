class TrieNode
{
    public:
        vector<TrieNode*> edge;
    bool isWord;
    int prefix_cnt;
    int len;

    TrieNode()
    {
        edge = vector<TrieNode*> (26, nullptr);
        isWord = false;
        prefix_cnt = 0;
        len = 0;
    }

    bool containsEdge(char ch)
    {
        return edge[ch - 'a'] != nullptr;
    }

    TrieNode* next(char ch)
    {
        return edge[ch - 'a'];
    }

    void insertEdge(char ch)
        {
            edge[ch - 'a'] = new TrieNode();
        }

        ~TrieNode()
        {
            for (int i = 0; i < 26; i++)
                delete edge[i];
        }
};

class Trie
{
    private:
        TrieNode * root;
    public:
    int len_of_lcp;
        Trie()
        {
            root = new TrieNode();
            len_of_lcp = 0;
        }

    void insert(string word, int &n)
    {
        TrieNode *cur_node = root;

        for (char ch: word)
        {
            if (not cur_node->containsEdge(ch))
            {
                cur_node->insertEdge(ch);
            }
            
            TrieNode* child = cur_node->next(ch);
            child->prefix_cnt++;
            child->len = cur_node->len + 1;
            if(child->prefix_cnt == n)
                len_of_lcp = max(len_of_lcp,child->len);
            cur_node = child;
        }
        cur_node->isWord = true;
    }
    
};

class Solution
{
    public:
        string longestCommonPrefix(vector<string> &strs)
        {
            Trie trie;
            int n = strs.size();
            for (auto s: strs)
                trie.insert(s, n);
            return strs[0].substr(0,trie.len_of_lcp);
        }
};