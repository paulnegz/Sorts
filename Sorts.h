/* File Name: Sorts.h
 * Author: Paul Negedu
 * EECS 268 - Lab 7
 * Description: Delcares each sort needed by the Executive class
 * Last edited - April 13th, 2019
 *------------------------------------------------------------------------*/

#ifndef SORTS_H
#define SORTS_H

#include "SortTimer.h"
#include <functional>
#include <cstdlib>

template <typename T>
class Sorts
{
public:
  /** @pre None.
	*   @post None.
	*   @return None.
	*/
  Sorts();

  /** @pre None.
	*   @post None.
	*   @return None.
	*/
  ~Sorts();

  /** @pre None
	*   @post Sorts the array using a bubble sort algorithm.
	*   @return None.
	*/
  static void bubbleSort(T arr[], int size);

  /** @pre None
	*   @post Sorts the array using a selection sort algorithm.
	*   @return None.
	*/
  static void selectionSort(T arr[], int size);

  /** @pre None
	*   @post Sorts the array using an insertion sort algorithm.
	*   @return None.
	*/
  static void insertionSort(T arr[], int size);

  /** @pre None
	*   @post Recurses until it reaches a size of 1 and then merges using the merge function.
	*   @return None.
	*/
  static void mergeSort(T arr[], int size);

  /** @pre None
	*   @post Calls the quickSortRec function without the median flag.
	*   @return None.
	*/
  static void quickSort(T arr[], int size);
      //Calls quickSort with median flag set to false

  /** @pre None
	*   @post Calls the quickSortRec function to quick sort an algorithm.
	*   @return None.
	*/
  static void quickSortWithMedian(T arr[], int size);
      //Calls quickSortRec with median flag set to true

private:
  /** @pre None.
	*   @post This function is recursive and calls itself until it can solve itself.
	*   @return None.
	*/
  static void merge(T* a1, T* a2, int size1, int size2);

  /** @pre None.
	*   @post Recursive function that calls itself until a segmented array
  *                   reaches a size of 1.
	*   @return None.
	*/
  static void quickSortRec(T arr[], int first, int last, bool median);

  /** @pre None.
	*   @post Sets the pivot desired by the programmer given an array's current size.
	*   @return None.
	*/
  static void setMedianPivot(T arr[], int first, int last);

  /** @pre None.
	*   @post Determines a partition array index.
	*   @return None.
	*/
  static int partition(T arr[], int first, int last, bool median);

  /** @pre None.
	*   @post Small subroutine I made to find the middle value in three indeces.
	*   @return None.
	*/
  static void order(T arr[], int i, int j);

  /** @pre None
	*   @post Finishes sorting the segmented array when it reaches a small enough size.
	*   @return None.
	*/
  static void finishSort(T arr[], int first, int last);

  /** @pre None.
	*   @post None.
	*   @return Whether the sorting algorithm has finished sorting the array.
	*/
  static bool finished(T arr[],int size);

};
#include "Sorts.hpp"
#endif
