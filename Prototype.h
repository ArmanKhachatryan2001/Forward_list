#ifndef PROTOTYPE_H
#define PROTOTYPE_H

template <typename T>
class list {
private:
template <typename>
    struct node {
        T count;
        node<T>* next;
        node(T number , node<T>* new_next = nullptr) :
            count(number),
            next(new_next)
        {}
        ~node() {}
    };
    node<T>* ptr;
public :
template<typename>
class iterator : public std::iterator<std::forward_iterator_tag,T>
{
    public:
        iterator(): m_item(nullptr)
    {}
        iterator(const iterator& obj): m_item(obj.m_item)
    {}
        iterator(node<T>*obj)  : m_item(obj)
    {}

        iterator& operator=(const iterator& obj)
        {
            m_item = obj.m_item;
            return *this;
        }

        iterator& operator++()
        {
            m_item = m_item -> next;
            return *this;
        }
        iterator operator++(int)
        {
             iterator tmp{*this};
             ++*this;
             return tmp;
        }

        T& operator*()
        {
            return m_item -> count;
        }
        const T& operator*() const
        {
            return m_item -> count;
        }

        T* operator->()
        {
            return &(m_item -> count);
        }
        const T* operator->() const
        {
            return &(m_item -> count);
        }

        bool operator==(const iterator& obj) const
        {
            return (m_item == obj.m_item);
        }
        bool operator!=(const iterator& obj) const
        {
            return !(*this == obj);
        }

    private:
        friend class list<T>;
        node<T>* m_item;
};
    list() : ptr(nullptr) {}
    list(std::initializer_list<T> obj) : ptr(nullptr) {
        for(T item : obj) {
            push_back(item);
        }
    }
    list(const list<T>& obj) {
        copy_list(ptr,obj.ptr);
    }
    list(list<T>&&);
    list& operator=(const list<T>&);
    list& operator=(list<T>&&);
    template<typename T1>
    friend std::ostream& operator<<(std::ostream& cout,list<T1>&);
    ~list() {}
    std::vector<T> print;
    iterator<T> begin();
    iterator<T> end();
    iterator<T> erase_after(iterator<T> position);
    iterator<T> insert_after(iterator<T> position, T&& obj);
    void remove(T value);
    void merge(list&);
    void resize(int);
    void reverse();
    void assign(size_t,T);
    void clear();
    void swap(list&);
    void push_front(T value);
    void pop_front();
    void copy_list(node<T>*&,node<T>*);
    void push_back(T count);
    void print_count();
    void sort();
};

#include "Implimentation.h"
#endif //PROTOTYPE_H
