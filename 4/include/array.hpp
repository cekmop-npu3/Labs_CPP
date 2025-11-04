#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdlib.h>
#include <variant>
#include "iter.hpp"
#include "error.hpp"
#include <iostream>
#include <variant>

namespace {
    int BUF_SIZE = 4;
    int BUF_COUNT = 3;
}

using namespace std;


template<class T>
class Array;
template<typename N>
using Elem = std::variant<N, Array<N>*>;


template<class T>
class Array : public Iter<Elem<T>> {
    private:
        Elem<T>* data;
        int len;
        int bufSize;
        int bufCount;
    public:
        Array(int bufSize = BUF_SIZE, int bufCount = BUF_COUNT) : Iter<Elem<T>>(data, len) {
            this->data = new Elem<T>[bufSize]{};
            this->bufSize = bufSize;
            this->bufCount = bufCount;
            this->len = 0;
        }
        Array(const Array& other) : Iter<Elem<T>>(data, len) {
            if (this != &other){
                this->data = new Elem<T>[other.bufSize * (other.len / other.bufSize + 1)]{};
                for (int i = 0; i < other.len; i++){
                    if (holds_alternative<Array*>(other.data[i])){
                        Array *arr = new Array();
                        *arr = *std::get<Array*>(other.data[i]);
                        this->data[i] = arr;
                    }
                    else
                        this->data[i] = other.data[i];
                }
                this->bufSize = other.bufSize;
                this->bufCount = other.bufCount;
                this->len = other.len;
            }
        }
        Array& operator=(const Array& other){
            if (this != &other){
                delete[] this->data;
                this->data = new Elem<T>[other.bufSize * (other.len / other.bufSize + 1)]{};
                for (int i = 0; i < other.len; i++){
                    if (holds_alternative<Array<T>*>(other.data[i])){
                        Array *arr = new Array<T>();
                        *arr = *get<Array<T>*>(other.data[i]);
                        this->data[i] = arr;
                    }
                    else
                        this->data[i] = other.data[i];

                }
                this->bufSize = other.bufSize;
                this->bufCount = other.bufCount;
                this->len = other.len;
            }
            return *this;
        }
        Array& operator-=(const Array& other){
            Elem<T> elem;
            for (int i = this->len - 1; i >= 0; i--){
                for (int j = 0; j < other.len; j++){
                    if ((holds_alternative<Array<T>*>(this->data[i]) &&
                         holds_alternative<Array<T>*>(other.data[j]) &&
                        (*get<Array<T>*>(this->data[i]) == *get<Array<T>*>(other.data[j]))) || 
                        (holds_alternative<T>(this->data[i]) &&
                         holds_alternative<T>(other.data[j]) &&
                         this->data[i] == other.data[j]))
                    {
                        if (holds_alternative<Array<T>*>(elem = this->pop(i)))
                            delete get<Array<T>*>(elem);
                        break;
                    }
                }
            }
            return *this;
        }
        Array operator-(const Array& other){
            Array<T> result(this->bufSize, this->bufCount);
            bool equal;
            for (int i = 0; i < this->len; i++){
                equal = false;
                for (int j = 0; j < other.len; j++)
                    if ((holds_alternative<Array<T>*>(this->data[i]) &&
                                holds_alternative<Array<T>*>(other.data[j]) &&
                                (*get<Array<T>*>(this->data[i]) == *get<Array<T>*>(other.data[j]))) || 
                            (holds_alternative<T>(this->data[i]) &&
                             holds_alternative<T>(other.data[j]) &&
                             this->data[i] == other.data[j]))
                    {
                        equal = true;
                        break;
                    }
                if (!equal)
                    result.append(holds_alternative<Array<T>*>(this->data[i]) ? *get<Array<T>*>(this->data[i]) : get<T>(this->data[i]));
            }
            return result;
        }
        Elem<T>& operator[](int index) const{
            while (index < 0)
                index = this->len + index;
            if (index > this->len - 1)
                throw ArrayError{"Array index out of range"};
            return this->data[index];
        }
        bool operator==(const Array& other) const {
            if (this->len != other.len)
                return false;
            for (int i = 0; i < this->len; i++)
                if ((holds_alternative<Array<T>*>(this->data[i]) && !(*get<Array<T>*>(this->data[i]) == *get<Array<T>*>(other.data[i]))) || 
                    (holds_alternative<T>(this->data[i]) && this->data[i] != other.data[i])
                   )
                    return false;
            return true;
        }
        ~Array(){
            for (int i = 0; i < this->len; i++)
                if (holds_alternative<Array<T>*>(this->data[i]))
                    delete get<Array<T>*>(this->data[i]);
            delete[] this->data;
            this->len = 0;
        }
        void append(std::variant<T, Array<T>> data){
            if (this->len / this->bufSize == this->bufCount)
                throw ArrayError{"Memory block limit is reached"};
            if (!((this->len + 1) % this->bufSize) and (this->len + 1) / this->bufSize != this->bufCount){
                Elem<T> *tmpData = new Elem<T>[this->bufSize * ((this->len + 1) / this->bufSize + 1)]{};
                copy(this->data, this->data + this->len, tmpData);
                delete[] this->data;
                this->data = tmpData;
            }
            if (holds_alternative<Array<T>>(data)){
                Array<T> *tmp = new Array<T>();
                *tmp = std::get<Array<T>>(data);
                this->data[this->len++] = tmp;
            }
            else
                this->data[this->len++] = std::get<T>(data);
        }
        Elem<T> pop(int index = -1){
            while (index < 0)
                index = this->len + index;
            if (index > this->len - 1)
                throw ArrayError{"Array index out of range"};
            Elem<T> elem = this->data[index];
            for (int i = 0; i < this->len - 1; i++)
                this->data[i] = (i >= index ? this->data[i + 1] : this->data[i]);
            this->len--;
            return elem;
        }
        void print(bool wrapped = false) const {
            cout << "[";
            for (int i = 0; i < this->len; i++){
                if (holds_alternative<T>(this->data[i]))
                    cout << get<T>(this->data[i]);
                else 
                    get<Array<T>*>(this->data[i])->print(true);
                if (i != this->len - 1)
                    cout << ", ";
            }
            cout << "]" << (wrapped ? "" : "\n");
        }
};

#endif

