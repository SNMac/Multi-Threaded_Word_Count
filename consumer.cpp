/**
 * @file
 * @brief
 * @date 2022/10/06
 * @author SNMac
 */

#include <cstdio>
#include <thread>

#include "main.h"

using namespace std;

void consumer(lo_t* lineArg, so_t* statArg, vector<unsigned long long>& ret) {
    thread::id this_id = this_thread::get_id();

    lo_t* lo = lineArg;
    so_t* so = statArg;
    unsigned long long total = 0;
    unsigned long long linenum, totalReadLine;
    string line;

    while(true) {

        /* lineObj critical section begin */
        unique_lock<mutex> cons_lock(lo->m);
        while(lo->lineQueue.empty()) {
            if (lo->EndOfFile) {  // queue is empty and producer() file read is completed
                cons_lock.unlock();
                goto BRK;
            }
            lo->lineReady.wait(cons_lock);  // wait for producer() signal
        }  // if queue is not empty, continue file print
        linenum = lo->lineQueue.front().first;
        line = lo->lineQueue.front().second;
        lo->lineQueue.pop();
        totalReadLine = lo->totalReadLine;
        if (!lo->EndOfFile && lo->lineQueue.size() <= MAX_LINEQUEUE_SIZE / 4)
            lo->lineQueueFull.notify_all();
        cons_lock.unlock();
        /* lineObj critical section end */

        printf("Cons_%x) [%02llu:%02llu] %s\n", this_id, linenum, totalReadLine, line.c_str());
        total++;

        /* gather statistics of the given text in the file */
        vector<string> subStr;
        vector<int> subStrIndex;
        subStrIndex.push_back(-1);
        size_t length;
        for (int i = 0; i < line.length(); i++) {
            if (so->sep.find(line[i]) == string::npos)
                continue;
            else
                subStrIndex.push_back(i);
        }
        subStrIndex.push_back((int)line.length());
        for (int i = 0; i < subStrIndex.size() - 1; i++) {
            int start = subStrIndex[i] + 1;
            int end = subStrIndex[i + 1];
            string token = line.substr(start, end - start);
            if (token.empty())
                continue;
            subStr.push_back(line.substr(start, end - start));
        }

        for (const auto& s : subStr) {
            length = (int)s.length();
            // update stats

            // length of the sub-string
            if (length > MAX_STRING_LENGTH)
                length = MAX_STRING_LENGTH;

#ifdef _IO_
            printf("length: %d\n", (int)length);
#endif
            // number of the ASCII character in the sub-string
            /* statObj critical section begin */
            so->m.lock();
            so->stat[length - 1]++;
            for (auto c : s) {
                if (c < 256 && c > 1) {
                    so->stat2[c]++;
#ifdef _IO_
                    printf("# of %c(%d): %d\n", c, c, lo->stat2[c]);
#endif
                }
            }
            so->m.unlock();
            /* statObj critical section end */
        }
    }

    BRK:
    printf("Cons_%x) %llu lines\n", this_id, total);

    /* vector<unsigned long long> consRet critical section begin */
    so->m.lock();
    ret.push_back(total);
    so->m.unlock();
    /* vector<unsigned long long> consRet critical section end */
}