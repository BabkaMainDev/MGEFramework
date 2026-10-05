#ifndef BIGVALUES_H
#define BIGVALUES_H

#include <iostream>
#include <iomanip>

typedef unsigned __int64 uint64_t;
typedef __int64 int64_t;

struct __int256
{
    uint64_t data[4];

    __int256()
    {
        data[0] = 0;
        data[1] = 0;
        data[2] = 0;
        data[3] = 0;
    }

    __int256(int64_t v)
    {
        data[0] = (uint64_t)v;

        uint64_t fill;

        if (v < 0)
            fill = ~(uint64_t)0;
        else
            fill = 0;

        data[1] = fill;
        data[2] = fill;
        data[3] = fill;
    }

    __int256& operator=(int64_t v)
    {
        *this = __int256(v);
        return *this;
    }

    __int256 operator+(const __int256& other) const
    {
        __int256 result;
        uint64_t carry = 0;

        for (int i = 0; i < 4; ++i)
        {
            uint64_t sum = data[i] + other.data[i] + carry;

            if (sum < data[i] || (carry && sum <= data[i]))
                carry = 1;
            else
                carry = 0;

            result.data[i] = sum;
        }

        return result;
    }

    bool is_zero() const
    {
        return !(data[0] |
                 data[1] |
                 data[2] |
                 data[3]);
    }
};

inline std::ostream& operator<<(std::ostream& os, const __int256& val)
{
    std::ios_base::fmtflags f = os.flags();

    os << "0x";

    unsigned long high;
    unsigned long low;

    high = (unsigned long)(val.data[3] >> 32);
    low  = (unsigned long)(val.data[3] & 0xFFFFFFFF);

    os << std::hex << std::setw(8) << std::setfill('0') << high;
    os << std::hex << std::setw(8) << std::setfill('0') << low;

    high = (unsigned long)(val.data[2] >> 32);
    low  = (unsigned long)(val.data[2] & 0xFFFFFFFF);

    os << std::hex << std::setw(8) << std::setfill('0') << high;
    os << std::hex << std::setw(8) << std::setfill('0') << low;

    high = (unsigned long)(val.data[1] >> 32);
    low  = (unsigned long)(val.data[1] & 0xFFFFFFFF);

    os << std::hex << std::setw(8) << std::setfill('0') << high;
    os << std::hex << std::setw(8) << std::setfill('0') << low;

    high = (unsigned long)(val.data[0] >> 32);
    low  = (unsigned long)(val.data[0] & 0xFFFFFFFF);

    os << std::hex << std::setw(8) << std::setfill('0') << high;
    os << std::hex << std::setw(8) << std::setfill('0') << low;

    os.flags(f);

    return os;
}

#endif