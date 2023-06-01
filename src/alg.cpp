// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> variable;
    int size = tree.per_size;
    int fact = tree.n_fact;
    if ((n <= fact) && (n > 0)) {
        n = (n - 1) * size;
        for (int item = 0; item < size; item++) {
            variable.push_back(tree.data[n + item]);
        }
    }
    return variable;
}
