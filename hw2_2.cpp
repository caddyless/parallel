#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"
#include <random>
#define N 1000000

void random_init(int* s){
    for(int i=0;i<N;i++){
        *(s+1)=rand();
    }
}

void validate(int* s){
    for(int i=0;i<(N-1);i++){
        if(*(s+i)>*(s+i+1)){
            printf("error!");
            return;
        }
    }
    printf("correct!");
}

void sort_row(int* s, int row, int order){
    int num,temp;
    int *start;
    num = N / 1000;
    start=s+row*num;
    for(int i=0;i<num;i++){
        for(int j=(i+1);j<num;j++){
            if(*(start+i)>*(start+j) && order==1){
                temp=*(start+j);
                *(start+j)=*(start+i);
                *(start+i)=temp;
            }
            else if(*(start+i)<*(start+j) && order==2){
                temp=*(start+j);
                *(start+j)=*(start+i);
                *(start+i)=temp;
            }
        }
    }
}

void sort_column(int* s, int column){
    int num,temp;
    int *start;
    num = N / 1000;
    start=s+column;
    for(int i=0;i<num;i++){
        for(int j=(i+1);j<num;j++){
            if(*(start+num*i)>*(start+num*j)){
                temp=*(start+num*j);
                *(start+j)=*(start+i);
                *(start+i)=temp;
            }
        }
    }
}

int main(int argc,char** argv){
    int s[N],thread_count;
    random_init(s);
    validate(s);
    thread_count=strtol(argv[1],NULL,10);
#pragma omp parallel for nums_threads(thread_count)

}
