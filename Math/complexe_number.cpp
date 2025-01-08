#ifndef COMPLEXE_NB_CPP
#define COMPLEXE_NB_CPP
#include "Headers/complexe_number.hpp"
#include "../Core/logger.cpp"
#include <string>
#include <math.h>
#pragma once

namespace math
{
#pragma region Constructors and Destructors

    complexe_number::complexe_number() : m_real_part(0), m_imaginary_part(0) {}

    complexe_number::complexe_number(double real, double imaginary)
    {
        set_all(real, imaginary);
    }

    complexe_number::complexe_number(const complexe_number &other)
    {
        (*this) = other;
    }

#pragma endregion

#pragma region Getters and setters

    void complexe_number::set_all(double real, double imaginary)
    {
        m_real_part = real;
        m_imaginary_part = imaginary;
    }

    inline void complexe_number::set_real_part(double real)
    {
        m_real_part = real;
    }

    inline double complexe_number::get_real_part() const
    {
        return m_real_part;
    }

    inline void complexe_number::set_imaginary_part(double imaginary)
    {
        m_imaginary_part = imaginary;
    }

    inline double complexe_number::get_imaginary_part() const
    {
        return m_imaginary_part;
    }

    inline double complexe_number::get_magnitude() const
    {
        return std::sqrt(m_real_part * m_real_part + m_imaginary_part * m_imaginary_part);
    }

    inline double complexe_number::get_angle() const
    {
        double angle = std::acos(m_real_part / get_magnitude());
        return m_imaginary_part < 0 ? -angle : angle;
    }

    inline const complexe_number complexe_number::get_conjugate() const
    {
        return complexe_number(m_real_part, -m_imaginary_part);
    }

#pragma endregion

#pragma region Operations

    const complexe_number complexe_number::exp(const complexe_number &exponent)
    {
        double magnitude = std::exp(exponent.get_real_part());

        return complexe_number(magnitude * std::cos(exponent.get_imaginary_part()), magnitude * std::sin(exponent.get_imaginary_part()));
    }

    const complexe_number complexe_number::log(const complexe_number &exponent)
    {
        return complexe_number(std::log(exponent.get_magnitude()), exponent.get_angle());
    }

    const complexe_number complexe_number::to_the_power(const double &exponent) const
    {
        double magnitude = std::pow(get_magnitude(), exponent);
        double angle = get_angle() * exponent;
        return complexe_number(magnitude * std::cos(angle), magnitude * std::sin(angle));
    }

    const complexe_number complexe_number::to_the_power(const complexe_number &exponent) const
    {
        complexe_number temp(std::log(get_magnitude()), get_angle());
        temp *= exponent;

        double magnitude = std::exp(temp.get_real_part());
        return complexe_number(magnitude * std::cos(temp.get_imaginary_part()), magnitude * std::sin(temp.get_imaginary_part()));
    }

#pragma endregion

#pragma region Operators

    complexe_number &complexe_number::operator=(const complexe_number &other)
    {
        set_all(other.m_real_part, other.m_imaginary_part);
        return *this;
    }

    complexe_number &complexe_number::operator+=(const complexe_number &other)
    {
        m_real_part += other.m_real_part;
        m_imaginary_part += other.m_imaginary_part;
        return *this;
    }

    const complexe_number complexe_number::operator+(const complexe_number &other) const
    {
        return complexe_number(*this) += other;
    }

    complexe_number &complexe_number::operator+=(const double &other)
    {
        m_real_part += other;
        return *this;
    }

    const complexe_number complexe_number::operator+(const double &other) const
    {
        return complexe_number(*this) += other;
    }

    complexe_number &complexe_number::operator-=(const complexe_number &other)
    {
        m_real_part -= other.m_real_part;
        m_imaginary_part -= other.m_imaginary_part;
        return *this;
    }

    const complexe_number complexe_number::operator-(const complexe_number &other) const
    {
        return complexe_number(*this) -= other;
    }

    complexe_number &complexe_number::operator-=(const double &other)
    {
        m_real_part -= other;
        return *this;
    }

    const complexe_number complexe_number::operator-(const double &other) const
    {
        return complexe_number(*this) -= other;
    }

    complexe_number &complexe_number::operator*=(const complexe_number &other)
    {
        m_real_part = m_real_part * other.m_real_part - m_imaginary_part * other.m_imaginary_part;
        m_imaginary_part = m_real_part * other.m_imaginary_part + m_imaginary_part * other.m_real_part;
        return *this;
    }

    const complexe_number complexe_number::operator*(const complexe_number &other) const
    {
        return complexe_number(*this) *= other;
    }

    complexe_number &complexe_number::operator*=(const double &other)
    {
        m_real_part *= other;
        m_imaginary_part *= other;
        return *this;
    }

    const complexe_number complexe_number::operator*(const double &other) const
    {
        return complexe_number(*this) *= other;
    }

    complexe_number &complexe_number::operator/=(const complexe_number &other)
    {
        double new_real = m_real_part * other.m_real_part + m_imaginary_part * other.m_imaginary_part;
        double new_img = m_imaginary_part * other.m_real_part - m_real_part * other.m_imaginary_part;
        double other_mag = other.get_magnitude();
        m_real_part = new_real / other_mag;
        m_imaginary_part = new_img / other_mag;
        return *this;
    }

    const complexe_number complexe_number::operator/(const complexe_number &other) const
    {
        return complexe_number(*this) /= other;
    }

    complexe_number &complexe_number::operator/=(const double &other)
    {
        m_real_part /= other;
        m_imaginary_part /= other;
        return *this;
    }

    const complexe_number complexe_number::operator/(const double &other) const
    {
        return complexe_number(*this) /= other;
    }

    const bool operator==(const complexe_number &a, const complexe_number &b)
    {
        return a.get_real_part() == b.get_real_part() && a.get_imaginary_part() == b.get_imaginary_part(); //Could do abs(a.real - b.real) <= DELTA
    }

    const bool operator==(const complexe_number &a, const double &b)
    {
        return a.get_real_part() == b && a.get_imaginary_part() == 0;
    }

#pragma endregion

#pragma region Writable

    std::string complexe_number::to_string() const
    {
        return "( " + std::to_string(m_real_part) + " + " + std::to_string(m_imaginary_part) + " * i" + " )";
    }

#pragma endregion
}
#endif