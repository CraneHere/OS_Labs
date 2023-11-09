#include <iostream>
#include <fstream>

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
        if (line.length() > 0) {
            for (size_t i = 0; i < line.length(); ++i) {
                if (isVowel(tolower(line[i]))) {
                    line.erase(i, 1);
                }
            }
        }
        file << line;
    }

    return 0;
}