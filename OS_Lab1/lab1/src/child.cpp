#include <iostream>
#include <fstream>
#include <algorithm>

bool isVowel(char c) {
    return c == 'e' ||
           c == 'u' ||
           c == 'i' ||
           c == 'o' ||
           c == 'a';
}


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("No input file.\n");
        exit(EXIT_FAILURE);
    }

    std::string filename(argv[1]);
    std::ofstream file(filename);


    for (std::string line; std::getline(std::cin, line); ) {
        line.push_back('\n');
        int len = line.length();
        if (len > 0) { 
            line.erase(std::remove_if(line.begin(), line.end(), 
                [](unsigned char x) 
                {
                    return isVowel(tolower(x));
                }), line.end());
        }
        file << line;
    }

    return 0;
}