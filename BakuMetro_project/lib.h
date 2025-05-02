#ifndef BAKUMETRO_PROJECT_LIB_H
#define BAKUMETRO_PROJECT_LIB_H

#ifndef BAKUMETRO_PROJECT_HPP
#define BAKUMETRO_PROJECT_HPP

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <memory>


void sleep_ms(int ms);

std::vector<std::string> allStations;

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

#endif // BAKUMETRO_PROJECT_HPP

#endif //BAKUMETRO_PROJECT_LIB_H
