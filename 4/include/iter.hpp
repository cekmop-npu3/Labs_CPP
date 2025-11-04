#ifndef __ITER_H__
#define __ITER_H__


template<class T>
class Iter {
    private:
       T*& container;
       int& len;
       int counter;
    public:
        explicit Iter(T*& container, int &len) : container(container), len(len), counter(0) {}
        Iter(const Iter& other) : container(other.container), len(other.len), counter(other.counter) {}
        T operator*() const {return this->container[this->counter];}
        bool operator!=(const Iter& other) const {
            return this->container && this->len ? this->counter != other.counter : false;
        }
        Iter& operator++(){
            ++this->counter;
            return *this;
        }
        Iter begin() const {
            Iter start = *this;
            start.counter = 0;
            return start;
        }
        Iter end() const {
            Iter end = *this;
            end.counter = this->len;
            return end;
        }
};

#endif

