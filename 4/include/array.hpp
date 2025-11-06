#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>
#include <functional>


template<class T>
class List;


template<class N>
class Node {
    private:
        N data;
        Node* prev = nullptr;
        Node* next = nullptr;
    public:
        Node(N data) : data(data) {}
        friend List<N>;
};


template<typename T>
class List {
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        int size = 0;

        Node<T>* getNode(int index) const {
            if (index < 0 || index >= size)
                throw std::out_of_range("Index out of range");
            Node<T>* current;
            if (index < size / 2) { 
                current = head;
                for (int i = 0; i < index; i++)
                    current = current->next;
            }
            else { 
                current = tail;
                for (int i = size - 1; i > index; i--)
                    current = current->prev;
            }
            return current;
        }

    public:
        List() = default;

        List(const List& other) {
            Node<T>* current = other.head;
            while (current != nullptr) {
                push_back(current->data);
                current = current->next;
            }
        }

        List& operator=(const List& other) {
            if (this != &other) {
                while (this->head != nullptr) {
                    Node<T>* temp = this->head;
                    this->head = this->head->next;
                    delete temp;
                }
                this->tail = nullptr;
                this->size = 0;
                Node<T>* current = other.head;
                while (current != nullptr) {
                    push_back(current->data);
                    current = current->next;
                }
            }
            return *this;
        }

        ~List() {
            while (this->head != nullptr) {
                Node<T>* temp = head;
                this->head = this->head->next;
                delete temp;
            }
            this->tail = nullptr;
            this->size = 0;
        }

        void insert(T data, int index) {
            if (index < 0 || index > this->size)
                throw std::out_of_range("Index out of range");
            Node<T>* newNode = new Node(data);
            if (!this->size)
                this->head = this->tail = newNode;
            else if (!index) { 
                newNode->next = this->head;
                this->head->prev = newNode;
                this->head = newNode;
            }
            else if (index == size) { 
                this->tail->next = newNode;
                newNode->prev = this->tail;
                this->tail = newNode;
            }
            else { 
                Node<T>* current = getNode(index);
                newNode->prev = current->prev;
                newNode->next = current;
                current->prev->next = newNode;
                current->prev = newNode;
            }
            this->size++;
        }

        T pop(int index) {
            if (index < 0 || index >= this->size)
                throw std::out_of_range("Index out of range");
            Node<T>* toRemove;
            T removedData;
            if (this->size == 1) { 
                toRemove = this->head;
                this->head = this->tail = nullptr;
            } else if (index == 0) { 
                toRemove = this->head;
                this->head = this->head->next;
                this->head->prev = nullptr;
            } else if (index == this->size - 1) { 
                toRemove = this->tail;
                this->tail = this->tail->prev;
                this->tail->next = nullptr;
            } else { 
                toRemove = getNode(index);
                toRemove->prev->next = toRemove->next;
                toRemove->next->prev = toRemove->prev;
            }
            removedData = toRemove->data;
            delete toRemove;
            this->size--;
            return removedData;
        }

        int find(std::function<bool(const T&)> find_function) const {
            Node<T>* current = this->head;
            int index = 0;
            while (current != nullptr) {
                if (find_function(current->data))
                    return index;
                current = current->next;
                index++;
            }
            return -1; 
        }

        T& operator[](int index) {
            return getNode(index)->data;
        }

        const T& operator[](int index) const {
            return getNode(index)->data;
        }

        friend std::ostream& operator<<(std::ostream& os, const List& list) {
            Node<T>* current = list.head;
            os << "[";
            while (current != nullptr) {
                os << current->data;
                if (current->next != nullptr)
                    os << ", ";
                current = current->next;
            }
            return os << "]" << std::endl;
        }

        bool operator==(const List& other) const {
            if (this->size != other.size)
                return false;
            Node<T>* current1 = this->head;
            Node<T>* current2 = other.head;
            while (current1 != nullptr && current2 != nullptr) {
                if (current1->data != current2->data)
                    return false;
                current1 = current1->next;
                current2 = current2->next;
            }
            return true;
        }

        bool operator!=(const List& other) const {
            return !(*this == other);
        }

        size_t getSize() const {
            return this->size;
        }

        bool isEmpty() const {
            return !this->size;
        }
};


#endif

