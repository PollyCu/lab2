#include "ArraySequence.h"

template <class T> class LiniarForm {
private:
    ArraySequence<T>* data;
public:
    LiniarForm() {
        data = new ArraySequence<T>;
    }
    LiniarForm(T* ndata, int l) {
        data = new ArraySequence<T>[l];
        for (int i = 0; i < l; i++)
            data->Append(ndata[i]);
    }
    LiniarForm(LiniarForm<T>& Lin) {
        int l = Lin.GetSize();
        data = new ArraySequence<T>;
        for (int i = 0; i < l; i++)
            data->Append(Lin.Get(i));
    }
    int GetSize() {
        return data->GetLength();
    }
    T Get(int i) {
        return data->Get(i);
    }
    void Sum(LiniarForm<T> b) {
        if (this->GetSize() > b.GetSize()) {
            for (int i = 0; i < b.GetSize(); i++) {
                this->data->Set(i, b.Get(i) + this->data->Get(i));
            }
        }
        else {

            for (int i = 0; i < this->GetSize(); i++) {
                this->data->Set(i, b.Get(i) + this->data->Get(i));
            }
            int l = this->GetSize();
            this->data->Resize(b.GetSize());
            for (int i = l; i < this->GetSize(); i++) {
                this->data->Set(i, b.Get(i));
            }
        }
    }
    void Min(LiniarForm<T> b) {
        if (this->GetSize() > b.GetSize()) {
            for (int i = 0; i < b.GetSize(); i++) {
                this->data->Set(i,  this->data->Get(i)-b.Get(i));
            }
        }
        else {

            for (int i = 0; i < this->GetSize(); i++) {
                this->data->Set(i, this->data->Get(i)- b.Get(i));
            }
            int l = this->GetSize();
            this->data->Resize(b.GetSize());
            for (int i = l; i < this->GetSize(); i++) {
                this->data->Set(i, b.Get(i) * (-1));
            }
        }

    }
    void Mult(T x) {
        for (int i = 0; i < this->GetSize(); i++)
            this->data->Set(i, this->data->Get(i) * x);
    }
    T value(ArraySequence<T>* x) {
        assert(x->GetLength() == this->GetSize());
        T sum = 0;
        for (int i = 0; i < this->GetSize(); i++)
            sum = sum + this->Get(i) * x->Get(i);
        return sum;
    }
    void Printinfo() {
        cout << "\nLength:\n" << this->GetSize() << "\nData:\n";
        for (int i = this->GetSize()-1; i >=0 ; i--)
            cout << "+(" << data->Get(i) << ")*x" << i;
        cout << "\n";
    };
};