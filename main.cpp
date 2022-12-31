/**
 * @file
 * @brief
 * @date 2022/10/05
 * @author SNMac
 */

#include <cstdio>
#include <thread>
#include <chrono>

#include "main.h"

using namespace std;
namespace fs = filesystem;

int main (int argc, char* argv[]) {
    string strArgv[4];
    for (int i = 0; i < argc; i++)  // convert char* array to string array
        strArgv[i] = argv[i];

    auto programStart = chrono::steady_clock::now();
    vector<thread> prod;
    vector<thread> cons;
    unsigned long long dirSRet;
    vector<unsigned long long> prodRet;
    vector<unsigned long long> consRet;

    int Nprod, Ncons;
    int i;
    if (argc == 1) {
        printf("usage: ./2022_os_hw2 <Dirname or filename> #producer #consumer\n");
        exit(EXIT_SUCCESS);
    }

    fs::path filepath(strArgv[1]);
    if (!fs::exists(filepath)) {  // if file not exists
        perror("path");
        exit(EXIT_FAILURE);
    }

    lo_t* lineObj = new lo_t;
    fo_t* fileObj = new fo_t;
    so_t* statObj = new so_t;

    if (!strArgv[2].empty()) {
        Nprod = stoi(strArgv[2]);
        if (Nprod > 100)
            Nprod = 100;
        else if (Nprod == 0)
            Nprod = 1;
    } else {
        Nprod = 1;
    }
    lineObj->Nprod = Nprod;
    if (!strArgv[3].empty()) {
        Ncons = stoi(strArgv[3]);
        if (Ncons > 100)
            Ncons = 100;
        else if (Ncons == 0)
            Ncons = 1;
    } else {
        Ncons = 1;
    }

    /* create threads */
    thread dirS(dirSearch, fileObj, ref(filepath), ref(dirSRet));
    for (i = 0 ; i < Nprod ; i++)
        prod.emplace_back(thread(producer, fileObj, lineObj, ref(prodRet)));
    for (i = 0 ; i < Ncons ; i++)
        cons.emplace_back(thread(consumer, lineObj, statObj, ref(consRet)));

    printf("-------------------\n"
           "| main continuing |\n"
           "-------------------\n");

    unsigned long long consPrintLine = 0;
    for (i = 0 ; i < Ncons ; i++) {
        cons[i].join();
        printf("main) consumer_%d joined with %llu\n", i, consRet[i]);
        consPrintLine += consRet[i];
    }
    unsigned long long prodReadLine = 0;
    for (i = 0 ; i < Nprod ; i++) {
        prod[i].join();
        printf("main) producer_%d joined with %llu\n", i, prodRet[i]);
        prodReadLine += prodRet[i];
    }
    dirS.join();
    printf("main) dirSearch joined with %llu\n", dirSRet);


    printResult(statObj);
    delete fileObj;
    delete lineObj;
    delete statObj;
    auto programEnd = chrono::steady_clock::now();

    auto programTime = chrono::duration<double>(programEnd - programStart);
    printf("\nfilename(Dirname) : %s\n", argv[1]);
    printf("# of dirSearch searched files : %llu\n", dirSRet);
    printf("# of producer : %d\n", Nprod);
    printf("# of total producer read lines : %llu\n", prodReadLine);
    printf("# of consumer : %d\n", Ncons);
    printf("# of total consumer printed lines : %llu\n", consPrintLine);
    printf("Execution time : %.04lf seconds\n", programTime.count());
    exit(EXIT_SUCCESS);
}

void printResult(so_t* statArg) {
    so_t* so = statArg;

    // sum
    unsigned long long sum = 0;
    for (unsigned long long i : so->stat)
        sum += i;

    // print out distributions
    printf("\n*** print out distributions *** \n");
    printf("  #ch              freq\n");
    for (int i = 0; i < MAX_STRING_LENGTH; i++) {
        unsigned long long num_star = so->stat[i] * 80 / sum;
        if (i + 1 != 30)
            printf("[%4d]: %15llu \t", i + 1, so->stat[i]);
        else
            printf("[>=%2d]: %15llu \t", i + 1, so->stat[i]);
        for (int j = 0 ; j < num_star ; j++)
            printf("*");
        printf("\n");
    }
    printf("\n");

    printf("              A               B               C               D               E\n");
    printf("%15llu %15llu %15llu %15llu %15llu\n",
           so->stat2['A'] + so->stat2['a'], so->stat2['B'] + so->stat2['b'], so->stat2['C'] + so->stat2['c'],
           so->stat2['D'] + so->stat2['d'], so->stat2['E'] + so->stat2['e']);
    printf("\n");

    printf("              F               G               H               I               J\n");
    printf("%15llu %15llu %15llu %15llu %15llu\n",
           so->stat2['F'] + so->stat2['f'], so->stat2['G'] + so->stat2['g'], so->stat2['H'] + so->stat2['h'],
           so->stat2['I'] + so->stat2['i'], so->stat2['J'] + so->stat2['j']);
    printf("\n");

    printf("              K               L               M               N               O\n");
    printf("%15llu %15llu %15llu %15llu %15llu\n",
           so->stat2['K'] + so->stat2['k'], so->stat2['L'] + so->stat2['l'], so->stat2['M'] + so->stat2['m'],
           so->stat2['N'] + so->stat2['n'], so->stat2['O'] + so->stat2['o']);
    printf("\n");

    printf("              P               Q               R               S               T\n");
    printf("%15llu %15llu %15llu %15llu %15llu\n",
           so->stat2['P'] + so->stat2['p'], so->stat2['Q'] + so->stat2['q'], so->stat2['R'] + so->stat2['r'],
           so->stat2['S'] + so->stat2['s'], so->stat2['T'] + so->stat2['t']);
    printf("\n");

    printf("              U               V               W               X               Y               Z\n");
    printf("%15llu %15llu %15llu %15llu %15llu %15llu\n",
           so->stat2['U'] + so->stat2['u'], so->stat2['V'] + so->stat2['v'], so->stat2['W'] + so->stat2['w'],
           so->stat2['X'] + so->stat2['x'], so->stat2['Y'] + so->stat2['y'], so->stat2['Z'] + so->stat2['z']);

}

