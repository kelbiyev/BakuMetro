#ifndef BAKUMETRO_PROJECT_LIB_H
#define BAKUMETRO_PROJECT_LIB_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <memory>

void sleep_ms(int ms);

 std::vector<std::string> allStations = {
    "Icherisheher", "Sahil", "28 May", "Ganjlik", "Nariman Narimanov",
    "Bakmil", "Ulduz", "Koroghlu", "Gara Garaev", "Neftchiler",
    "Khalqlar Dostlughu", "Ahmedli", "Hazi Aslanov", "Darnagul", "Azadlig Prospekti",
    "Nasimi", "Memar Ajami", "20 Yanvar", "Inshaatchilar", "Elmler Akademiyasi",
    "Nizami", "Khojasan", "Avtovaghzal", "8 Noyabr", "Jafar Jabbarli", "Khatai"
};

std::map<std::string, int> stationIndex;

std::vector<std::unique_ptr<std::mutex>> stationMutexes;

std::mutex coutMutex;

struct Line {
    std::string name;
    std::vector<int> stationIndices;
};

std::vector<Line> lines;

void initializeLines();

void train(int train_id, const Line& line, bool direction);

#endif //BAKUMETRO_PROJECT_LIB_H
