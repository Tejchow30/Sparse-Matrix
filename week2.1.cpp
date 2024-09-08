#include <iostream>
#include <vector>

struct Triplet {
    int row;
    int col;
    int value;
};

class SparseMatrix {
private:
    int rows, cols;
    std::vector<Triplet> elements;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void addElement(int r, int c, int v) {
        if (r >= rows || c >= cols) {
            std::cout << "Error: Index out of bounds." << std::endl;
            return;
        }
        for (auto &element : elements) {
            if (element.row == r && element.col == c) {
                element.value = v;
                return;
            }
        }
        elements.push_back({r, c, v});
    }

    void printMatrix() {
        int k = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (k < elements.size() && elements[k].row == i && elements[k].col == j) {
                    std::cout << elements[k].value << " ";
                    ++k;
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SparseMatrix sm(4, 5); // 4x5 sparse matrix
    sm.addElement(0, 1, 10);
    sm.addElement(1, 3, 20);
    sm.addElement(3, 4, 30);
    
    sm.printMatrix();
    return 0;
}
