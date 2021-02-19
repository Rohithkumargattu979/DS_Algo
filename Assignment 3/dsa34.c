#include <stdio.h>
#include <stdbool.h>
void sort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
bool isFeasible(int mid, int arr[], int m, int n)
{
	int pos = arr[0];
	int elements = 1;
	for (int i = 1; i < m; i++) {
		if (arr[i] - pos >= mid) {
			pos = arr[i];
			elements++;
			if (elements == n)
				return true;
		}
	}
	return 0;
}
int largestMinDist(int arr[], int m, int n)
{
	sort(arr,  m);
	int res = -1;
	int left = 1, right = arr[m - 1];
	while (left < right) {
		int mid = (left + right) / 2;
		if (isFeasible(mid, arr, m, n)) {
			res = max(res, mid);
			left = mid + 1;
		}
		else
			right = mid;
	}

	return res;
}

int main()
{
	int n,m;
    scanf("%d %d",&n,&m);
    int arr[m];
    for(int i=0;i<m;i++){
        scanf("%d", &arr[i]);
    }
	printf("%d", largestMinDist(arr, m, n));
	return 0;
}
