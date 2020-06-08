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

        cout << "  ���������� ������ ����� �� ���������� ����:\n  "
             << wordsFromFile[i].second << "\n\n";

        cout << "  ������� �������: ";
        cin >> answer;

        isCorrect = answerCheck(answer, wordsFromFile, i);
        if (isCorrect) {
            cout << "\n  ��� �����!\n\n";
        } else {
            cout << "\n  ���, ��� ����� ����������� ���:\n  "
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
    cout << "|          ����� ���������� � ���������           |\n";
    cout << "|      �������� ������ ���� ����������� �����     |\n";

    while (menuState) {
        cout << "===================================================\n";
        cout << "| 1. �������                                      |\n"
             << "| 2. ����� ����                                   |\n"
             << "| 3. ������                                       |\n"
             << "| 4. �����                                        |\n";
        cout << "===================================================\n";
        cout << "�������� ����� ����: ";
        cin >> choose;

        switch (choose) {
        case 1:
            cout << "\n  ����� ������ �������� ������� ���������� ����,\n"
                 << "  �������� ����� ���� \"����� ����\" \n"
                 << "  � �������� ����, �� ������� ������ ������ ��������.\n"
                 << "  ����� �����, �� ����� ��������� �����, ������� ����� "
                    "���������\n"
                 << "  ���� ��� ������� ����� ������ - ��������� ��������� "
                    "�����.\n"
                 << "  ���� �� ������� ����� �������� - ��������� ���������� "
                    "�������.\n\n";
            break;
        case 2:
            break;
        case 3:
            cout << "\n  �������� ������ �� ����������\n"
                 << "  \"���������� ���������� ������������ �����������\".\n"
                 << "  �������� ��������� ������ ��-912 ���������� "
                    "��������.\n\n";
            break;
        case 4:
            cout << "\n  �����\n\n";
            menuState = false;
            break;
        default:
            cout << "\n  ������ �����!\n\n";
            break;
        }
    }
}

void secondMenu()
{
    vector<pair<string, string>> wordsFromFile;
    int choose;

    cout << "===================================================\n";
    cout << "|          �������� ���� ��� ��������             |\n";
    cout << "|            �� ���� ��������������               |\n";
    cout << "===================================================\n";
    cout << "| 1. ��������                                     |\n";
    cout << "| 2. ������                                       |\n";
    cout << "| 3. ����                                         |\n";
    cout << "| 4. �����                                        |\n";
    cout << "| 5. �������                                      |\n";
    cout << "| 6. �����������                                  |\n";
    cout << "| 7. ������                                       |\n";
    cout << "| 8. ��������                                     |\n";
    cout << "| 9. ��������                                     |\n";
    cout << "| 10. ����� � ������                              |\n";
    cout << "| 11. ��������� �����                             |\n";
    cout << "===================================================\n";
    cout << "�������� ����� ����: ";
    cin >> choose;

    switch (choose) {
    case 1:
        cout << "\n  �� ������� ���� \"��������\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 2:
        cout << "\n  �� ������� ���� \"������\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 3:
        cout << "\n  �� ������� ���� \"����\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 4:
        cout << "\n  �� ������� ���� \"�����\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 5:
        cout << "\n  �� ������� ���� \"�������\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 6:
        cout << "\n  �� ������� ���� \"�����������\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 7:
        cout << "\n  �� ������� ���� \"������\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 8:
        cout << "\n  �� ������� ���� \"��������\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 9:
        cout << "\n  �� ������� ���� \"��������\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 10:
        cout << "\n  �� ������� ���� \"����� � ������\"!\n";
        fileParse(PATH, wordsFromFile);
        translate(wordsFromFile);
        break;
    case 11:
        menu();
        break;
    default:
        cout << "\n  ������ �����!\n\n";
        break;
    }
}