#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[20], n, h, size, seek = 0, i, j, t;

    printf("Enter no of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for(i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("Enter head position: ");
    scanf("%d", &h);

    printf("Enter disk size: ");
    scanf("%d", &size);

    // Sort requests
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(a[i] > a[j])
                t = a[i], a[i] = a[j], a[j] = t;

    printf("C-SCAN Order: ");

    // Move right
    for(i = 0; i < n; i++)
        if(a[i] >= h)
            printf("%d ", a[i]),
            seek += abs(a[i] - h),
            h = a[i];

    // Jump to beginning
    seek += (size - 1 - h) + (size - 1);
    h = 0;

    // Move from start
    for(i = 0; i < n; i++)
        if(a[i] < h)
            printf("%d ", a[i]),
            seek += abs(a[i] - h),
            h = a[i];

    printf("\nTotal Seek Time = %d", seek);

    return 0;
}
