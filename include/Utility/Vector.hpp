#ifndef VECTOR_HPP
#define VECTOR_HPP


//STD
#include <iostream>
#include <cmath>

//3RD

//SELF
#include "Constants.hpp"

namespace zge
{
    double radToDeg(double rad);
    double degToRad(double deg);

    struct Vector
    {
        Vector(double x = 0, double y = 0);
        Vector& operator=(const Vector& vec);
        Vector operator+(const Vector& vec);
        Vector& operator+=(const Vector& vec);
        Vector operator-(const Vector& vec);
        Vector& operator-=(const Vector& vec);
        Vector operator*(const Vector& vec);
        Vector& operator*=(const Vector& vec);
        Vector operator/(const Vector& vec);
        Vector& operator/=(const Vector& vec);

        Vector operator+(const double scalar);
        Vector& operator+=(const double scalar);
        Vector operator-(const double scalar);
        Vector& operator-=(const double scalar);
        Vector operator*(const double scalar);
        Vector& operator*=(const double scalar);
        Vector operator/(const double scalar);
        Vector& operator/=(const double scalar);

        double x;
        double y;

        double dot(Vector& vec);
        double length();
        double squaredLength();
        void normalize();
        Vector normalized();

        void turnLeft();
        Vector turnedLeft();

        void turnRight();
        Vector turnedRight();

        void rotateWithDeg(const double deg);
        Vector rotatedWithDeg(const double deg);

        void rotateWithRad(const double rad);
        Vector rotatedWithRad(const double rad);

        double degrees();
        double radians();
    };
}


#endif
