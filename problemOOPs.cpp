#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

class StringUtils{
    public:
    std::string format(const std::string& text){
        std::string temp = text;
        std::transform(temp.begin() , temp.end() , temp.begin(),::toupper);
       return temp;
    }
    std::string format(const std::string& text, int repeateCount){

        if(repeateCount <= 0) return "";
        std::string result = text;

        while(repeateCount--){
          result += " " + text;
        }
        return result;
    }
    std::string format(const std::string& text, bool addBrackters){
        if(addBrackters){
            return ("[" + text + "]");
        }else{   
            return text;
        }
    }
    std::string format(const std::string& text, const std::string& prefix, const std::string& suffix){
        return (prefix + text  + suffix);
    }
    ~StringUtils() = default;
};

int main(){

    StringUtils test;

    std::cout<< test.format("hello")<< std::endl;
    std::cout << test.format("kali" , 3) << std::endl;
    std::cout<< test.format("rahul", true)<<std::endl;
    std::cout<< test.format("2", "H" , "O");
    return 0;
}