//
// Created by Admin on 2021/3/22.
//
#include <string>
#include <vector>
#include <map>

class UnionFind {
public:
    UnionFind(std::vector<std::vector<std::string>>& pairs) {
        for (int i = 0; i < pairs.size(); i++) {
            if (!father.count(pairs[i][0])) {
                father[pairs[i][0]] = pairs[i][0];
            }
            if (!father.count(pairs[i][1])) {
                father[pairs[i][1]] = pairs[i][1];
            }
            merge(pairs[i][0], pairs[i][1]);
        }
    }
    std::string find(std::string& str) {
        std::string root = str;
        while (father[root] != root) {
            root = father[root];
        }
        while (str != root) {
            std::string originRoot = father[str];
            father[str] = root;
            str = originRoot;
        }
        return root;
    }
    void merge(std::string& str1, std::string& str2) {
        std::string root1 = find(str1);
        std::string root2 = find(str2);
        if (root1 != root2) {
            father[root1] = root2;
        }
    }
    bool isConnected(std::string& str1, std::string& str2) {
        return find(str1) == find(str2);
    }
private:
    std::map<std::string, std::string> father;
};

class _737AreSentencesSimilarTwo {
public:
    bool areSentencesSimilarTwo(std::vector<std::string>& words1, std::vector<std::string>& words2, std::vector<std::vector<std::string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        if (words1 == words2) {
            return true;
        }
        UnionFind uf(pairs);
        for (int i = 0; i < words1.size(); i++) {
            if (!uf.isConnected(words1[i], words2[i])) {
                return false;
            }
        }
        return true;
    }
};