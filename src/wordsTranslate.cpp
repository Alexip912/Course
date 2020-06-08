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

bool checkPath(const std::string path)
{
    std::ifstream test(path);
    return test.is_open();
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
        if (!checkPath(AIRPORT)) {
            std::cout << "  Отсутствует файл со словами!\n";
        } else {
            std::cout << "\n  Вы выбрали тему \"Аэропорт\"!\n\n";
            fileParse(AIRPORT, wordsFromFile);
            translate(wordsFromFile);
        }
        break;
    case 2:
        if (!checkPath(CAR)) {
            std::cout << "  Отсутствует файл со словами!\n";
        } else {
            std::cout << "\n  Вы выбрали тему \"Машины\"!\n\n";
            fileParse(CAR, wordsFromFile);
            translate(wordsFromFile);
        }
        break;
    case 3:
        if (!checkPath(CINEMA)) {
            std::cout << "  Отсутствует файл со словами!\n";
        } else {
            std::cout << "\n  Вы выбрали тему \"Кино\"!\n\n";
            fileParse(CINEMA, wordsFromFile);
            translate(wordsFromFile);
        }
        break;
    case 4:
        if (!checkPath(CITY)) {
            std::cout << "  Отсутствует файл со словами!\n";
        } else {
            std::cout << "\n  Вы выбрали тему \"Город\"!\n\n";
            fileParse(CITY, wordsFromFile);
            translate(wordsFromFile);
        }
        break;
    case 5:
        if (!checkPath(DISEASES)) {
            std::cout << "  Отсутствует файл со словами!\n";
        } else {
            std::cout << "\n  Вы выбрали тему \"Болезни\"!\n\n";
            fileParse(DISEASES, wordsFromFile);
            translate(wordsFromFile);
        }
        break;
    case 6:
        if (!checkPath(EDUCATION)) {
            std::cout << "  Отсутствует файл со словами!\n";
        } else {
            std::cout << "\n  Вы выбрали тему \"Образование\"!\n\n";
            fileParse(EDUCATION, wordsFromFile);
            translate(wordsFromFile);
        }
        break;
    case 7:
        if (!checkPath(MUSIC)) {
            std::cout << "  Отсутствует файл со словами!\n";
        } else {
            std::cout << "\n  Вы выбрали тему \"Музыка\"!\n\n";
            fileParse(MUSIC, wordsFromFile);
            translate(wordsFromFile);
        }
        break;
    case 8:
        if (!checkPath(POLITICS)) {
            std::cout << "  Отсутствует файл со словами!\n";
        } else {
            std::cout << "\n  Вы выбрали тему \"Политика\"!\n\n";
            fileParse(POLITICS, wordsFromFile);
            translate(wordsFromFile);
        }
        break;
    case 9:
        if (!checkPath(SOCIETY)) {
            std::cout << "  Отсутствует файл со словами!\n";
        } else {
            std::cout << "\n  Вы выбрали тему \"Общество\"!\n\n";
            fileParse(SOCIETY, wordsFromFile);
            translate(wordsFromFile);
        }
        break;
    case 10:
        if (!checkPath(CHEMISTRY_PHYSICS)) {
            std::cout << "  Отсутствует файл со словами!\n";
        } else {
            std::cout << "\n  Вы выбрали тему \"Химия и физика\"!\n\n";
            fileParse(CHEMISTRY_PHYSICS, wordsFromFile);
            translate(wordsFromFile);
        }
        break;
    case 11:
        menu();
        break;
    default:
        std::cout << "\n  Ошибка ввода!\n\n";
        break;
    }

    std::cout << "  Вы перевели все слова по данной теме!\n\n";
}