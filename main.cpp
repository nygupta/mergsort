#include <iostream>
using namespace std;
int *MergeSort(int *a, int n);
int *Merge(int *a1, int *a2, int n1, int n2);
int main()
{
    int n;
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    array = MergeSort(array, n);
    for (int i = 0; i < n; i++)
        cout << "\t" << array[i];
    cout << endl;
}
int *MergeSort(int *arr, int n)
{
    if (n == 1)
        return arr;
    int mid = n / 2;
    int *a = new int[mid];
    int *b = new int[n - mid];
    for (int i = 0; i < mid; i++)
        a[i] = arr[i];
    for (int i = 0, j = mid; j < n;j++, i++)
        b[i] = arr[j];
    a = MergeSort(a, mid);
    b = MergeSort(b, n - mid);
    arr = Merge(a, b, mid, n - mid);
    return arr;
}
int *Merge(int *a1, int *a2, int n1, int n2)
{
    int *a3 = new int[n1 + n2];
    int k = 0, i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
        {
            a3[k] = a1[i];
            i++;
        }
        else
        {
            a3[k] = a2[j];
            j++;
        }
        k++;
    }
    for (int x = i; x < n1; x ++, k++)
        a3[k] = a1[x];
    for (int x = j; x < n2; x++, k++)
        a3[k] = a2[x];
    return a3;
}
