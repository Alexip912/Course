#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#pragma warning(disable : 4996)
#define PATH "D:\\code\\TRPO\\Course\\Topics\\Airport.txt"

bool answerCheck(
        const string answer,
        vector<pair<string, string>>& wordsFromFile,
        const int index);
void translate(vector<pair<string, string>>& wordsFromFile);
void fileParse(const string path, vector<pair<string, string>>& wordsFromFile);
void menu();
void secondMenu();

int main()
{
    setlocale(LC_ALL, "rus");

    menu();

	secondMenu();

    cin.get();
    cin.get();
    return 0;
}

bool answerCheck(
        const string answer,
        vector<pair<string, string>>& wordsFromFile,
        const int index)
{
    if (answer == wordsFromFile[index].first) {
        return true;
    } else {
        return false;
    }
}

void translate(vector<pair<string, string>>& wordsFromFile)
{
    int testSize = wordsFromFile.size();
    bool isCorrect;

    for (int i = 0; i < testSize; i++) {
        string answer;

        cout << "  Переведите данное слово на английский язык:\n  "
             << wordsFromFile[i].second << "\n\n";

        cout << "  Введите перевод: ";
        cin >> answer;

        isCorrect = answerCheck(answer, wordsFromFile, i);
        if (isCorrect) {
            cout << "\n  Все верно!\n\n";
        } else {
            cout << "\n  Нет, это слово переводится так:\n  "
                 << wordsFromFile[i].first << "\n\n";
        }
    }
}

void fileParse(const string path, vector<pair<string, string>>& wordsFromFile)
{
    vector<string> wordsFromLine;

    ifstream file(path);

    while (!file.eof()) {
        pair<string, string> pair;
        string text;
        string delim = " ";

        getline(file, text);

        size_t previous = 0;
        size_t next;
        size_t delta = delim.length();

        while ((next = text.find(delim, previous)) != string::npos) {
            string buffer = text.substr(previous, next - previous);
            pair.first = buffer;
            previous = next + delta;
        }
        string buffer = text.substr(previous);
        pair.second = buffer;

        wordsFromFile.push_back(pair);
    }
}

void menu()
{
    int choose;
    bool menuState = true;

    cout << "===================================================\n";
    cout << "|          Добро пожаловать в программу           |\n";
    cout << "|      проверки знания слов английского языка     |\n";

    while (menuState) {
        cout << "===================================================\n";
        cout << "| 1. Правила                                      |\n"
             << "| 2. Выбор темы                                   |\n"
             << "| 3. Авторы                                       |\n"
             << "| 4. Выход                                        |\n";
        cout << "===================================================\n";
        cout << "Выберите пункт меню: ";
        cin >> choose;

        switch (choose) {
        case 1:
            cout << "\n  Чтобы начать проверку знаниня английских слов,\n"
                 << "  выберите пункт меню \"Выбор темы\" \n"
                 << "  И выберите тему, по которой хотите пройти проверку.\n"
                 << "  После этого, на экран выведится слово, которое нужно "
                    "перевести\n"
                 << "  Если ваш перевод будет верным - выведется следующее "
                    "слово.\n"
                 << "  Если же перевод будет неверным - выведется правильный "
                    "перевод.\n\n";
            break;
        case 2:
            break;
        case 3:
            cout << "\n  Курсовой проект по дисциплине\n"
                 << "  \"Технологии разработки программного обеспечения\".\n"
                 << "  Выполнен студентом группы ИП-912 Шкуратовым "
                    "Алексеем.\n\n";
            break;
        case 4:
            cout << "\n  Выход\n\n";
            menuState = false;
            break;
        default:
            cout << "\n  Ошибка ввода!\n\n";
            break;
        }
    }
}

void secondMenu()
{
    vector<pair<string, string>> wordsFromFile;
    int choose;

    cout << "===================================================\n";
    cout << "|          Выберите тему для проверки             |\n";
    cout << "|            из ниже представленных               |\n";
    cout << "===================================================\n";
    cout << "| 1. Аэропорт                                     |\n";
    cout << "| 2. Машины                                       |\n";
    cout << "| 3. Кино                                         |\n";
    cout << "| 4. Город                                        |\n";
    cout << "| 5. Болезни                                      |\n";
    cout << "| 6. Образование                                  |\n";
    cout << "| 7. Музыка                                       |\n";
    cout << "| 8. Политика                                     |\n";
    cout << "| 9. Общество                                     |\n";
    cout << "| 10. Химия и физика                              |\n";
    cout << "| 11. Вернуться назад                             |\n";
    cout << "===================================================\n";
    cout << "Выберите пункт меню: ";
    cin >> choose;

    switch (choose) {
    case 1:
        cout << "\n  Вы выбрали тему \"Аэропорт\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 2:
        cout << "\n  Вы выбрали тему \"Машины\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 3:
        cout << "\n  Вы выбрали тему \"Кино\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 4:
        cout << "\n  Вы выбрали тему \"Город\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 5:
        cout << "\n  Вы выбрали тему \"Болезни\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 6:
        cout << "\n  Вы выбрали тему \"Образование\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 7:
        cout << "\n  Вы выбрали тему \"Музыка\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 8:
        cout << "\n  Вы выбрали тему \"Политика\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 9:
        cout << "\n  Вы выбрали тему \"Общество\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 10:
        cout << "\n  Вы выбрали тему \"Химия и физика\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 11:
        menu();
        break;
    default:
        cout << "\n  Ошибка ввода!\n\n";
        break;
    }
}