#ifndef INTROSPECTIVESORT
#define INTROSPECTIVESORT


template <typename T>
void insertsort(T* array, int begin, int end)
{
    for(int j = 1; j <= end; ++j)
    {
        T insert = array[j];
        for(int i = j; i >= begin; --i)
        {
            if(insert < array[i])
            {
                array[i+1] = array[i];
                array[i] = insert;
            }
        }
    }
}

template <typename T>
void introsort(T* array, int begin, int end)
{
    if(end <= begin)
    {
        return;
    }

    int left = begin;
    int right = end ;

    T pivot = array[(left+right)/2];


    while(1)
    {
        while(array[left] < pivot) 
        {
            left++;
        }

        while(array[right] > pivot)
        {
            right--;
        }

        if(left >= right)
        {
            break;
        }
        else
        {
            T temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
    
    if(begin < right)
    {
        if(right-begin+1 > 9)
        {
            quicksort(array,begin,right);
        }
        else
        {
           insertsort(array,begin,right);
        }
    }

    if(end > left)
    {
        if(end-left+1 > 9)
        {
            quicksort(array,left+1, end);
        }
        else
        {
           insertsort(array,left+1,end);
        }
    }

}

#endif