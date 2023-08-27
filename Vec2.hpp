#ifndef VEC2_HPP
#define VEC2_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Vec2
{
private:
    T x;
    T y;

public:
    // Constructors
    Vec2() : x(T()), y(T()) {}
    Vec2(T x, T y) : x(x), y(y) {}
    Vec2(const Vec2<T>& other) : x(other.x), y(other.y) {}
    ~Vec2() = default;

    // Overload operators
    Vec2<T>& operator=(const Vec2<T>& other) { x = other.x; y = other.y; return *this; }
    Vec2<T> operator+(const Vec2<T>& other) const { return Vec2<T>(x + other.x, y + other.y); }
    Vec2<T> operator-(const Vec2<T>& other) const { return Vec2<T>(x - other.x, y - other.y); }
    Vec2<T> operator*(const Vec2<T>& other) const { return Vec2<T>(x * other.x, y * other.y); }
    Vec2<T> operator/(const Vec2<T>& other) const { 
        if (other.x == T() || other.y == T())
            throw std::runtime_error("Error : Divide by zero");
        return Vec2<T>(x / other.x, y / other.y); 
    }
    
    Vec2<T> operator*(T scalar) const { return Vec2<T>(x * scalar, y * scalar); }
    Vec2<T> operator/(T scalar) const
    { 
        if (scalar == T())
            throw std::runtime_error("Error : Divide by zero");
        return Vec2<T>(x / scalar, y / scalar); 
    }

    Vec2<T>& operator+=(const Vec2<T>& other) { x += other.x; y += other.y; return *this; }
    Vec2<T>& operator-=(const Vec2<T>& other) { x -= other.x; y -= other.y; return *this; }
    Vec2<T>& operator*=(const Vec2<T>& other) { x *= other.x; y *= other.y; return *this; }
    Vec2<T>& operator/=(const Vec2<T>& other)
    {
        if (other.x == T() || other.y == T())
            throw std::runtime_error("Error : Divide by zero");
        x /= other.x; y /= other.y; 
        return *this; 
    }
    Vec2<T>& operator*=(T scalar) { x *= scalar; y *= scalar; return *this; }
    Vec2<T>& operator/=(T scalar)
    {
        if (scalar == T())
            throw std::runtime_error("Error : Divide by zero");
        x /= scalar; y /= scalar; 
        return *this; 
    }
    Vec2<T> operator-() const { return Vec2<T>(-x, -y); }

    bool operator!=(const Vec2<T>& other) const { return !(*this == other); }
    bool operator==(const Vec2<T>& other) const { return x == other.x && y == other.y; }
    
    // getters
    T getX() const { return x; }
    T getY() const { return y; }

    // setters
    void setX(T x) { this->x = x; }
    void setY(T y) { this->y = y; }

    // Methods
    // Vec2&   Normalize() const;
    // Vec2    Rotate(const T angle) const;
    // Vec2    UnitVector() const;
    // Vec2    Normal() const;
    // T       Dot(const Vec2<T>& other) const;
    // T       Magnitude() const;
    // T       MagnitudeSquared() const;
    // T       Cross(const Vec2<T>& other) const;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec)
{
    os << "Vec2(" << vec.getX() << ", " << vec.getY() << ")";
    return os;
}



#endif
