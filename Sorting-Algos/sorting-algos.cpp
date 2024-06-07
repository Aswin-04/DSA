#include <bits/stdc++.h>
using namespace std;

// Time-Complexity -> O(n^2)

void selectionSort(vector<int> &arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        int minIndex = i;

        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    return;
}

// -----------------------------------------------------

// Time-Complexity -> O(n^2)
// Best-case -> O(n) if the arr is sorted

void bubbleSort(vector<int> &arr, int n)
{

    for (int i = n - 1; i >= 1; i--)
    {

        int didSwap = 0;

        for (int j = 0; j < i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }

        if (!didSwap)
            return;
    }
}

void recursiveBubbleSort(vector<int> &arr, int n) {

    if (n==1) return;
    
    for(int i=0; i <= n-2; i++) {

        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }

    recursiveBubbleSort(arr, n-1);
}

// -----------------------------------------------------

// Time-Complexity -> O(n^2)
// Best-case -> O(n) if the array is sorted

void insertionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j = i;

        while (j >= 0 && arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}

void recursiveInsertionSort(vector<int> &arr,int i, int n) {

    if(i == n-1) return;

    int j = i;

    while(j >= 0 && arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
        j--;
    }

    recursiveInsertionSort(arr, i+1, n);   
}

// -----------------------------------------------------

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high) {

        if(arr[left] < arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        } 
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i <= high; i++) {
        arr[i] = temp[i-low];
    }

}
 

// Time complexity -> O(n log n)
// Space complexity -> O(n)


void mergeSort(vector<int> &arr, int low, int high)
{

    if (low >= high)
        return;
    int mid = (high + low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

// -----------------------------------------------------


int partition(vector<int> &arr, int low, int high) {

    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i <= j) {

        while(arr[i] <= pivot && i <= high-1) {
            i++;
        }

        while(arr[j] > pivot && j >= low+1) {
            j--;
        }

        if(i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}

// Time complexity -> O(n log n)
// Space complexity -> O(1)

void quickSort(vector<int> &arr, int low, int high) {

    if (low >= high) return;
    int pIndex = partition(arr, low, high);
    quickSort(arr, low, pIndex-1);
    quickSort(arr, pIndex+1, high);
}



// -----------------------------------------------------

int main()
{
    int n;
    cin >> n;
    vector<int> arrNum(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arrNum[i];
    }

    selectionSort(arrNum, n);

    bubbleSort(arrNum, n);
    recursiveBubbleSort(arrNum, n);

    insertionSort(arrNum, n);
    recursiveInsertionSort(arrNum, 0, n);

    mergeSort(arrNum, 0, n-1);

    quickSort(arrNum, 0, n-1);

    for (auto it : arrNum)
    {
        cout << it << " ";
    }

    return 0;
}

// -----------------------------------------------------


