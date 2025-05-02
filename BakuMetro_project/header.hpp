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

extern std::vector<std::string> allStations;

extern std::map<std::string, int> stationIndex;

extern std::vector<std::unique_ptr<std::mutex>> stationMutexes;

extern std::mutex coutMutex;

struct Line {
    std::string name;
    std::vector<int> stationIndices;
};

extern std::vector<Line> lines;

void initializeLines();

void train(int train_id, const Line& line, bool direction);

#endif // BAKUMETRO_PROJECT_HPP
