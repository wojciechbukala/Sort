#ifndef QUICKSORT
#define QUICKSORT

/* template <typename T>
void quicksort(T* array, int begin, int end)
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
        quicksort(array,begin,right);
    }
    
    if(end > left)
    {
        quicksort(array,left+1,end);
    } 


} */


template <typename T>
void quicksort(T* array, int begin, int end)
{
    if(end <= begin)
    {
        return;
    }

    int left = begin;
    int right = end ;

    T pivot = array[(left+right)/2];

    while(left <= right)
    {
        while(array[left] < pivot) 
        {
            left++;
        }

        while(array[right] > pivot)
        {
            right--;
        }

        if(left <= right)
        {
            if(array[left] == array[right])
            {
                left++;
                right--;
            }
            else
            {
                T temp = array[left];
                array[left] = array[right];
                array[right] = temp;
                left++;
                right--;
            }
        }
    }

    if(begin < right)
    {
        quicksort(array,begin,right);
    }

    if(end > left)
    {
        quicksort(array,left,end);
    } 
}
#endif
