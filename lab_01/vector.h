#ifndef VECTOR_H
#define VECTOR_H

template <class T>
struct Vector
{
    T* data = nullptr;
    int count = 0;
    int allocate = 0;
};

template <class T>
void createVector(Vector<T>& vec)
{
    createVector<T>(vec, 10);
}

template <class T>
void createVector(Vector<T>& vec, int count)
{
    vec.count = 0;
    vec.allocate = count;
    vec.data = new T[count];
}

template <class T>
void destructVector(Vector<T>& vec)
{
    if (vec.data == nullptr) {
        return;
    }

    delete[] vec.data;
    vec.data = nullptr;
    vec.allocate = 0;
    vec.count = 0;
}

template <class T>
T& get(const Vector<T> vec, int index)
{
    return vec.data[index];
}

template <class T>
void append(Vector<T>& vec, T el)
{
    if (vec.count == vec.allocate) {
        T* copy = new T[vec.count * 2];

        for (int i = 0; i < vec.count; i++)
            copy[i] = vec.data[i];

        delete[] vec.data;
        vec.data = copy;
        vec.allocate *= 2;
    }

    vec.data[vec.count++] = el;
}

template <class T>
int size(const Vector<T> vec)
{
    return vec.count;
}

template <class T>
void copy(Vector<T>& vec, const Vector<T> copied)
{
    vec.count = copied.count;
    vec.allocate = copied.allocate;
    vec.data = new T[vec.allocate];
    for (int i = 0; i < copied.count; ++i) {
        vec.data[i] = copied.data[i];
    }
}

#endif // VECTOR_H
