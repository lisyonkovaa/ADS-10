// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <string>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> childs;
    };
    Node* root;

 public:
    int variable;
    int n_fact;
    std::vector<char> data;
    std::vector<char> template_data;
    std::vector<char> v;

    int fact(int n) {
        int count = 1;
        for (int item = 2; item <= n; item++) {
            count *= item;
        }
        return count;
    }

    Tree(std::vector<char> in): root(nullptr), n_fact(0), variable(0) {
        if (root) {
            throw std::string("Error!");
        } else {
            if (!in.empty()) {
                v = in;
                variable = in.size();
                n_fact = fact(variable);
                root = new Node;
                root->value = '*';
                for (int item = 0; item < in.size(); item++) {
                    root->childs.push_back(new Node);
                    root->childs[item]->value = in[item];
                }
                for (int item = 0; item < in.size(); item++) {
                    std::vector<char> in_item;
                    for (int k = 0; k < in.size(); k++) {
                       if (k != item) {
                           in_item.push_back(in[k]);
                       } else {
                           data.push_back(in[item]);
                       }
                    }
                    if (!in_item.empty()) {
                        root->childs[item] = addChilds(root->childs[item], in_item);
                    }
                    for (int q = 0; q < in.size() - 1; q++) {
                        template_data.push_back(data[data.size() - 1]);
                        data.pop_back();
                    }
                    data.push_back(in[item]);
                    for (int q = 0; q < in.size() - 1; q++) {
                        data.push_back(template_data[template_data.size() - 1]);
                        template_data.pop_back();
                    }
                    template_data.clear();
                }
            }
        }
    }

    Node* addChilds(Node* root, std::vector<char> ch) {
        if (!root) {
            throw std::string("Error!");
        } else {
            if (!ch.empty()) {
                for (int j = 0; j < ch.size(); j++) {
                    root->childs.push_back(new Node);
                    root->childs[j]->value = ch[j];
                }
                for (int j = 0; j < ch.size(); j++) {
                    std::vector<char> in_j;
                    for (int k = 0; k < ch.size(); k++) {
                        if (k != j) {
                            in_j.push_back(ch[k]);
                        } else {
                            data.push_back(ch[j]);
                        }
                    }
                    if (!in_j.empty()) {
                        root->childs[j] = addChilds(root->childs[j], in_j);
                    }
                }
            }
        }
        return root;
    }
};

std::vector<char> getPerm(const Tree& tree, int n);
#endif  // INCLUDE_TREE_H_
