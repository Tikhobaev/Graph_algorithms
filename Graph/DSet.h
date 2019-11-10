//
// Created by Илья on 009 09.11.19.
//

#ifndef DATA_STRUCTURES_DSET_H
#define DATA_STRUCTURES_DSET_H


class DSet
{
public:
    const int maxN;
    int* r;
    int* arr;
    DSet(int);
    ~DSet();
    void MakeSet(int);
    void Union(int, int);
    int Find(int);
    void print();
};


#endif //DATA_STRUCTURES_DSET_H
