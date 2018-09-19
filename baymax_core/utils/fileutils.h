#include <string>
#include <cstring>

namespace baymax {

std::string read_file(const char* filepath)
{
    FILE* file = fopen(filepath, "rt");
    fseek(file, 0, SEEK_END);
    
    unsigned int size = ftell(file);
    char* data = new char[size + 1];
    memset(data, 0, size + 1);
    fseek(file, 0, SEEK_SET);
    fread(data, 1, size, file);

    std::string result(data);
    delete[] data;
    return result;
}


}