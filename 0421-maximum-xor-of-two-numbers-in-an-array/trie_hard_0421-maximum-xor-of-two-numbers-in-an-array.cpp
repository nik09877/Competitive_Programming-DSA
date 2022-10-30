class TrieNode
{
    public:
        vector<TrieNode*> edge;
    bool isNum;

    TrieNode()
    {
        edge = vector<TrieNode*> (2, nullptr);
        isNum = false;
    }

    bool containsEdge(char ch)
    {
        return edge[ch - '0'] != nullptr;
    }

    TrieNode* next(char ch)
    {
        return edge[ch - '0'];
    }

    void insertEdge(char ch)
        {
            edge[ch - '0'] = new TrieNode();
        }

        ~TrieNode()
        {
            for (int i = 0; i < 2; i++)
                delete edge[i];
        }
};

class Trie
{
    public:
        TrieNode * root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *cur_node = root;

        for (char ch: word)
        {
            if (not cur_node->containsEdge(ch))
                cur_node->insertEdge(ch);
            cur_node = cur_node->next(ch);
        }
        cur_node->isNum = true;
    }

    bool search(string word)
    {
        TrieNode *cur_node = root;

        for (char ch: word)
        {
            if (not cur_node->containsEdge(ch))
                return false;
            cur_node = cur_node->next(ch);
        }
        return cur_node->isNum == true;
    }
};

class Solution
{
    public:
        string transform_to_str(int n, int compliment)
        {
            string str = "";
            if (compliment == 0)
            {
                for (int i = 31; i >= 0; i--)
                {
                    if (n &(1 << i))
                        str += '1';
                    else
                        str += '0';
                }
            }
            else
            {
                for (int i = 31; i >= 0; i--)
                {
                    if (n &(1 << i))
                        str += '0';
                    else
                        str += '1';
                }
            }
            return str;
        }
    int findMaximumXOR(vector<int> &nums)
    {
        Trie trie;
        for (auto x: nums)
        {
            string str = transform_to_str(x, 0);
            trie.insert(str);
        }
        int x_or = 0;
        for (auto x: nums)
        {
            string comp_of_x = transform_to_str(x, 1);
            int y = 0;
            TrieNode *node = trie.root;
            for (int i = 0; i < 32; i++)
            {
                char ch = comp_of_x[i];
                int bit_pos = 31 - i;
                if (node->containsEdge(ch))
                {
                    node = node->next(ch);
                    if (ch == '1')
                        y += (1 << bit_pos);
                }
                else
                {
                    if (ch == '0')
                    {
                        node = node->next('1');
                        y += (1 << bit_pos);
                    }
                    else
                    {
                        node = node->next('0');
                    }
                }
            }
            x_or = max(x_or, x ^ y);
        }
        return x_or;
    }
};