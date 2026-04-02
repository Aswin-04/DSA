class Solution {
    private void reverse(int arr[], int i, int n) {
        if(i >= n/2) return;
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
        reverse(arr, i+1, n);
    }
    public void reverseArray(int arr[]) {
        // code here
        reverse(arr, 0, arr.length);
    }
}