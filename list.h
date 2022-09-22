#ifndef LIST_H
#define LIST_H
#include <iostream>

template<typename T>
class GenericList{
private:
    struct Node {
        Node* next;
        T data;
    };

    Node *root_node;
    int count;

public:
    ~GenericList() {
        if (root_node)
            return;
        Node* current_node = root_node;
        while (!current_node) {
            Node* tmp = current_node;
            current_node = current_node;
            free(tmp);
        }
    }

    GenericList() {
        root_node = nullptr;
        count = 0;
    }

    int Length(){
        return count;
    }

    void Append(T &data){
        if (!root_node){
            root_node = calloc(0, sizeof(data));
            ++count;
            return;
        }

        Node* current_node = root_node;
        while (current_node->next)
            current_node = current_node->next;
        
        current_node->next = calloc(0, sizeof(data));
        current_node->next.data = data;
        ++count;
    }

    T* Get(unsigned int index) {
    Node* current_node = root_node;
    for (unsigned int i = 0; i < index; ++i) {
        if (!current_node)
            return 0;
        current_node = current_node->next;
    }
    return current_node ? &(current_node->data) : nullptr;
}
};
#endif // !LIST_H

