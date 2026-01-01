class Solution {
    struct Node {
        int i = -1;
        std::unordered_map<std::string_view, Node*> children;
    };
    
    void collect(Node* node,
                 const std::vector<std::string>& folder,
                 std::vector<std::string>& res) {
        for (auto& [seg, child] : node->children) {
            if (child->i != -1) {
                res.push_back(folder[child->i]);
            } else {
                collect(child, folder, res);
            }
        }
    }
    
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Node* root = new Node();
        
        for (int p = 0; p < folder.size(); ++p) {
            const auto& path = folder[p];
            Node* curr = root;
            for (int i = 1; i < (int)path.size(); ) {
                int j = i;
                while (j < (int)path.size() && path[j] != '/') ++j;
                
                std::string_view seg(path.data() + i, j - i);
                auto it = curr->children.find(seg);
                if (it == curr->children.end()) {
                    Node* n = new Node();
                    curr->children.emplace(seg, n);
                    curr = n;
                } else {
                    curr = it->second;
                }
                
                i = j + 1;
            }
            curr->i = p;
        }
        
        std::vector<std::string> res;
        res.reserve(root->children.size());
        collect(root, folder, res);
        return res;
    }
};
