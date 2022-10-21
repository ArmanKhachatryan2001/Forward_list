template <typename T>
void list<T>::remove(T value)
{
  node<T>* new_p = ptr;
  node<T>* new_ptr = ptr;
  while(new_ptr->count == value) {
      new_p = new_ptr->next;
      delete new_ptr;
       ptr = new_p;
       new_ptr = new_p->next;
       ptr = new_ptr;
  }
  while(new_ptr != nullptr) {
      if(new_ptr->count == value) {
          new_p->next = new_ptr->next;
          delete new_ptr;
      }
      new_p = new_ptr;
      new_ptr = new_ptr->next;
  }
}

template <typename T>
void list<T>::merge(list& obj)
{
    if (obj.ptr == nullptr) {
        return;
    }
    if (ptr == nullptr) {
        ptr = obj.ptr;
    } else {
        node<T>* new_ptr = ptr;
        node<T>* pt = obj.ptr;
        node<T>* prev = ptr;
        while (new_ptr != nullptr && pt != nullptr) {
            if (new_ptr->count > pt->count) {
                obj.ptr = obj.ptr->next;
                if (new_ptr == ptr) {
                    pt->next = prev;
                    ptr = pt;
                    new_ptr = ptr;
                } else {
                    pt->next = new_ptr;
                    prev->next = pt;
                    prev = pt;
                }
                pt = obj.ptr;
            } else {
                prev = new_ptr;
                new_ptr = new_ptr->next;
            }
        }
        if (new_ptr == nullptr && pt != nullptr) {
            prev->next = pt;
            pt = nullptr;
        }
    prev = nullptr;
    new_ptr = nullptr;
    }
    obj.ptr = nullptr;
}
/*list* merge(list* ptr, list* ptr1) {
    if (ptr == nullptr || obj.ptr == nullptr) {
        if (ptr) {
            return;
        } else {
            ptr = obj.ptr;
            return;
        }
        if (ptr->count >= obj.ptr->count) {
            ptr->next = merge(ptr->next, obj.ptr);
            return;
        } else {
            obj.ptr->next = merge(ptr, obj.ptr->next);
            return;
        }
    }
*/
template <typename T>
void list<T>::resize(int size)
{
    int new_size{};
    if(ptr == nullptr) {
        for(int i = 0;i < size;++i) {
            push_back(0);
        }
        return;
    }
    for(iterator<T> it = begin();it != end();++it){
        ++new_size;
    }
    size -= new_size;
    while(size) {
         push_back(0);
        --size;
    }
}

template <typename T>
void list<T>::reverse()
{
    node<T>* new_ptr = ptr;
    print_count();
    int i = print.size()-1;
    ptr = new_ptr;
    for(iterator<T> it = begin();it != end();++it) {
        *it = print[i];
        --i;
    }
    print.clear();
}

template <typename T>
void list<T>::sort()
{
    iterator<T> i = begin();
    for(;i != end();++i) {
        std::iter_swap(i, std::min_element(i, end()));
    }
}
template <typename T>
void list<T>::assign(size_t index,T value)
{
    clear();
    for(int i = 0;i < index;++i) {
        push_front(value);
    }
}
template <typename T>
list<T>::iterator<T> list<T>::insert_after(iterator<T> position, T&& obj)
{
    node<T>* new_ptr = new node<T>(obj);
    new_ptr->next = position.m_item->next;
    position.m_item->next = new_ptr;
    return position;
}

template <typename T>
list<T>::iterator<T> list<T>::erase_after(iterator<T> position)
{
    node<T>* _ptr = position.m_item->next;
    position.m_item->next = _ptr->next;
    delete _ptr;
    return position;
}

template <typename T>
void list<T>::swap(list& obj)
{
    node<T>* n_ptr = this-> ptr;
    this-> ptr = obj.ptr;
    obj.ptr = n_ptr;
}

template <typename T>
void list<T>::clear()
{
    while(ptr != nullptr) {
        pop_front();
    }
}

template <typename T>
list<T>::iterator<T> list<T>::end()
{
    return nullptr;
}

template <typename T>
list<T>::iterator<T> list<T>::begin()
{
    return ptr;
}
template <typename T>
std::ostream& operator<<(std::ostream& cout,list<T>& obj)
{
    obj.print_count();
    for(auto it : obj.print) {
        cout << it << " ";
    }
    obj.print.clear();
    return cout;
}
template <typename T>
list<T>& list<T>::operator=(list<T>&& obj)
{
    ptr = obj.ptr;
    obj.ptr = nullptr;
    return *this;
}
template <typename T>
list<T>& list<T>::operator=(const list<T>& obj)
{
    copy_list(ptr, obj.ptr);
    return *this;
}
template <typename T>
list<T>::list(list<T>&& obj)
{
    ptr = obj.ptr;
    obj.ptr = nullptr;
}
template <typename T>
void list<T>::copy_list(node<T>*& root,node<T>* troot)
{
    if(troot == nullptr) {
        root = nullptr;
        return;
    }
    root = new node<T>(troot-> count);
    copy_list(root -> next, troot -> next);
}
template <typename T>
void list<T>::push_back(T count)
{
    if(ptr == nullptr) {
        ptr = new node<T>(count);
    } else {
        node<T>* new_ptr = ptr;
        while( new_ptr -> next != nullptr) {
            new_ptr = new_ptr -> next;
        }
        new_ptr -> next = new node<T>(count);
    }
}

template <typename T>
void list<T>::push_front(T value)
{
    node<T>* new_ptr = new node<T>(value);
    new_ptr -> next = ptr;
    ptr = new_ptr;
}

template <typename T>
void list<T>::pop_front()
{
    node<T>* new_ptr = ptr -> next;
    delete ptr;
    ptr = new_ptr;
}

template <typename T>
void list<T>::print_count()
{
    while(ptr != nullptr){
        print.push_back(ptr -> count);
        ptr = ptr-> next;
    }
}
