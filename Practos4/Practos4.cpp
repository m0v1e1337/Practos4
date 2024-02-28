#include <iostream>
#include <algorithm>
#include <random>
#include <string>

void reverse(std::string& word) {
    std::reverse(word.begin(), word.end());
}

void removeVowels(std::string& word) {
    std::string vowels = "aeiouAEIOU";
    word.erase(std::remove_if(word.begin(), word.end(), [&vowels](const char c) {
        return vowels.find(c) != std::string::npos;
        }), word.end());
}

void removeConsonants(std::string& word) {
    std::string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    word.erase(std::remove_if(word.begin(), word.end(), [&consonants](const char c) {
        return consonants.find(c) != std::string::npos;
        }), word.end());
}

void shuffle(std::string& word) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(word.begin(), word.end(), gen);
}

int main() {
    std::string word;
    std::cout << "Введи слово: ";
    std::cin >> word;

    int choice;
    while (true) {
        std::cout << "\nSelect an action:\n";
        std::cout << "1. Задом наперед.\n";
        std::cout << "2. Слово без гласных.\n";
        std::cout << "3. Слово без согласных.\n";
        std::cout << "4. Раскидывать буквы заданного слова.\n";
        std::cout << "Выберите цифру (1-4): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            reverse(word);
            break;
        case 2:
            removeVowels(word);
            break;
        case 3:
            removeConsonants(word);
            break;
        case 4:
            shuffle(word);
            break;
        default:
            std::cout << "Нет такой цифры, гений.";
            continue;
        }

        std::cout << "Гена, вот твое полотенце: " << word << std::endl;
        break;
    }

    return 0;
}
