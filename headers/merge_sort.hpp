#ifndef MERGE_SORT
#define MERGE_SORT

template <typename T>
void merge(T* array, int begin, int middle, int end)
{
    int left = begin;
    int right = middle + 1;
    int i = 0;

    T *tmp = new T[end-begin +1];

    while(left <= middle && right <= end)
    {
        if(array[left] < array[right])
        {
            tmp[i] = array[left];
            ++left;
        }
        else
        {
            tmp[i] = array[right];
            ++right;
        }
        ++i;
    }

    while(left <= middle)
    {
        tmp[i] = array[left];
        ++left;
        ++i;
    }

    while(right <= end)
    {
        tmp[i] = array[right];
        ++right;
        ++i;
    }


    for(int j = 0; j < end - begin + 1; ++j)
    {
        array[begin+j] = tmp[j];
    }

    delete[] tmp;
}

template <typename T>
void merge_sort(T* array, int begin, int end)
{
    if(begin < end)
    {
        int middle = (begin+end)/2;

        merge_sort(array,begin,middle);
        merge_sort(array,middle+1,end);

        merge(array, begin, middle, end);
    }

}


#endif