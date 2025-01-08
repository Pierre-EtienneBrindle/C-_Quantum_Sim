#ifndef MATRICE_H
#define MATRICE_H

#include "../../Core/logger.cpp"
#include "../../Core/Headers/writable.hpp"
#include <stdexcept>
namespace math
{
    template <unsigned int height, unsigned int width, typename T>
    class matrice
    {
    private:
        T **m_matrice;
        void clear_matrice();

    public:
        matrice();
        matrice(const matrice &);
        ~matrice();

        matrice &operator=(const matrice &);
        matrice &operator+=(const matrice &);
        const matrice &operator+(const matrice &) const;
        matrice &operator-=(const matrice &);
        const matrice &operator-(const matrice &) const;
        matrice &operator*=(const T &);
        const matrice &operator*(const T &) const;
        const matrice &operator*(const matrice &) const;
        friend const matrice &kronecher_product(const matrice &, const matrice &);
        friend const bool operator==(const matrice &, const matrice &);
    };

    template <unsigned int height, unsigned int width, typename T>
    void matrice<height, width, T>::clear_matrice()
    {
        if (!m_matrice)
            return;

        for (int i = 0; i < height; ++i)
        {
            delete[] m_matrice[i];
        }
        delete[] m_matrice;
    }

    template <unsigned int height, unsigned int width, typename T>
    matrice<height, width, T>::matrice()
    {
        m_matrice = new T *[height];

        for (int i = 0; i < height; ++i)
        {
            m_matrice[i] = new T[width];
            for (int j = 0; j < width; ++j)
                m_matrice[i][j] = T();
        }
    }

    template <unsigned int height, unsigned int width, typename T>
    matrice<height, width, T>::matrice(const matrice<height, width, T> &other)
    {
        return *(this) = other;
    }

    template <unsigned int height, unsigned int width, typename T>
    matrice<height, width, T>::~matrice()
    {
        clear_matrice();
    }

    template <unsigned int height, unsigned int width, typename T>
    matrice<height, width, T> &matrice<height, width, T>::operator=(const matrice<height, width, T> &other)
    {
        clear_matrice();

        if (!other.m_matrice)
            return this;

        m_matrice = new T *[height];
        for (int i = 0; i < height; ++i)
        {
            m_matrice[i] = new T[width];
            for (int j = 0; j < width; ++j)
                m_matrice[i][j] = other.m_matrice[i][j];
        }

        return this;
    }

    template <unsigned int height, unsigned int width, typename T>
    matrice<height, width, T> &matrice<height, width, T>::operator+=(const matrice<height, width, T> &other)
    {
        if (!m_matrice || !other.m_matrice)
        {
            core::logger::log("One or more matrix is null");
            throw invalide_argument("One or more matrix is null");
        }

        for (int i = 0; i < height; ++i)
        {
            if (!m_matrice[i] || !other.m_matrice[i])
            {
                core::logger::log("One or more matrix is incomplete");
                throw invalide_argument("One or more matrix is incomplete");
            }

            for (int j = 0; j < width; ++j)
                m_matrice[i][j] += other.m_matrice[i][j];
        }
    }

    template <unsigned int height, unsigned int width, typename T>
    const matrice<height, width, T> &matrice<height, width, T>::operator+(const matrice<height, width, T> &other) const
    {
        return matrice(*this) += other;
    }

    template <unsigned int height, unsigned int width, typename T>
    matrice<height, width, T> &matrice<height, width, T>::operator-=(const matrice<height, width, T> &other)
    {
        if (!m_matrice || !other.m_matrice)
        {
            core::logger::log("One or more matrix is null");
            throw invalide_argument("One or more matrix is null");
        }

        for (int i = 0; i < height; ++i)
        {
            if (!m_matrice[i] || !other.m_matrice[i])
            {
                core::logger::log("One or more matrix is incomplete");
                throw invalide_argument("One or more matrix is incomplete");
            }

            for (int j = 0; j < width; ++j)
                m_matrice[i][j] -= other.m_matrice[i][j];
        }
    }

    template <unsigned int height, unsigned int width, typename T>
    const matrice<height, width, T> &matrice<height, width, T>::operator-(const matrice<height, width, T> &other) const
    {
        return matrice(*this) -= other;
    }

}
#endif