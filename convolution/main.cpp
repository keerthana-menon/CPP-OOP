# include "Conv.hpp"

int main()
{
    int m, n;

    std::cout << "Enter the size of the first array: ";
    std::cin >> m;
    std::cout << "Enter the elements of the first array: ";
    std::vector<float> first_array;
    for(int i = 0; i < m; i++)
    {
        float a;
        std::cin >> a;
        first_array.push_back(a);
    }
    NumArray vec1(first_array);

    std::cout << "Enter the size of the second array: ";
    std::cin >> n;
    std::cout << "Enter the elements of the second array: ";
    std::vector<float> second_array;
    for(int i = 0; i < n; i++)
    {
        float a;
        std::cin >> a;
        second_array.push_back(a);
    }
    NumArray vec2(second_array);

    std::cout << vec1 * vec2;
    
    return 0;
}