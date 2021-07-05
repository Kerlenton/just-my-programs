#include "big_numbers.h"
#include <cstdint>

BigNumber::BigNumber(int n)
{
    while (n > 0)
    {
        data_.push_back(n % BASE);
        n /= BASE; 
    }
}

BigNumber BigNumber::operator+(const BigNumber &y) const
{
    BigNumber result;
    int carrier = 0;
    
    for (auto i = 0; i < std::max(y.data_.size(), data_.size()); i++)
    {
        auto xx = i >= data_.size() ? 0 : data_[i];
        auto yy = i >= y.data_.size() ? 0 : y.data_[i];
        
        uint64_t r = 0ULL + xx + yy + carrier;
        result.data_.push_back(r % BASE);
        carrier = r / BASE;
    }
    
    if (carrier != 0)
        result.data_.push_back(carrier);
   
    return result;
}

BigNumber BigNumber::operator-(const BigNumber &y) const
{
    BigNumber result;
    int carrier = 0;
    
    for (auto i = 0u; i < std::max(y.data_.size(), data_.size()); i++)
    {
        auto xx = i >= data_.size() ? 0 : data_[i];
        auto yy = i >= y.data_.size() ? 0 : y.data_[i];
        
        if (0LL + xx >= 0LL + yy + carrier) 
        {
            result.data_.push_back(xx - yy - carrier);
            carrier = 0;
        }
        
        else
        {
            result.data_.push_back(BASE + xx - yy - carrier);
            carrier = 1;
        }
    }
   
    return result;
}

BigNumber BigNumber::operator*(const BigNumber &y) const
{
    BigNumber result;
    
    for (auto i = 0u; i < y.data_.size(); i++)
    {
        unsigned carrier = 0;
        BigNumber k;
        
        for (auto j = 0; j < i; j++)
            k.data_.push_back(0);
        
        for (auto j = 0; j < data_.size(); j++)
        {
            auto xx = data_[j];
            auto yy = y.data_[i];
            uint64_t r = 1ULL * xx * yy + carrier;
            k.data_.push_back(r % BASE);
            carrier = r / BASE;
        }
        
        if (carrier != 0)
            k.data_.push_back(carrier);
        
        result = result + k;
    }
    
    return result;
}

