/**
 * @file
 * @brief
 * @date 2022/10/06
 * @author SNMac
 */

#ifndef INC_2022_OS_HW2_MAIN_H
#define INC_2022_OS_HW2_MAIN_H

#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>
#include <filesystem>

#define MAX_LINEQUEUE_SIZE 10000000
#define MAX_STRING_LENGTH 30
#define ASCII_SIZE 256

typedef struct fileObject {
    std::mutex m;
    std::condition_variable fileReady;
    std::queue<std::string> fileQueue;
    bool EndOfDir = false;
} fo_t;

typedef struct lineObject {
    std::mutex m;
    std::condition_variable lineReady;
    std::condition_variable lineQueueFull;
    std::queue<std::pair<unsigned long long, std::string>> lineQueue;
    unsigned long long totalReadLine = 0;
    bool EndOfFile = false;
    int Nprod = 0;
} lo_t;

typedef struct statObject {
    std::mutex m;
    unsigned long long stat[MAX_STRING_LENGTH] = {0, };
    unsigned long long stat2[ASCII_SIZE] = {0, };
    std::string sep = "{}()[],;\" \n\t^";
} so_t;

void dirSearch(fo_t* fileArg, const std::filesystem::path& dir, unsigned long long& ret);
void producer(fo_t* fileArg, lo_t* lineArg, std::vector<unsigned long long>& ret);
void consumer(lo_t* lineArg, so_t* statArg, std::vector<unsigned long long>& ret);
void printResult(so_t* statArg);

#endif //INC_2022_OS_HW2_MAIN_H
