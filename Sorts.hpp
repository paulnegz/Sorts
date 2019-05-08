/* File Name: Sorts.hpp
 * Author: Paul Ngedu
 * EECS 268 - Lab 7
 * Description: Defines methods used to time sorts used in other classes
 * Last edited - April 13th, 2019
 *------------------------------------------------------------------------*/

#include "Sorts.h"

using namespace std;

template <typename T>
Sorts<T>::Sorts()
{

}

template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
    if(size > 1)
    {
        T tempArr;
        bool swapped = true;
        while(swapped) //loops until the sort algorithm no longer finds an error in the array
        {
            swapped = false;
            for(int i = 0; i < size-1; i++)
            {
                if(arr[i] > arr[i+1]) //compares current array value to next array value
                {
                    tempArr = arr[i+1];
                    arr[i+1] = arr[i];
                    arr[i] = tempArr;
                    swapped = true;
                }
            }
        }
    }
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
    int posTrack;
    for(int i = 0; i < size; i++)
    {
        T min = arr[i]; //temporary minimum value
        T tempArr = arr[i];
        for(int j = 1; j < size; j++)
        {
            if(min > arr[j])
            {
                posTrack = j;
                min = arr[j];
            }
        }
        arr[posTrack] = tempArr; //moves the array value to the desired spot
        arr[i] = min;
    }
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
    if(size > 1)
    {
        T tempArr;
        for(int i = 1; i < size; i++)
        {
            if(arr[i] < arr[i-1])
            {
                for(int j = 0; j < i; j++)
                {
                    if(arr[i] < arr[j])
                    {
                        tempArr = arr[i];
                        //Move desired array values forward to make room for "inserted" value
                        for(int k = i; k > j; k--)
                        {
                            arr[k] = arr[k-1];
                        }
                        arr[j] = tempArr;
                    }
                }
            }
        }
    }
}

template <typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
    if(size != 1)
    {
       mergeSort(arr, size/2);
       mergeSort(arr + size/2, size-size/2);
    }
    merge(arr, arr+size/2, size/2, size-size/2);
}

template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
    if(size > 1)
    {
        //calls recursive function
        quickSortRec(arr, 0, size-1, 0);
    }
}

template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
    if(size > 1)
    {
        //calls recursive function
        quickSortRec(arr, 0, size-1, 1);
    }
}

//
//All of the following private methods are subroutines used by public methods
//

template <typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
{
    int a=0;
    int b=0;
    int i=0;
    T* tempArr = new T[size1+size2];
    while (a < size1 && b < size2)
    {
        if (a1[a] <= a2[b])
        {
            tempArr[i] = a1[a];
            a++;
        }
        else
        {
            tempArr[i] = a2[b];
            b++;
        }
        i++;
    }
    while (a < size1)
    {
        tempArr[i] = a1[a];
        i++;
        a++;
    }
    while (b < size2)
    {
        tempArr[i] = a2[b];
        i++;
        b++;
    }
    for (int i = 0; i < size1 + size2; i++)
    {
        a1[i] = tempArr[i];
    }
}

template <typename T>
bool Sorts<T>::finished(T arr[],int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    if (arr[i] > arr[i+1])
    {
      return false;
    }
  }
  return true;
}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
    if ((last - first) >= 1 && !finished(arr, last+1))
    {
        int pivot = partition(arr, first, last, median);
        quickSortRec(arr, 0, pivot-1, median);
        quickSortRec(arr+pivot+1, 0, last-pivot-1, median);
    }
}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
    if (last-first > 1)
    {
        T* tempArr = new T[3];
        tempArr[0] = arr[first];
        tempArr[1] = arr[(first+last)/2];
        tempArr[2] = arr[last];
        for (int i=0;i<1;i++)
        {
            if (tempArr[i] > tempArr[i+1])
            {
                T temp = tempArr[i+1];
                tempArr[i+1] = tempArr[i];
                tempArr[i] = temp;
            }
        }
        T temp = tempArr[1],set;
        if (temp == arr[first])
        {
            set = first;
        }
        else if (temp == arr[last])
        {
            set = last;
        }
        else
        {
            set = (first+last)/2;
        }
        swap(arr[set], arr[last]);
    }

}

template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
    if (median) //runs code if user wants to use a quick sort with a median
    {
        setMedianPivot(arr,first,last);
    }
    if (last-first == 1)
    {
        if (arr[first] > arr[last])
        {
        swap(arr[first], arr[last]); //swap(int a, int b) is in standard cstlib library
        return (1);
        }
    }
    else
    {
        bool check = true;
        int a = first;
        int b = last - 1;
        T pivotval = arr[last];
        while (a != b) //runs until first and last are 1 apart
        {
            if (arr[a] < pivotval)
            {
                a++;
            }
            else
            {
                check = false;
                swap(arr[a], arr[b]);
                if (arr[a] >= pivotval)
                {
                    b--;
                }
            }
        }
        if (check && (arr[b] < pivotval)) return(a+1);
        else if (check)
        {
            swap(arr[b], arr[last]);
            return(a+1);
        }
        swap(arr[a], arr[last]);
        return a;
  }
}

template<class T>
void Sorts<T>::order(T arr[], int i, int j)
{
   if (arr[i] > arr[j]) swap(arr[i], arr[j]);
}

template<class T>
void Sorts<T>::finishSort(T arr[], int first, int last)
{
    for (int i = first + 1; i <= last; i++)
    {
      T nextItem = arr[i];
      int loc = i;
      while ((loc > first) && (arr[loc - 1] > nextItem)) //compare array value to previous array value
      {
         arr[loc] = arr[loc - 1];
         loc--;
      }
      arr[loc] = nextItem;
   }
}

template <typename T>
Sorts<T>::~Sorts()
{


}
