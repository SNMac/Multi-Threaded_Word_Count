/**
 * @file
 * @brief
 * @date 2022/10/06
 * @author SNMac
 */

#include <cstdio>
#include <fstream>
#include <thread>

#include "main.h"

using namespace std;

void producer(fo_t* fileArg, lo_t* lineArg, vector<unsigned long long>& ret) {
    thread::id this_id = this_thread::get_id();

    fo_t* fo = fileArg;
    lo_t* lo = lineArg;
    unsigned long long total = 0;
    string line;

    while(true) {

        /* fileObj critical section begin */
        unique_lock<mutex> fileProd_lock(fo->m);
        while(fo->fileQueue.empty()) {
            if (fo->EndOfDir) {  // queue is empty and dirSearch() directory search is completed
                fileProd_lock.unlock();
                /* fileObj critical section end */

                /* lineObj critical section begin */
                lo->m.lock();
                lo->Nprod--;
                if (lo->Nprod == 0) {
                    lo->EndOfFile = true;
                    lo->lineReady.notify_all();
                }
                lo->m.unlock();
                /* lineObj critical section end */

                goto BRK;
            }
            fo->fileReady.wait(fileProd_lock);  // wait for dirSearch() signal
        }  // if queue is not empty, continue file read
        fstream rfile(fo->fileQueue.front());
        fo->fileQueue.pop();
        fileProd_lock.unlock();
        /* fileObj critical section end */

        while(true) {
            // related to consumer()
            if (!getline(rfile, line)) {
                // End Of File
                break;
            }

            /* lineObj critical section begin */
            unique_lock<mutex> lineProd_lock(lo->m);
            if (lo->lineQueue.size() + 1 > MAX_LINEQUEUE_SIZE)
                lo->lineQueueFull.wait(lineProd_lock);
            lo->lineQueue.push(make_pair(++lo->totalReadLine, line));
            lo->lineReady.notify_one();  // notify to consumer that line is ready
            lineProd_lock.unlock();
            /* lineObj critical section end */

            total++;
        }
    }

    BRK:
    printf("Prod_%x) %llu lines\n", this_id, total);

    /* vector<unsigned long long> prodRet critical section begin */
    lo->m.lock();
    ret.push_back(total);
    lo->m.unlock();
    /* vector<unsigned long long> prodRet critical section end */
}