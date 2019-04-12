#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
#include <ctime>
#define N 1000000000

int main(int argc,char** argv) {
    using std::cout;
    using std::cin;
    using std::endl;

    long long int num_in_cycle=0;
    clock_t start_time,end_time;
    int thread_count;
    thread_count=strtol(argv[1],NULL,10);
    srand(time(NULL));
    double x,y,distance_point;
    long long int i;
    start_time=clock();
    #pragma omp parallel for num_threads(thread_count) default(none) \
    reduction(+:num_in_cycle) private(i,x,y,distance_point)
    for (i = 0; i < N; i++) {
        x = (double) rand() / (double) RAND_MAX;
        y = (double) rand() / (double) RAND_MAX;
        distance_point = x * x + y * y;
        if (distance_point <= 1) {
            num_in_cycle++;
        }
    }
    end_time=clock();
    double estimate_pi=(double)num_in_cycle/N*4;
    cout <<"the estimate value of pi is "<< estimate_pi <<endl;
    cout <<"Time consumption is "<< (double)(end_time-start_time)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}