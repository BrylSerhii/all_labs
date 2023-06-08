#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

/*Реалізуйте функцію для обчислення мінімальної кількості ребер,
які слід видалити, щоб перетворити задане дерево на ліс дерев з однаковою кількістю вузлів.
Збережіть дерево у файлі та реалізуйте функцію для завантаження дерева з файлу.*/
using namespace std;

struct TreeNode {
    vector<TreeNode*> children;
    TreeNode() = default;
};

void createTreeFile() {
    ofstream file("tree.txt");
    if (file.is_open()) {
        file << "1 2\n";
        file << "1 3\n";
        file << "2 4\n";
        file << "2 5\n";
        file << "3 6\n";
        file.close();
        cout << "File 'tree.txt' created successfully." << endl;
    } else {
        cout << "Unable to create file 'tree.txt'." << endl;
    }
}

TreeNode* loadTreeFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        TreeNode* root = nullptr;
        vector<pair<int, int>> connections;
        int parent, child;
        while (file >> parent >> child) {
            connections.push_back(make_pair(parent, child));
        }
        file.close();

        unordered_map<int, TreeNode*> nodesMap;
        for (const auto& conn : connections) {
            int parentVal = conn.first;
            int childVal = conn.second;

            TreeNode* parentNode;
            if (nodesMap.find(parentVal) == nodesMap.end()) {
                parentNode = new TreeNode();
                nodesMap[parentVal] = parentNode;
            } else {
                parentNode = nodesMap[parentVal];
            }

            TreeNode* childNode;
            if (nodesMap.find(childVal) == nodesMap.end()) {
                childNode = new TreeNode();
                nodesMap[childVal] = childNode;
            } else {
                childNode = nodesMap[childVal];
            }

            parentNode->children.push_back(childNode);
        }

        if (!connections.empty()) {
            root = nodesMap[connections[0].first];
        }

        return root;
    } else {
        cout << "File '" << filename << "' could not be opened." << endl;
        return nullptr;
    }
}

int calculateMinEdgesToRemove(TreeNode* root) {
    int minEdgesToRemove = 0;

    if (root == nullptr || root->children.empty()) {
        return minEdgesToRemove;
    }

    for (TreeNode* child : root->children) {
        minEdgesToRemove += calculateMinEdgesToRemove(child);
    }

    if (root->children.size() > 1) {
        minEdgesToRemove += root->children.size() - 1;
    }

    return minEdgesToRemove;
}


int main() {
    createTreeFile();

    TreeNode* root = loadTreeFromFile("tree.txt");
    if (root) {
        cout << "Tree loaded successfully" << endl;
    }

    int minEdges = calculateMinEdgesToRemove(root);
    cout << "Minimum number of edges to remove: " << minEdges << endl;

    return 0;
}
