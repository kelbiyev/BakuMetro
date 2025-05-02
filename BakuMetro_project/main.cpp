#include "lib.h"

int main() {
    initializeLines();

    std::vector<std::thread> trains;
    for (size_t i = 0; i < lines.size(); ++i) {
        bool dir = (i % 2 == 0);
        trains.emplace_back(train, static_cast<int>(i + 1), std::ref(lines[i]), dir);//emplace_back позволяет эффективно добавляет в конец вектора новый объект
    }//std::ref передает ссылку на элемент lines[i]

    for (auto& t : trains) {
        t.join();
    }
    return 0;
}
