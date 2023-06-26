#include <iostream>
using namespace std;

void merge(int *arr, int p, int q, int r)
{
    int nL = q - p + 1;
    int nR = r - q;
    int L[nL], R[nR];
    for (int i = 0; i < nL; i++)
    {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < nR; j++)
    {
        R[j] = arr[q + j + 1];
    }
    int i = 0;
    int j = 0;
    int k = p;
    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < nL)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < nR)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int p, int r)
{
    if (p >= r)
    {
        return;
    }
    int q = p + (r - p) / 2;
    // left divide
    mergeSort(arr, p, q);
    // right divide
    mergeSort(arr, q + 1, r);
    // merging
    merge(arr, p, q, r);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}