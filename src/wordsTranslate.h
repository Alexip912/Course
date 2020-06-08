#ifndef TRANSLATE_H
#define TRANSLATE_H

#define _CRT_SECURE_NO_WARNINGS

#include "menu.h"
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define AIRPORT "Topics/Airport.txt"
#define CAR "Topics/Car.txt"
#define CINEMA "Topics/Cinema.txt"
#define CITY "Topics/City.txt"
#define DISEASES "Topics/Diseases.txt"
#define EDUCATION "Topics/Education.txt"
#define MUSIC "Topics/Music.txt"
#define POLITICS "Topics/Politics.txt"
#define SOCIETY "Topics/Society.txt"
#define CHEMISTRY_PHYSICS "Topics/Сhemistry_physics.txt"

bool answerCheck(
        const std::string answer,
        std::vector<std::pair<std::string, std::string>>& wordsFromFile,
        const int index);
void translate(std::vector<std::pair<std::string, std::string>>& wordsFromFile);
bool checkPath(const std::string path);
void fileParse(
        const std::string path,
        std::vector<std::pair<std::string, std::string>>& wordsFromFile);
void secondMenu();

#endif
