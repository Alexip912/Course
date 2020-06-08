#ifndef TRANSLATE_H
#define TRANSLATE_H

#pragma warning(disable : 4996)

#include "menu.h"
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define AIRPORT "D:/code/TRPO/Course/Topics/Airport.txt"
#define CAR "D:/code/TRPO/Course/Topics/Car.txt"
#define CINEMA "D:/code/TRPO/Course/Topics/Cinema.txt"
#define CITY "D:/code/TRPO/Course/Topics/City.txt"
#define DISEASES "D:/code/TRPO/Course/Topics/Diseases.txt"
#define EDUCATION "D:/code/TRPO/Course/Topics/Education.txt"
#define MUSIC "D:/code/TRPO/Course/Topics/Music.txt"
#define POLITICS "D:/code/TRPO/Course/Topics/Politics.txt"
#define SOCIETY "D:/code/TRPO/Course/Topics/Society.txt"
#define CHEMISTRY_PHYSICS "D:/code/TRPO/Course/Topics/Ñhemistry_physics.txt"

bool answerCheck(
        const std::string answer,
        std::vector<std::pair<std::string, std::string>>& wordsFromFile,
        const int index);
void translate(std::vector<std::pair<std::string, std::string>>& wordsFromFile);
void fileParse(
        const std::string path,
        std::vector<std::pair<std::string, std::string>>& wordsFromFile);
void secondMenu();

#endif
