class TrieNode {
    public int index;
    public TrieNode[] children;

    public TrieNode() {
        index = Integer.MAX_VALUE;
        children = new TrieNode[26];
    }
}

class Trie {
    private TrieNode root;
    private String[] words;

    private boolean change(int i, int j) { // change i to j ?
        int n = words.length;
        return (0 <= j && j < n) && // j should be valid
            (!(0 <= i && i < n) || // change if i is not valid
             words[j].length() < words[i].length() || // or if less size
             (words[j].length() == words[i].length() && j < i)); // or if less index
    }
    
    private int fillIndices(TrieNode curr) {
        for (TrieNode child: curr.children) {
            int r = child != null ? fillIndices(child) : Integer.MAX_VALUE;
            if (change(curr.index, r)) {
                curr.index = r;
            }
        }
        return curr.index;
    }

    public Trie(String[] words) {
        int n = words.length;
        root = new TrieNode();
        this.words = words;
        for (int i = 0; i < n; i++) {
            insertSuffix(words[i], i);
        }
        fillIndices(root);
    }
    
    public void insertSuffix(String s, int index) {
        TrieNode curr = root;
        char[] str = s.toCharArray();
        for (int i = str.length - 1; i >= 0; i--) {
            if (curr.children[str[i] - 'a'] == null) {
                curr.children[str[i] - 'a'] = new TrieNode();
            }
            curr = curr.children[str[i] - 'a'];
        }
        curr.index = Math.min(curr.index, index);
    }
    
    public int longestCommonSuffix(String s) {
        TrieNode curr = root;
        char[] str = s.toCharArray();
        for (int i = str.length - 1; i >= 0 && curr.children[str[i] - 'a'] != null; i--) {
            curr = curr.children[str[i] - 'a'];
        }
        return curr.index;
    }
}

class Solution {
    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
        int m = wordsQuery.length;
        Trie trie = new Trie(wordsContainer);
        int[] result = new int[m];
        for (int i = 0; i < m; i++) {
            result[i] = trie.longestCommonSuffix(wordsQuery[i]);
        }
        return result;
    }
}