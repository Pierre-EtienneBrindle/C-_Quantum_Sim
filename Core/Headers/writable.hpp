#ifndef WRITABLE_HPP
#define WRITABLE_HPP

#include <string>

namespace core
{
    // Interface to use on all objects that can be transformed into a string
    class writable
    {
    public:
        virtual ~writable() {}
        virtual std::string to_string() const = 0;
    };
}

#endif