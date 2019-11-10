#include <stdio.h>
#include <stdlib.h>

void hanoi(int nDisk, int left, int right, int middle)
{
    if(nDisk > 0)
    {
        hanoi(nDisk-1, left, middle, right);
        printf("Move %d to %d\n", left, right);
        hanoi(nDisk-1, middle, right, left);
    }
}

void main()
{
    int disks;
    scanf("%d", &disks);
    hanoi(disks,1,3,2);
}
