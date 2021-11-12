#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "Sequence.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "ListSequence.h"
#include "ArraySequence.h"
#include "Polynom.h"
#include "LiniarForm.h"

using namespace std;


int main()
{

    int* dat = new int[10];
    for (int i = 0; i < 10; i++)
        dat[i] = i;
    DynamicArray<int>* D1 = new DynamicArray<int>(10,dat);
    D1->InsertAt(5, 3);
    for (int i = 0; i < D1->GetLen(); i++)
        cout << D1->Get(i);
    cout << "\n";
    ArraySequence<int>* D2 = new ArraySequence<int>;
    for (int i = 0; i < 15; i++) {
        D2->Append(i);

    }
    for (int i = 0; i < D2->GetLength(); i++)
        cout << D2->Get(i) << " ";
    ArraySequence<int>* D3 = new ArraySequence<int>;
    for (int i = 0; i < 15; i++) {
        D3->Prepend(i);
    }
    ArraySequence<int>* D4 = new ArraySequence<int>(*D2->Concat(D3));
    ArraySequence<int>* D5 = new ArraySequence<int>(*D2->GetSubsequence(4,10));
    for (int i = 0; i < D5->GetLength(); i++)
        cout << D5->Get(i) << " ";
    for (int i = 0; i < 200; i++) {
        D5->Append(i);
    }
    cout << "sadasd";
    for (int i = 0; i < 200; i++) {
        D5->Prepend(i);
        cout << i << " ";
    }
    return 0;
}
