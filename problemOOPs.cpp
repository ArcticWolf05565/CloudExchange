#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

int main()
{

    std::vector<std::vector<int>> matrix;

    for (int i = 0; i < 3; i++)
    {
        std::vector<int> tempVec;
        for (int j = 0; j < 3; j++)
        {
            int userInput;
            std::cout << "Please Enter number: ";
            std::cin >> userInput;

            tempVec.push_back(userInput);
        }
        matrix.push_back(tempVec);
    }

    std::ofstream file;

    file.open("number.txt");

    if(!file.is_open()){
        std::cout<< "file not found." <<std::endl;
        return 1;
    }

    for (auto &row : matrix)
    {
        for (auto &col : row)
        {
            file << col << " ";
        }
        std::cout << std::endl;
    }

    file.close();

    std::ifstream open_file;
    open_file.open("number.txt");

    if(!open_file.is_open()){
        std::cout<< "file not found." <<std::endl;
        return 1;
    }

    int num;
    int sum = 0;
    double avg = 0;
    int count = 0;

    while(open_file >> num ){
        sum += num;
        count++;
    }

    avg = sum / count;
    std::cout << sum << std::endl;
    std::cout << avg << std::endl;

    return 0;
}