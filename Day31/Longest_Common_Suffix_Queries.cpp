/*
You are given two arrays of strings wordsContainer and wordsQuery.

For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.

Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].
*/
class Solution {
    struct TrieNode {
        int children[26];
        int best_idx;
        
        TrieNode(int idx) {
            memset(children, -1, sizeof(children));
            best_idx = idx;
        }
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int min_len = 1e9;
        int min_idx = -1;
        
        
        for (int i = 0; i < n; ++i) {
            if (wordsContainer[i].length() < min_len) {
                min_len = wordsContainer[i].length();
                min_idx = i;
            }
        }
        
        
        vector<TrieNode> trie;
        trie.emplace_back(min_idx);
        
      
        for (int i = 0; i < n; ++i) {
            int curr = 0; 
            int len = wordsContainer[i].length();
            
        
            for (int j = len - 1; j >= 0; --j) {
                int c = wordsContainer[i][j] - 'a';
                
                if (trie[curr].children[c] == -1) {
                    trie[curr].children[c] = trie.size();
                    trie.emplace_back(i);
                }
                
                curr = trie[curr].children[c];
                
                
                if (len < wordsContainer[trie[curr].best_idx].length()) {
                    trie[curr].best_idx = i;
                }
            }
        }
        
       
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& q : wordsQuery) {
            int curr = 0;
            
            for (int j = q.length() - 1; j >= 0; --j) {
                int c = q[j] - 'a';
                if (trie[curr].children[c] == -1) {
                    break; 
                }
                curr = trie[curr].children[c];
            }
            ans.push_back(trie[curr].best_idx);
        }
        
        return ans;
    }
};