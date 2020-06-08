#include "wordsTranslate.h"

bool answerCheck(
        const std::string answer,
        std::vector<std::pair<std::string, std::string>>& wordsFromFile,
        const int index)
{
    if (answer == wordsFromFile[index].first) {
        return true;
    } else {
        return false;
    }
}

void translate(std::vector<std::pair<std::string, std::string>>& wordsFromFile)
{
    int testSize = wordsFromFile.size();
    bool isCorrect;

    for (int i = 0; i < testSize; i++) {
        std::string answer;

        std::cout << "  Переведите данное слово на английский язык:\n  "
                  << wordsFromFile[i].second << "\n";

        std::cout << "  Введите перевод: ";
        std::cin >> answer;

        isCorrect = answerCheck(answer, wordsFromFile, i);
        if (isCorrect) {
            std::cout << "\n  Все верно!\n\n";
        } else {
            std::cout << "\n  Нет, это слово переводится так:\n  "
                      << wordsFromFile[i].first << "\n\n";
        }
    }
}

void fileParse(
        const std::string path,
        std::vector<std::pair<std::string, std::string>>& wordsFromFile)
{
    std::ifstream file(path);

    while (!file.eof()) {
        std::pair<std::string, std::string> pair;
        std::string text;
        std::string delim = " ";

        getline(file, text);

        size_t previous = 0;
        size_t next;
        size_t delta = delim.length();

        while ((next = text.find(delim, previous)) != std::string::npos) {
            std::string buffer = text.substr(previous, next - previous);
            pair.first = buffer;
            previous = next + delta;
        }
        std::string buffer = text.substr(previous);
        pair.second = buffer;

        wordsFromFile.push_back(pair);
    }
}

void secondMenu()
{
    std::vector<std::pair<std::string, std::string>> wordsFromFile;
    int choose;

    std::cout << "===================================================\n";
    std::cout << "|          Выберите тему для проверки             |\n";
    std::cout << "|            из ниже представленных               |\n";
    std::cout << "===================================================\n";
    std::cout << "| 1. Аэропорт                                     |\n";
    std::cout << "| 2. Машины                                       |\n";
    std::cout << "| 3. Кино                                         |\n";
    std::cout << "| 4. Город                                        |\n";
    std::cout << "| 5. Болезни                                      |\n";
    std::cout << "| 6. Образование                                  |\n";
    std::cout << "| 7. Музыка                                       |\n";
    std::cout << "| 8. Политика                                     |\n";
    std::cout << "| 9. Общество                                     |\n";
    std::cout << "| 10. Химия и физика                              |\n";
    std::cout << "| 11. Вернуться назад                             |\n";
    std::cout << "===================================================\n";
    std::cout << "  Выберите пункт меню: ";
    std::cin >> choose;

    switch (choose) {
    case 1:
        std::cout << "\n  Вы выбрали тему \"Аэропорт\"!\n";
        fileParse(AIRPORT, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 2:
        std::cout << "\n  Вы выбрали тему \"Машины\"!\n";
        fileParse(CAR, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 3:
        std::cout << "\n  Вы выбрали тему \"Кино\"!\n";
        fileParse(CINEMA, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 4:
        std::cout << "\n  Вы выбрали тему \"Город\"!\n";
        fileParse(CITY, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 5:
        std::cout << "\n  Вы выбрали тему \"Болезни\"!\n";
        fileParse(DISEASES, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 6:
        std::cout << "\n  Вы выбрали тему \"Образование\"!\n";
        fileParse(EDUCATION, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 7:
        std::cout << "\n  Вы выбрали тему \"Музыка\"!\n";
        fileParse(MUSIC, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 8:
        std::cout << "\n  Вы выбрали тему \"Политика\"!\n";
        fileParse(POLITICS, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 9:
        std::cout << "\n  Вы выбрали тему \"Общество\"!\n";
        fileParse(SOCIETY, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 10:
        std::cout << "\n  Вы выбрали тему \"Химия и физика\"!\n";
        fileParse(CHEMISTRY_PHYSICS, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 11:
        menu();
        break;
    default:
        std::cout << "\n  Ошибка ввода!\n\n";
        break;
    }
}