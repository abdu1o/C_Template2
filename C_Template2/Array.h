
template<typename T>
class Array
{
private:
    size_t size;
    T* arr;

public:
    Array() : size(0), arr(nullptr)
    {

    }

    Array(T length) : size(length)
    {
        assert(length >= 0);

        if (length > 0)
        {
            arr = new T[length];
        }
        else
        {
            arr = nullptr;
        }

    }

    ~Array()
    {
        if (arr != nullptr)
        {
            delete[] arr;
        }
    }

    void RemoveAll()
    {
        delete[] arr;
        arr = nullptr;
        size = 0;
    }

    bool IsEmpty() const
    {
        if (size > 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    int GetSize() const
    {
        return size;
    }

    void SetSize(int newSize)
    {
        if (newSize == size)
        {
            return;
        }

        if (newSize <= 0)
        {
            RemoveAll();
            return;
        }

        T* data = new T[newSize];

        if (size > 0)
        {
            T elementsToCopy = (newSize > size) ? size : newSize;

            if (newSize > size)
            {
                elementsToCopy = size;
            }
            else
            {
                elementsToCopy = newSize;
            }

            for (int i = 0; i < elementsToCopy; i++)
            {
                data[i] = arr[i];
            }

        }
        delete[] arr;

        arr = data;
        size = newSize;
    }

    int GetUpperBound()
    {
        return sizeof(arr) / sizeof(arr[0]) - 1;
    }

    void InsertAt(int value, int index)
    {
        assert(index >= 0 && index <= size);

        int* data = new int[size + 1];

        for (int before = 0; before < index; before++)
        {
            data[before] = arr[before];
        }

        data[index] = value;

        for (int after = index; after < size; after++)
        {
            data[after + 1] = arr[after];
        }

        delete[] arr;
        arr = data;
        size++;
    }

    void RemoveAt(int index)
    {
        assert(index >= 0 && index < size);

        if (size == 1)
        {
            RemoveAll();
            return;
        }

        int* data = new int[size - 1];

        for (int before = 0; before < index; before++)
        {
            data[before] = arr[before];
        }

        for (int after = index + 1; after < size; after++)
        {
            data[after - 1] = arr[after];
        }

        delete[] arr;
        arr = data;
        size--;
    }

    void Add(int value)
    {
        InsertAt(value, size);
    }

    auto GetData()
    {
        cout << "\n\nAddresses of elements: \n";
        for (int i = 0; i < size; i++)
        {
            cout << &arr[i] << "\n";
        }
        cout << "\n";
        return arr;
    }

    int& operator+(T arr2[])
    {
        int sizeof_1 = sizeof(arr) / sizeof(arr[0]);
        int sizeof_2 = sizeof(arr2) / sizeof(arr2[0]);

        T result_arr[sizeof_1 + sizeof_2];
        std::copy(arr2, arr2 + sizeof_2, std::copy(arr, arr + sizeof_1, result_arr));

        for (int i : result_arr)
        {
            cout << i << " ";
        }
    }

    int& operator=(T arr2[])
    {
        memcpy(arr2, arr, sizeof arr);
    }

    int& operator[](int index)
    {
        assert(index >= 0 && index < size);

        return arr[index];
    }
};
