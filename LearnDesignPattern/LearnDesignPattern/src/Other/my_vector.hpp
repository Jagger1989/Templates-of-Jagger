#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#if 0

using namespace std;
namespace my_vector {

template<typename T, int length = 2>
class Vector : public array<T, length>{
public:
    Vector() {}
    Vector(const T& v)
    {
        for (size_t i = 0; i < length; i++)
        {
            this[i] = v;
        }
    }

    Vector(const initializer_list<T>& list)
    {
        for (size_t i = 0; i < length; i++)
        {
            this[i] = list[i];
        }
    }

    Vector(const Vector<T, length>& obj)
    {
        for (size_t i = 0; i < length; i++)
        {
            (*this)[i] = obj[i];
        }
    }

    Vector& operator=(const Vector<T, length>& obj)
    {
        for (size_t i = 0; i < length; i++)
        {
            (*this)[i] = obj[i];
        }
    }

    // get
    T getX() const { return (*this)[0]; }
    T getY() const { return (*this)[1]; }
    T getX() const { return (*this)[2]; }
    // set
    T setX(const T& v) const { return (*this)[0] = v; }
    T setY(const T& v) const { return (*this)[1] = v; }
    T setX(const T& v) const { return (*this)[2] = v; }
};

template<typename T>
class Vector2 : public Vector<T, 2>
{

};





}

#endif

#endif //! MY_VECTOR_HPP