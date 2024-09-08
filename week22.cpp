#include <iostream>

struct Node {
    int row;
    int col;
    int value;
    Node* next;
};

class SparseMatrix {
private:
    Node* head;
    int totalRows, totalCols;

public:
    SparseMatrix(int rows, int cols) : totalRows(rows), totalCols(cols), head(nullptr) {}

    ~SparseMatrix() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addElement(int r, int c, int v) {
        if (r >= totalRows || c >= totalCols) {
            std::cout << "Error: Index out of bounds." << std::endl;
            return;
        }
        Node** walker = &head;
        while (*walker && ((*walker)->row < r || ((*walker)->row == r && (*walker)->col < c))) {
            walker = &((*walker)->next);
        }
        if (*walker && (*walker)->row == r && (*walker)->col == c) {
            (*walker)->value = v; // Update the value if it already exists
        } else {
            Node* newNode = new Node{r, c, v, *walker};
            *walker = newNode;
        }
    }

    void printMatrix() {
        Node* current = head;
        for (int i = 0; i < totalRows; ++i) {
            for (int j = 0; j < totalCols; ++j) {
                if (current && current->row == i && current->col == j) {
                    std::cout << current->value << " ";
                    current = current->next;
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
