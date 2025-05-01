# 🚇 Baku Metro

Этот проект моделирует движение поездов по линиям метро с использованием многопоточности и синхронизации в C++. Каждый поезд двигается по своей линии, останавливается на станциях, ожидает, и разворачивается в конце маршрута.

---

## 🔧 Сборка проекта

### 📁 Требования

- **C++17** или выше
- **CMake** (ESLI вы используете CLion — уже встроено)
- Компилятор (GCC / Clang / MSVC)

### 🛠 Статическая сборка

```bash
mkdir build
cd build
cmake .. -DBUILD_SHARED_LIBS=OFF
make
```

### 🂨 Динамическая сборка

```bash
mkdir build
cd build
cmake .. -DBUILD_SHARED_LIBS=ON
make
```

---

## 📄 Описание структуры и компонентов

### 1. **Станции метро (`allStations`)**

```cpp
std::vector<std::string> allStations = { "Icherisheher", "Sahil", ..., "Khatai" };
```

---

### 2. **Сопоставление станций и их индексов**

```cpp
std::map<std::string, int> stationIndex;
```

---

### 3. **Мьютексы для синхронизации поездов на станциях**

```cpp
std::vector<std::unique_ptr<std::mutex>> stationMutexes;
```

---

### 4. **Структура `Line`**

```cpp
struct Line {
    std::string name;
    std::vector<int> stationIndices;
};
```

---

### 5. **Инициализация линий (`initializeLines`)**

- Заполняет `stationIndex`
- Инициализирует `stationMutexes`
- Создаёт линии: Red, Green, Violet, Lime

---

### 6. **Функция `train` — логика поезда**

```cpp
void train(int train_id, const Line& line, bool direction);
```

- `train_id`: идентификатор поезда
- `line`: линия метро
- `direction`: направление

---

### 7. **Функция `sleep_ms`**

```cpp
void sleep_ms(int ms);
```

Обёртка для `std::this_thread::sleep_for`

---

### 8. **`main` — запуск поездов**

- Инициализирует линии
- Создаёт потоки поездов
- Вызывает `join()` для ожидания (BESKONECHNYY cikl)

---

## 🧵 Многопоточность и синхронизация

- Каждый поезд работает в своём `std::thread`
- Мьютексы на станциях избегают конфликтов
- Мьютекс `coutMutex` защищает вывод в консоль

---

## 📊 Пример вывода

```
Train 1 (Red Line) has arrived at Icherisheher (Direction: Forward)
Train 1 is leaving Icherisheher
...
Train 1 is turning around at Hazi Aslanov
```

---

## 📌 Возможные улучшения

- Графическая визуализация
- Добавление/удаление станций во время работы
- GUI с Qt или SFML

