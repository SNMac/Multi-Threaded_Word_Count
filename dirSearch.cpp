/**
 * @file
 * @brief
 * @date 2022/10/17
 * @author SNMac
 */

#include <cstdio>
#include <thread>

#include "main.h"

using namespace std;
namespace fs = filesystem;

void dirSearch(fo_t* fileArg, const fs::path& dir, unsigned long long& ret) {
    thread::id this_id = this_thread::get_id();
    static unsigned long long total;
    static int depth;
    fo_t* fo = fileArg;
    fo->EndOfDir = false;
    if (fs::is_regular_file(dir)) {  // if argv[1] is regular file

        /* fileObj critical section begin */
        fo->m.lock();
        fo->fileQueue.push(dir.string());
        fo->fileReady.notify_one();  // notify to producer that file is ready
        fo->m.unlock();
        /* fileObj critical section end */

        total++;
    } else if (fs::is_directory(dir)) {
        fs::directory_iterator itr(dir);
        while(itr != fs::end(itr)) {
            const fs::directory_entry& entry = *itr;
            if (fs::is_regular_file(entry.path())) {

                /* fileObj critical section begin */
                fo->m.lock();
                fo->fileQueue.push(entry.path().string());
                fo->fileReady.notify_one();  // notify to producer that file is ready
                fo->m.unlock();
                /* fileObj critical section end */

                total++;
            } else if (fs::is_directory(entry.path())) {
                depth++;
                dirSearch(fileArg, entry.path(), total);
            }
            itr++;
        }
    }
    if (depth) {
        depth--;
    } else {

        /* fileObj critical section begin */
        fo->m.lock();
        fo->EndOfDir = true;
        fo->fileReady.notify_all();  // wake up all producer threads
        fo->m.unlock();
        /* fileObj critical section end */

        printf("dirS_%x) %llu files\n", this_id, total);
        ret = total;
    }
}