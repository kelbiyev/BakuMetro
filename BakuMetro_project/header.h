#ifndef BAKUMETRO_PROJECT_HEADER_H
#define BAKUMETRO_PROJECT_HEADER_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <memory>
void sleep_ms(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

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

void initializeLines() {
    for (size_t i = 0; i < allStations.size(); ++i) {
        stationIndex[allStations[i]] = static_cast<int>(i);
    }
    stationMutexes.reserve(allStations.size());
    for (size_t i = 0; i < allStations.size(); ++i) {
        stationMutexes.push_back(std::make_unique<std::mutex>());
    }
    lines = {
            {"Red", {
                            stationIndex["Icherisheher"],
                            stationIndex["Sahil"],
                            stationIndex["28 May"],
                            stationIndex["Ganjlik"],
                            stationIndex["Nariman Narimanov"],
                            stationIndex["Bakmil"],
                            stationIndex["Ulduz"],
                            stationIndex["Koroghlu"],
                            stationIndex["Gara Garaev"],
                            stationIndex["Neftchiler"],
                            stationIndex["Khalqlar Dostlughu"],
                            stationIndex["Ahmedli"],
                            stationIndex["Hazi Aslanov"]
                    }},
            {"Green", {
                            stationIndex["Darnagul"],
                            stationIndex["Azadlig Prospekti"],
                            stationIndex["Nasimi"],
                            stationIndex["Memar Ajami"],
                            stationIndex["20 Yanvar"],
                            stationIndex["Inshaatchilar"],
                            stationIndex["Elmler Akademiyasi"],
                            stationIndex["Nizami"],
                            stationIndex["Ganjlik"],
                            stationIndex["Nariman Narimanov"],
                            stationIndex["Bakmil"],
                            stationIndex["Ulduz"],
                            stationIndex["Koroghlu"],
                            stationIndex["Gara Garaev"],
                            stationIndex["Neftchiler"],
                            stationIndex["Khalqlar Dostlughu"],
                            stationIndex["Ahmedli"],
                            stationIndex["Hazi Aslanov"]
                    }},
            {"Violet", {
                            stationIndex["Khojasan"],
                            stationIndex["Avtovaghzal"],
                            stationIndex["Memar Ajami"],
                            stationIndex["8 Noyabr"]
                    }},
            {"Lime", {
                            stationIndex["Jafar Jabbarli"],
                            stationIndex["Khatai"]
                    }}
    };
}

void train(int train_id, const Line& line, bool direction) {
    while (true) {
        int start = direction ? 0 : static_cast<int>(line.stationIndices.size()) - 1;
        int end   = direction ? static_cast<int>(line.stationIndices.size()) - 1 : 0;
        int step  = direction ? 1 : -1;

        for (int i = start; direction ? (i <= end) : (i >= end); i += step) {
            int idx = line.stationIndices[i];
            {
                std::lock_guard<std::mutex> stationLock(*stationMutexes[idx]);

                {
                    std::lock_guard<std::mutex> coutLock(coutMutex);
                    std::cout << "Train " << train_id
                              << " (" << line.name << " Line) has arrived at "
                              << allStations[idx]
                              << " (Direction: " << (direction ? "Forward" : "Backward") << ")\n";
                }

                sleep_ms(2000);

                {
                    std::lock_guard<std::mutex> coutLock(coutMutex);
                    std::cout << "Train " << train_id
                              << " is leaving " << allStations[idx] << "\n";
                }
            }

            sleep_ms(500);
        }

        {
            std::lock_guard<std::mutex> coutLock(coutMutex);
            std::cout << "Train " << train_id << " is turning around at "
                      << allStations[line.stationIndices[end]] << "\n";
        }

        direction = !direction;
    }
}




#endif //BAKUMETRO_PROJECT_HEADER_H
