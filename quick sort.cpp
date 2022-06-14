#include<stdio.h>
 /* Đo  phuc tap thuat toán quick sort
Truong hop tot: O(nlog(n))
Trung bình: O(nlog(n))
Truong hop xau: O(n^2)
Không gian bo nh0 su dung: O(log(n)) */
 
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++; // Tìm phan tu >= arr[pivot]
        while(right >= left && arr[right] > pivot) right--; // Tìm phan tu <= arr[pivot]
        if (left >= right) break; // đa duyet xong thì thoat vong lap
        swap(&arr[left], &arr[right]); // neu chua xong thi doi cho
        left++; // Vì left hien tai da xet nen can tang
        right--; // Vì right hien tai da xet nen can giam
    }
    swap(&arr[left], &arr[high]);
    return left; // tra ve chi so se dung de chia doi mang
}
 
/* ham thuc hien giai thuat quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chi so noi phan tu này đã đung đúng vi trí
         và là phan tu chia mang làm 2 mang con trái & phai */
        int pi = partition(arr, low, high);
 
        // Goi đe quy sap xep 2 mang con trái và phai
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Hàm xuat mang */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
 
int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
 