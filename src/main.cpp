#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

#pragma warning(disable : 4996)
#define PATH "D:\\code\\TRPO\\Course\\Topics\\Airport.txt"

void menu()
{
    int choose;
    bool menuState = true;

    cout << "===================================================\n";
    cout << "| Добро пожаловать в программу                    |\n";
    cout << "| проверки знания слов английского языка          |\n";

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


		/*cout << text << endl;
		char* buffer = new char[text.length() + 1];
        char const* delim = " \n";
		memcpy(buffer, text.c_str(), (text.size() + 1) * sizeof(*buffer));
        //strcpy(buffer, text.c_str());
		char const* token = strtok(buffer, delim);
        while (token != NULL) {
			pair.first = token;
            token = strtok(NULL, delim);
            pair.second = token;
		}
		delete[] buffer;
        delete[] token;
        wordsFromFile.push_back(pair);*/
	}
}

int main()
{
    setlocale(LC_ALL, "rus");

    ifstream Airport(PATH);
    if (!Airport.is_open())
        cout << "бан\n";

    //menu();

	vector<pair<string, string>> wordsFromFile;
    fileParse(PATH, wordsFromFile);

	for (int i = 0; i < wordsFromFile.size(); i++) {
        cout << wordsFromFile[i].first << " - " 
			 << wordsFromFile[i].second
             << "\n";
	}

    cin.get();
    cin.get();
    return 0;
}