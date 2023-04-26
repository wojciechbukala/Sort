#ifndef BUCKETSORT
#define BUCKETSORT

#include "quicksort.hpp"
#include "merge_sort.hpp"
#include <algorithm> 
#include <vector>
#include <cstring>

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    void push_back(const T& value)
    {
        Node* new_node = new Node { value, nullptr };
        if (!head)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    T& operator[](int index)
    {
        Node* current = head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current->data;
    }

    int size() const
    {
        int count = 0;
        Node* current = head;
        while (current)
        {
            ++count;
            current = current->next;
        }
        return count;
    }

    void clear()
    {
        Node* current = head;
        while (current)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }
    bool empty() const
{
    return head == nullptr;
}
};


template <typename T>
void bucket_sort(T* array, int n, int max_value) 
{
    int num_buckets = max_value + 1;
    List<T>* buckets = new List<T>[max_value];

    for(int i=0; i<n; ++i)
    {
        int iter = int(array[i])/ (max_value / (num_buckets - 1));
        buckets[iter].push_back(array[i]);
    }

    for(int i=0; i<max_value; ++i)
    {
        //std:: cout << "For2" << std::endl;
        if(!buckets[i].empty())
        {
            int length = buckets[i].size();
            T* tmp = new T[length];
            for (int j=0; j<length; ++j)
            {
                tmp[j] = buckets[i][j];
            }
            merge_sort(tmp, 0, length-1);
            for (int j=0; j<length; ++j)
            {
                buckets[i][j] = tmp[j];
            }
            delete[] tmp;
        }
    }

    int ii=0;
    for(int i=0; i<max_value; ++i)
    {
        //std:: cout << "For3" << std::endl;
        int length = buckets[i].size();
        for (int j=0; j<length; ++j)
        {
            //std:: cout << "For4" << std::endl;
            array[ii] = buckets[i][j];
            ++ii;
        }
        buckets[i].clear();
    }

    delete[] buckets;
}


/* template <typename T>
void bucket_sort(T* array, int n, int max_value) 
{
    T** buckets = new T*[max_value];

    for(int i=0; i<max_value; ++i)
    {
        buckets[i] = nullptr;
    }

    for(int i=0; i<n; ++i)
    {
        int iter = array[i];
        if(buckets[iter] == nullptr)
        {
            buckets[iter] = new T[1];
            buckets[iter][0] = array[i];
        }
        else
        {
            int length = 0;
            while(buckets[iter][length] != 0)
            {
                length++;
            }
            T* tmp = new T[length+1];
            
            for(int j=0; j<length; ++j)
            {
                tmp[j] = buckets[iter][j];
            }
            tmp[length] = array[i];
            delete[] buckets[iter];
            buckets[iter] = tmp;
            for (int j=0; j<length+1; ++j)
            {
                std::cout << buckets[iter][j] << " ";
            }
            std::cout << std::endl;
        }
            
    }

    for(int i=0; i<max_value; ++i)
    {
        if(buckets[i] != nullptr)
        {
            int size =  sizeof(buckets[i]) / sizeof(buckets[0]);
            quicksort(buckets[i], 0, size);
        }
    }

    int ii=0;
    for(int i=0; i<max_value; ++i)
    {
        if(buckets[i] != nullptr)
        {
            int length = 0; 
            while(buckets[i][length] != 0 && length < n)
            {
                array[ii] = buckets[i][length];
                ++ii;
                ++length;
            }
        delete[] buckets[i];
        }
    }
} */


#endif