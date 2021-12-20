#include <iostream>
#include <fstream>

struct Work {
    std::string name;
    std::string n;
    std::string id;
};

int main()
{
    fstream fout;
    fout.open("File.txt");
    fout << "crufuhfhruhfr\n";
    fout.close();
    return  0;
}
