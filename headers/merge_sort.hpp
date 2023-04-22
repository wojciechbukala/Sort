#ifndef MERGE_SORT
#define MERGE_SORT

template <typename T>
void merge(T array, int begin, int middle, int end)
{
    int left = begin;
    int right = middle + 1;
    int i = 0;

    T *tmp;

    while(left <= middle && right <= end)
    {
        if(array[left] < array[right])
        {
            *tmp[i] = array[left];
        }
        else
        {
            *tmp[i] = array[right];
        }
        ++i;
        ++left;
        ++right;
    }

    while(left <= middle)
    {
        *tmp[i] = array[left];
        ++left;
        ++i;
    }

    while(right <= end)
    {
        *tmp[i] = array[right];
        ++right;
        ++i;
    }

    for(int j = 0; j <= end; ++j)
    {
        array[begin+j] = *tmp[j];
    }

}

template <typename T>
void merge_sort(T* array, int begin, int end)
{
    if(begin == end)
    {
        return;
    }
    int middle = (begin+end)/2;

    merge_sort(array,begin,middle);
    merge_sort(array,middle+1,end);

    merge(array, begin, middle, end);

}

#endif