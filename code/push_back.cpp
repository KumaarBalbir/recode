#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
private:
  T *data;
  size_t size;
  size_t capacity;

public:
  /**
   * The MyVector constructor initializes the size and capacity variables to 0 and 2 respectively, and
   * allocates memory for the data array.
   */
  MyVector() : size(0), capacity(2)
  {
    data = new T[capacity];
  }
  /**
   * The MyVector constructor initializes the size and capacity variables to the given capacity value.
   *
   * @param capacity The capacity parameter represents the maximum number of elements that the vector can
   * hold without needing to allocate more memory.
   */
  MyVector(size_t capacity) : size(0), capacity(capacity) // direct initialization (more efficient for non-primitive types,avoids an extra initialization step)
  {
    // this->capacity=capacity; //assignment intialization (not efficient, as member variables are first default initialized and then assigned a new value,especially for non-primitive types)
    data = new T[capacity];
  }
  ~MyVector()
  {
    delete[] data;
  }
  /**
   * The push_back function adds a new element to the end of an array, doubling the capacity if
   * necessary.
   *
   * @param value The parameter "value" is of type T, which represents the type of elements stored in
   * the array. It is passed by reference, meaning that the function will work with the actual value
   * passed to it, rather than a copy of the value.
   */
  void push_back(const T &value)
  {
    if (size == capacity) // double the capacity if array is full
    {
      capacity <<= 1;
      T *newdata = new T[capacity];
      for (size_t i = 0; i < size; i++)
      {
        newdata[i] = data[i];
      }
      delete[] data;
      data = newdata;
    }

    data[size++] = value;
  }
  /**
   * Get the size of the object.
   *
   * @return the size of the object
   */
  size_t getSize() const
  {
    return size;
  }

  /**
   * The function overloads the subscript operator to access elements of an array-like data structure,
   * throwing an exception if the index is out of range.
   *
   * @return a reference to the element at the specified index in the data array.
   */
  T &operator[](size_t index)
  {
    if (index < size)
    {
      return data[index];
    }
    else
    {
      throw std::out_of_range("Index out of range");
    }
  }
};
int main()
{

  MyVector<int> v;
  v.push_back(10);
  cout << v[0] << endl;
}