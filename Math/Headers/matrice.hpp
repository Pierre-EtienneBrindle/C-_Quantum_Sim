#ifndef MATRICE_H
#define MATRICE_H

namespace math
{
    template <unsigned int height, unsigned int width, typename T>
    class matrice
    {
        private: 
        T** m_matrice
        
        public:
        matrice();
        matrice(const matrice &);
        
        matrice& apply_kronecher_product(const matrice&);
        const matrice& get_kronecher_product(const matrice&)&;
        matrice &operator=(const matrice&);
        matrice &operator+=(const matrice&);
        const matrice &operator+(const matrice&)const;
        matrice &operator-=(const matrice&);
        const matrice &operator-(const matrice&)const;
        matrice &operator*=(const matrice&);
        const matrice &operator*(const matrice&)const;
        matrice &operator*=(const T&);
        const matrice &operator*(const T&)const;
        friend const bool operator==(const matrice&, const matrice&);

    };
}
#endif