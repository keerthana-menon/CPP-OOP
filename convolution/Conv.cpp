# include "Conv.hpp"

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

NumArray NumArray::operator*(const NumArray & rhs) const
{
    std::vector<float> arr;
    int m = this->num.size(), n = rhs.num.size();
    for(int k = 0; k < m + n - 1; k++)
    {
        arr.push_back(0.0);
        for(int j = max(0, k + 1 - n); j <= min(k, m - 1); j++)
        {
            float pa = this->num[j] * rhs.num[k - j];
            arr[k] += pa;
        }
    }
    NumArray temp(arr);
    return temp;
}

std::ostream &operator<<(std::ostream &os, const NumArray &obj)
{
    os << "Convolution: ";
    for(auto iter = obj.num.begin(); iter != obj.num.end(); iter++)
    {
        os << *iter << " ";
    }
    return os;
}