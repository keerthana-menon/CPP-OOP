# ifndef _CONV_H
# define _CONV_H
# include <iostream>
# include <utility>
# include <vector>

class NumArray
{
    friend std::ostream &operator<<(std::ostream &os, const NumArray &obj);
    private:
        std::vector<float> num;
    public:
        // Constructor
        NumArray(std::vector<float> a)
        {
            num = a;
        }
        // Overloaded operators
        NumArray operator*(const NumArray &rhs) const;
};

# endif