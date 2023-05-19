#include <iostream>
#include <filesystem>

using namespace std::filesystem;
int main() {
    std::cout << "Benvenuti nel software, per proseguire digitare un percorso di inizio" << std::endl;
    std::string path;
    std::cin>>path;
    path = "../../../";

    for (const auto & file: directory_iterator(path)) {
        std::cout << file.path() << std::endl;
    }




    return 0;
}
