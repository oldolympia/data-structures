//
//  main.cpp
//  data hw 4
//
//  Created by Olympia Pyburn on 10/15/19.
//  Copyright © 2019 Olympia Pyburn. All rights reserved.
//
// used https://www.chegg.com/homework-help/questions-and-answers/c-programming-write-recursive-function-tonumber-forms-integer-sum-digit-characters-string--q11112485 for help on question 2.
//used https://www.chegg.com/homework-help/questions-and-answers/c-programmatically-generate-three-type-arrays-vectors-size-10-000-array-sorted-ascending-o-q11112535 for the sort question.


// Header files section
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

int mystery(int n) {
    if (n == 0){
        return 0;
    }
    else{
        cout << n * n + mystery(n - 1) << " ";
        return n * n + mystery(n - 1);
    }
}

int to_number(string str)
{
   if (str == " " || str.length() == 0){
       return 0;
   }
    
   char next = str.at(0);
    
   if (isdigit(next) == true){
       return next - '0' + to_number(str.substr(1));
   }
    
   else{
       return to_number(str.substr(1));
   }
}


int findItem(int vector[], int top, int num){

    if (top < 0){
        return -1;
    }

    if (vector[top] == num){
        return 2;
    }

    else{
        return findItem(vector, top - 1, num);
    }
}

// constants
const int MAX_SIZE = 10000;
const int ALGORITHMS = 7;
const int TYPES = 3;
const int RANDOM = 0;
const int SORTED = 1;
const int REVERSED = 2;
const int BUBBLE = 0;
const int SELECTION = 1;
const int INSERTION = 2;
const int SHELL = 3;
const int MERGE = 4;
const int QUICK1 = 5;
const int QUICK2 = 6;

