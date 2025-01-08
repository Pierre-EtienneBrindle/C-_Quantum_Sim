#ifndef COMPLEXE_NB_HPP
#define COMPLEXE_NB_HPP
#include <cstdint>
#include "../../Core/Headers/writable.hpp"
#include <string>

namespace math
{
    struct complexe_number : public core::writable
    {
    private:
#pragma region Attributes

        double m_real_part;
        double m_imaginary_part;

#pragma endregion

    public:
#pragma region Constructor and destructor

        // Creates the number 0 + 0 i
        complexe_number();
        complexe_number(double, double);
        complexe_number(const complexe_number &);

#pragma endregion

#pragma region Getters and setters

        // Changes both the real and imaginary part of the complexe number
        void set_all(double, double);

        void set_real_part(double);
        double get_real_part() const;

        void set_imaginary_part(double);
        double get_imaginary_part() const;

        double get_magnitude() const;
        double get_angle() const;

        // Returns the complexe conjugate of the number (a - b i)
        const complexe_number get_conjugate() const;

#pragma endregion

#pragma region Operations

        // Returns e to the complexe number
        static const complexe_number exp(const complexe_number &); // e^z

        // Returns only one of the logs of the complexe number
        static const complexe_number log(const complexe_number &);

        const complexe_number to_the_power(const double &) const;

        const complexe_number to_the_power(const complexe_number &) const; //z^w

#pragma endregion

#pragma region operators

        complexe_number &operator=(const complexe_number &);
        complexe_number &operator+=(const complexe_number &);
        const complexe_number operator+(const complexe_number &) const;
        complexe_number &operator+=(const double &);
        const complexe_number operator+(const double &) const;
        complexe_number &operator-=(const complexe_number &);
        const complexe_number operator-(const complexe_number &) const;
        complexe_number &operator-=(const double &);
        const complexe_number operator-(const double &) const;
        complexe_number &operator*=(const complexe_number &);
        const complexe_number operator*(const complexe_number &) const;
        complexe_number &operator*=(const double &);
        const complexe_number operator*(const double &) const;
        complexe_number &operator/=(const complexe_number &);
        const complexe_number operator/(const complexe_number &) const;
        complexe_number &operator/=(const double &);
        const complexe_number operator/(const double &) const;
        friend const bool operator==(const complexe_number &, const complexe_number &);
        friend const bool operator==(const complexe_number &, const double &);
        friend const bool operator==(const double &, const complexe_number &);

#pragma endregion

#pragma region Writable

        virtual std::string to_string() const;

#pragma endregion
    };
}

#endif