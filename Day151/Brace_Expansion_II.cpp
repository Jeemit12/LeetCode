/*
Under the grammar given below, strings can represent a set of lowercase words. Let R(expr) denote the set of words the expression represents.

The grammar can best be understood through simple examples:

Single letters represent a singleton set containing that word.
R("a") = {"a"}
R("w") = {"w"}
When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
R("{a,b,c}") = {"a","b","c"}
R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
Formally, the three rules for our grammar:

For every lowercase letter x, we have R(x) = {x}.
For expressions e1, e2, ... , ek with k >= 2, we have R({e1, e2, ...}) = R(e1) ∪ R(e2) ∪ ...
For expressions e1 and e2, we have R(e1 + e2) = {a + b for (a, b) in R(e1) × R(e2)}, where + denotes concatenation, and × denotes the cartesian product.
Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.
*/
class Solution {
public:
    vector<char> op;
    vector<vector<string>> st;

    void perf() {
        int x=st.size()-2, y = st.size()-1;
        if (op.back()=='+'){
            st[x].reserve(st[x].size()+st[y].size());
            st[x].insert(st[x].end(), st[y].begin(), st[y].end());
        }
        else { 
            vector<string> nxt;
            nxt.reserve(st[x].size()*st[y].size());
            for (const auto& l : st[x]) {
                for (const auto& r : st[y]) 
                    nxt.push_back(l+r);
            }
            st[x]=move(nxt);
        }
        op.pop_back();
        st.pop_back();
    }
    vector<string> braceExpansionII(string& expr) {
        const int n=expr.size();
        op.reserve(n);

        char prv='@', cur;

        for (int i=0; i<n; i++, prv=cur) {
            cur = expr[i];
            switch (cur) {
            case ',': 
                while (!op.empty() && op.back() != '{') perf();
                op.push_back('+');
                break;
            case '{':
                if (prv=='}' || isalpha(prv)) op.push_back('*');
                op.push_back('{');
                break;
            case '}':
                while (!op.empty() && op.back()!='{') perf();
                op.pop_back(); 
                break;
            default:
                if (prv=='}') op.push_back('*');
                string s;
                for (; i<n && isalpha(expr[i]); i++) s+=expr[i];
                st.push_back({s});
                i--;
                cur=expr[i];
            }
        }

        while (!op.empty()) perf();

        auto ans=st.front();
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();