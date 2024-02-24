#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#define RAND_MAX 0x7fff
using namespace std;

int makeRandomNumber(int min, int max)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    return min + std::rand() % (max - min + 1);
}

int main()
{
    while (true)
    {
        int min, max;
        std::cout << "Min Value = ";
        std::cin >> min;
        std::cout << "Max value = ";
        std::cin >> max;
        int randomNumber = makeRandomNumber(min, max);
        while (true)
        {
            std::cout << "The value is in range [" << min << ", " << max << "]" << std::endl;
            std::cout << "Your choosen value is: ";
            int choose;
            std::cin >> choose;
            if (choose == randomNumber)
            {
                std::cout << "Congratulation!" << std::endl;
                break;
            }
            if (choose < randomNumber)
                min = choose;
            else
                max = choose;
        }
        std::cout << "Do you want to continue [Y/N] :";
        char c;
        std::cin >> c;
        if (c == 'N')
            break;
    }
    return 0;
}