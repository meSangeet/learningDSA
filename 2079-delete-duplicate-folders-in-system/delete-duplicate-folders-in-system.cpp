using namespace std;

struct Trie {
    string signature;
    unordered_map<string, Trie*> children;
};

class Solution {
public:
    void build(Trie* node, unordered_map<string, int>& count) {
        if (node->children.empty()) return;
        vector<string> sigs;
        for (auto& [name, child] : node->children) {
            build(child, count);
            sigs.push_back(name + "(" + child->signature + ")");
        }
        sort(sigs.begin(), sigs.end());
        for (auto& s : sigs) node->signature += move(s);
        ++count[node->signature];
    }

    void collect(Trie* node, unordered_map<string, int>& count, 
                 vector<string>& path, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (count[child->signature] > 1) continue;
            path.push_back(name);
            result.push_back(path);
            collect(child, count, path, result);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie* root = new Trie();
        for (auto& path : paths) {
            Trie* node = root;
            for (auto& dir : path)
                node = node->children[dir] ? node->children[dir] : (node->children[dir] = new Trie());
        }

        unordered_map<string, int> count;
        build(root, count);

        vector<vector<string>> result;
        vector<string> path;
        collect(root, count, path, result);
        return result;
    }
};
