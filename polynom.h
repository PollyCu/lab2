#include"ArraySequence.h"
using namespace std;

template <class T> class Polynom {
private:
    ArraySequence<T>* Poly;
public:
    Polynom() {
        Poly = new ArraySequence<T>;
    }
    Polynom(Polynom<T>& pol) {
        Poly = new ArraySequence<T>;
        for (int i = 0; i < pol.Poly->GetLength(); i++) {
            Poly->Append(pol.Poly->Get(i));
        }
    }
    Polynom(T* data, int l) {
        Poly = new ArraySequence<T>;
        for (int i = 0; i < l; i++)
        {
            Poly->Append(data[i]);
        }
    }
    Polynom(ArraySequence<T> from) {
        int x = from.GetLength();
        Poly = new ArraySequence<T>;
        for (int i = 0; i < x; i++) {
            Poly->Append(from.Get(i));
        }
    }
    Polynom(int size) {
        Poly = new ArraySequence<T>(size);
    }
    void totheend(T x) {
        Poly->Append(x);
    }
    void tothebeg(T x) {
        Poly->Prepend(x);
    }
    void insert(T x, int ind) {
        assert(ind >= 0);
        assert(ind <= this->GetSize());
        Poly->InsertAt(x, ind);
    }
    int  GetSize() {
        return Poly->GetLength();
    }
    T Get(int i) {
        assert(i <= this->GetSize());
        return Poly->Get(i);
    }
    Polynom<T>* Superposition(Polynom<T>* b) {

        this->Printifo();
        b->Printifo();
        int l = this->GetSize() + b->GetSize() - 2;
        T* res = new T[l];
        for (int i = 0; i < l; i++)
            res[i] = 0;
        Polynom<T>* resa = new Polynom<T>(res, l);
        T Lastsum = this->Get(0);

        for (int j = 0; j < this->GetSize() - 1; j++) {

            Polynom<T>* temp = new Polynom<T>(*b);

            for (int i = 0; i < this->GetSize() - 2 - j; i++)
                temp->Mult(*b);

            temp->Byvalue(this->Get(this->GetSize()-j-1));


            resa->Sum(*temp);

            Lastsum = Lastsum + temp->Get(0);
        }
        resa->Set(0, Lastsum);
        return resa;
    }
    void Set(int index, T value) {
        assert(index >= 0);
        assert(index <= this->GetSize());
        Poly->Set(index, value);
    }
    void Sum(Polynom<T> b) {
        cout<<"\n"<<this->GetSize()<<" "<<b.GetSize();
        if (this->GetSize() > b.GetSize()) {
            for (int i = 0; i < b.GetSize(); i++) {
                this->Poly->Set(i, b.Get(i) + this->Poly->Get(i));
            }
        }
        else {

            for (int i = 0; i < this->GetSize(); i++) {
                this->Poly->Set(i, b.Get(i) + this->Poly->Get(i));
            }
            int l = this->GetSize();
            this->Poly->Resize(b.GetSize());
            for (int i = l; i < this->GetSize(); i++) {
                this->Poly->Set(i, b.Get(i));
            }
        }

    }
    void Mult(Polynom<T> b) {
        T* d1 = new T[this->GetSize()];
        T* d2 = new T[b.GetSize()];
        int l = this->GetSize() + b.GetSize() - 1;
        T* res = new T[l];

        for (int i = 0; i < this->GetSize(); i++) d1[i] = this->Get(i);
        for (int i = 0; i < b.GetSize(); i++) d2[i] = b.Get(i);
        for (int i = 0; i < l; i++) res[i] = 0;
        for (int i = 0; i < this->GetSize(); i++)
            for (int j = 0; j < b.GetSize(); j++) {
                T x = res[i + j];
                x = x + this->Get(i) * b.Get(j);
                res[i + j] = x;
            }
        this->Poly->Resize(l);
        for (int i = 0; i < l; i++)this->Poly->Set(i, res[i]);
    }
    void Byvalue(T x) {

        for (int i = 0; i < this->GetSize(); i++) {
            this->Poly->Set(i, this->Get(i) * x);
        }
    }
    T Value(T x) {
        T res = Poly->Get(0);

        for (int i = 1; i < Poly->GetLength(); i++) {
            T temp = 1;
            for (int j = 0; j < i; j++)
                temp = temp * x;
            temp = temp * Poly->Get(i);
            res = res + temp;
        }
        return res;
    }
    void Printifo() {
        cout << "\nLength:\n" << this->GetSize() << "\nData:\n";
        for (int i = this->GetSize() - 1; i >= 0; i--) {
            cout << " + (" << this->Get(i) << ")*x^" << i;
        }
    }

};