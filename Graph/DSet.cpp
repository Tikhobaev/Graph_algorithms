//
// Created by Илья on 009 09.11.19.
//

#include "DSet.h"

DSet::DSet(int n) : maxN(n)
{
    arr = new int[maxN+1];
    r = new int[maxN+1];
    for (int i = 1; i <= maxN; i++)
    {
        arr[i] = 0;
        r[i] = 0;
    }
}

DSet::~DSet()
{
    delete[] arr;
    delete[] r;
}

void DSet::MakeSet(int x)
{
    arr[x] = x;
}

void DSet::Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return;
    if (r[x] < r[y])
        arr[x] = y;
    else
    if(r[x] > r[y])
        arr[y] = x;
    else {
        arr[x] = y;
        r[y]++;
    }
}

int DSet::Find(int x)
{
    int z = x;  // Copy
    while(arr[x] != x)
    {
        x = arr[x];
    }
    int y = x;
    while(arr[z] != z)
    {
        int z1 = z;
        z = arr[z];
        arr[z1] = y;
    }
    return x;
}