// global arrays
string algorithms[] = { "Bubble Sort Improved", "Selection Sort", "Insertion Sort", "Shell Sort", "Merge Sort", "Quick Sort", "Quick Sort Improved" };
int exchanges[ALGORITHMS][TYPES] = { {0, 0, 0}, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
int comparisons[ALGORITHMS][TYPES] = { { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };

// generate_array function implementation
void generate_array(int arr[], int size, int type)
{
   if (type == RANDOM)
   {
       for (int i = 0; i < size; i++)
       {
           arr[i] = rand() % size;
       }
   }
   else if (type == SORTED)
   {
       for (int i = 0; i < size; i++)
       {
           arr[i] = i;
       }
   }
   else if (type == REVERSED)
   {
       for (int i = size - 1; i >= 0; i--)
       {
           arr[i] = i;
       }
   }
}

// swap function implementation
void swap(int arr[], int i, int j)
{
   int temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
}

// bubble_sort function implementation
void bubble_sort(int arrBubble[], int size, int type)
{
   bool swapped = false;
   for (int i = 1; i < size; i++)
   {
       swapped = false;
       for (int j = 0; j < size - i; j++)
       {
           comparisons[BUBBLE][type]++;
           if (arrBubble[j + 1] < arrBubble[j])
           {
               exchanges[BUBBLE][type]++;
               swap(arrBubble, j, j + 1);
               swapped = true;
           }
       }

       if (!swapped)
           break;
   }
}

// selection_sort function implementation
void selection_sort(int arrSelection[], int size, int type)
{
   for (int i = 0; i < size - 1; i++)
   {
       int minPos = i;

       for (int j = i + 1; j < size; j++)
       {
           comparisons[SELECTION][type]++;
           if (arrSelection[j] < arrSelection[minPos])
           {
               minPos = j;
           }
       }

       if (minPos != i)
       {
           exchanges[SELECTION][type]++;
           swap(arrSelection, minPos, i);
       }
   }
}

// insertion_sort function implementation
void insertion_sort(int arrInsertion[], int size, int type)
{
   for(int i = 1; i < size; i++)
   {
       int temp = arrInsertion[i];
       int j = i;

       comparisons[INSERTION][type]++;
       while (j > 0 && temp < arrInsertion[j - 1])
       {
           exchanges[INSERTION][type]++;
           arrInsertion[j] = arrInsertion[j - 1];
           j--;
       }

       arrInsertion[j] = temp;
   }
}

// shell_sort function implementation
void shell_sort(int arrShell[], int size, int type)
{
   int gap = size / 2;
   while (gap > 0)
   {
       for (int i = gap; i < size; i++)
       {
           for (int j = i; j >= gap; j -= gap)
           {
               comparisons[SHELL][type]++;
               if (arrShell[j] < arrShell[j - gap])
               {
                   exchanges[SHELL][type]++;
                   swap(arrShell, j, j - gap);
               }
               else
               {
                   break;
               }
           }
       }

       gap = gap / 2;
   }
}

// merge function implementation
void merge(int arrMerge[], int left, int middle, int right, int type)
{
   int i, j, k;
   int leftSize = middle - left + 1;
   int rightSize = right - middle;

   int leftArr[MAX_SIZE];
   int rightArr[MAX_SIZE];

   for (i = 0; i < leftSize; i++)
   {
       exchanges[MERGE][type]++;
       leftArr[i] = arrMerge[left + i];
   }

   for (j = 0; j < rightSize; j++)
   {
       exchanges[MERGE][type]++;
       rightArr[j] = arrMerge[middle + 1 + j];
   }

   i = 0;
   j = 0;
   k = left;

   while (i < leftSize && j < rightSize)
   {
       comparisons[MERGE][type]++;
       if (leftArr[i] <= rightArr[j])
       {
           exchanges[MERGE][type]++;
           arrMerge[k] = leftArr[i];
           i++;
       }
       else
       {
           exchanges[MERGE][type]++;
           arrMerge[k] = rightArr[j];
           j++;
       }
       k++;
   }

   while (i < leftSize)
   {
       exchanges[MERGE][type]++;
       arrMerge[k] = leftArr[i];
       i++;
       k++;
   }

   while (j < rightSize)
   {
       exchanges[MERGE][type]++;
       arrMerge[k] = rightArr[j];
       j++;
       k++;
   }
}

// merge_sort helper function implementation
void merge_sort(int arrMerge[], int left, int right, int type)
{
   if (left < right)
   {
       int middle = left + (right - left) / 2;

       merge_sort(arrMerge, left, middle, type);
       merge_sort(arrMerge, middle + 1, right, type);

       merge(arrMerge, left, middle, right, type);
   }
}

// merge_sort function implementation
void merge_sort(int arrMerge[], int size, int type)
{
   merge_sort(arrMerge, 0, size - 1, type);
}

// partition function implementation
int partition(int arrQuickRegular[], int left, int right, int type)
{
   int p = left + 1;
   int q = right - 1;

   do
   {
       comparisons[QUICK1][type]++;
       while(p < right && arrQuickRegular[p] <= arrQuickRegular[left])
       {
           p++;
       }

       comparisons[QUICK1][type]++;
       while(arrQuickRegular[left] < arrQuickRegular[q])
       {
           q--;
       }

       if (p < q)
       {
           exchanges[QUICK1][type]++;
           swap(arrQuickRegular, p, q);
       }
   } while (p < q);

   exchanges[QUICK1][type]++;
   swap(arrQuickRegular, q, left);

   return q;
}

// quick_sort helper function implementation
void quick_sort(int arrQuickRegular[], int left, int right, int type)
{
   if (right - left > 1)
   {
       int pivot = partition(arrQuickRegular, left, right, type);
       quick_sort(arrQuickRegular, left, pivot, type);
       quick_sort(arrQuickRegular, pivot + 1, right, type);
   }
}

// quick_sort function implementation
void quick_sort(int arrQuickRegular[], int size, int type)
{
   quick_sort(arrQuickRegular, 0, size, type);
}

// sort_median function implementation
void sort_median(int arrQuickImproved[], int left, int right, int type)
{
   int middle = (left + right) / 2;

   if (arrQuickImproved[left] > arrQuickImproved[middle])
   {
       exchanges[QUICK2][type]++;
       swap(arrQuickImproved, left, middle);
   }

   if (arrQuickImproved[middle] > arrQuickImproved[right])
   {
       exchanges[QUICK2][type]++;
       swap(arrQuickImproved, middle, right);
   }

   if (arrQuickImproved[left] > arrQuickImproved[middle])
   {
       exchanges[QUICK2][type]++;
       swap(arrQuickImproved, left, middle);
   }

   exchanges[QUICK2][type]++;
   swap(arrQuickImproved, middle, left);
}

// middle_partition function implementation
int middle_partition(int arrQuickImproved[], int left, int right, int type)
{
   int p = left + 1;
   int q = right - 1;
   sort_median(arrQuickImproved, left, right - 1, type);
   int middle = left;

   do
   {
       comparisons[QUICK2][type]++;
       while (p < right - 1 && arrQuickImproved[p] <= arrQuickImproved[middle])
       {
           p++;
       }

       comparisons[QUICK2][type]++;
       while (arrQuickImproved[middle] < arrQuickImproved[q])
       {
           q--;
       }

       if (p < q)
       {
           exchanges[QUICK2][type]++;
           swap(arrQuickImproved, p, q);
       }
   } while (p < q);

   exchanges[QUICK2][type]++;
   swap(arrQuickImproved, middle, q);

   return q;
}

// middle_quick_sort helper function implementation
void middle_quick_sort(int arrQuickImproved[], int left, int right, int type)
{
   if (right - left > 1)
   {
       int pivot = middle_partition(arrQuickImproved, left, right, type);
       middle_quick_sort(arrQuickImproved, left, pivot, type);
       middle_quick_sort(arrQuickImproved, pivot + 1, right, type);
   }
}

// middle_quick_sort function implementation
void middle_quick_sort(int arrQuickImproved[], int size, int type)
{
   middle_quick_sort(arrQuickImproved, 0, size, type);
}

// print_array function implementation
void print_array(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   {
       if (i != 0 && i % 50 == 0)
           cout << endl;

       cout << arr[i] << " ";
   }
}

// start main function
int main()
{
    
    //for question 2
       string str;

       cout << "Enter string:";
       cin >> str;

       cout << to_number(str) << endl;
        
    //for question 3
        const int top = 7;
        int vector[top] = {2, 3, 7, 9, 14, 21, 28};
        int num = 0;
        
        cout << "Enter a number to search for." << ' ';
        cin >> num;
        

        if (findItem (vector, top, num) == -1){
        cout << num << " not found.\n";
        }
        else{
            cout << num << " found.\n";
        }
    
    
   srand(time(NULL));

   int type;
   int size;
   int arr[MAX_SIZE];
   int arrBubble[MAX_SIZE];
   int arrSelection[MAX_SIZE];
   int arrInsertion[MAX_SIZE];
   int arrShell[MAX_SIZE];
   int arrMerge[MAX_SIZE];
   int arrQuickRegular[MAX_SIZE];
   int arrQuickImproved[MAX_SIZE];

   cout << "Enter the size of the array [1-10000]: ";
   cin >> size;

   while (size < 1 || size > MAX_SIZE)
   {
       cout << "Enter valid size of the array [1-10000]: ";
       cin >> size;
   }

   type = RANDOM;
   generate_array(arr, size, type);
  
   for (unsigned int i = 0; i < size; i++)
   {
       arrBubble[i] = arr[i];
       arrSelection[i] = arr[i];
       arrInsertion[i] = arr[i];
       arrShell[i] = arr[i];
       arrMerge[i] = arr[i];
       arrQuickRegular[i] = arr[i];
       arrQuickImproved[i] = arr[i];
   }

   bubble_sort(arrBubble, size, type);
   selection_sort(arrSelection, size, type);
   insertion_sort(arrInsertion, size, type);
   shell_sort(arrShell, size, type);
   merge_sort(arrMerge, size, type);
   quick_sort(arrQuickRegular, size, type);
   middle_quick_sort(arrQuickImproved, size, type);

   type = SORTED;
   generate_array(arr, size, type);

   for (unsigned int i = 0; i < size; i++)
   {
       arrBubble[i] = arr[i];
       arrSelection[i] = arr[i];
       arrInsertion[i] = arr[i];
       arrShell[i] = arr[i];
       arrMerge[i] = arr[i];
       arrQuickRegular[i] = arr[i];
       arrQuickImproved[i] = arr[i];
   }

   bubble_sort(arrBubble, size, type);
   selection_sort(arrSelection, size, type);
   insertion_sort(arrInsertion, size, type);
   shell_sort(arrShell, size, type);
   merge_sort(arrMerge, size, type);
   quick_sort(arrQuickRegular, size, type);
   middle_quick_sort(arrQuickImproved, size, type);
  
   type = REVERSED;
   generate_array(arr, size, type);

   for (unsigned int i = 0; i < size; i++)
   {
       arrBubble[i] = arr[i];
       arrSelection[i] = arr[i];
       arrInsertion[i] = arr[i];
       arrShell[i] = arr[i];
       arrMerge[i] = arr[i];
       arrQuickRegular[i] = arr[i];
       arrQuickImproved[i] = arr[i];
   }

   bubble_sort(arrBubble, size, type);
   selection_sort(arrSelection, size, type);
   insertion_sort(arrInsertion, size, type);
   shell_sort(arrShell, size, type);
   merge_sort(arrMerge, size, type);
   quick_sort(arrQuickRegular, size, type);
   middle_quick_sort(arrQuickImproved, size, type);

   cout << "\n\nComparing the number of comparisons..." << endl;
   cout << "---------------------------------------------------------------------" << endl;
   cout << left << setw(25) << "" << setw(15) << "Random Array" << setw(15) << "Sorted Array" << setw(15) << "Reversed Array" << endl;
   cout << "---------------------------------------------------------------------" << endl;
   for (int i = 0; i < ALGORITHMS; i++)
   {
       cout << setw(25) << algorithms[i] << setw(15) << comparisons[i][RANDOM] << setw(15) << comparisons[i][SORTED] << setw(15) << comparisons[i][REVERSED] << endl;
   }
   cout << "---------------------------------------------------------------------" << endl;

   cout << "\n\nComparing the number of exchanges..." << endl;
   cout << "---------------------------------------------------------------------" << endl;
   cout << left << setw(25) << "" << setw(15) << "Random Array" << setw(15) << "Sorted Array" << setw(15) << "Reversed Array" << endl;
   cout << "---------------------------------------------------------------------" << endl;
   for (int i = 0; i < ALGORITHMS; i++)
   {
       cout << setw(25) << algorithms[i] << setw(15) << exchanges[i][RANDOM] << setw(15) << exchanges[i][SORTED] << setw(15) << exchanges[i][REVERSED] << endl;
   }
   cout << "---------------------------------------------------------------------" << endl;

   return 0;
}



