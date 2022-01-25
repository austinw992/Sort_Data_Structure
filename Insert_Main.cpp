#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <sys/time.h>



#define MAX 100000

/*


GENERATE RANDOM NUMBERS TO BE SORTED THROUGH THE METHOD OF INSERTION SORT
*/

int counter = 0;

//insertion sort of the array
void insert_sort(int node_array[], int a_size){
    int c;
    int d;
    int e;

    //loops through the size of the array to be sorted
    for (c = 1; c < a_size; c++){
        d = node_array[c];
        e = c - 1;

        //based on the position index of the array, sorting can begin
        while ( e >= 0 && node_array[e] > d){
            node_array[e + 1] = node_array[e];
            e = e - 1;
            counter++;

        }
        node_array [e + 1] = d;
        counter++;

    }
}

//print the values of the array
void print_Values(int node_array[], int a_size){
    int i;

    //loops based on the size of the array
    for (i = 0; i < a_size; i++) {

        //prints out the values in the array
        std::cout << node_array[i] << " ";
    }
}//end of printValues function


int main(){

     int User_Input;
    std::cout << "Enter the size of numbers you would like to sort ";
    std::cin >> User_Input;
    //std::cin.ignore();

    //creates an empty array to be filled with random numbers
    int node_array[User_Input];
    srand(time(0));
    for (int i = 0; i < User_Input; i++){

        node_array[i] = (rand() % 400);
        //std::cout << node_array[i];

    }
    //int a[User_Input];
    //determines the size of the arrray
    int a_size = sizeof(node_array)/sizeof(node_array[0]);

    //int a[User_Input];
    
    //struct timeval start, end;

    std::cout<< "UNSORTED: ";
    std::cout << "[";
    print_Values(node_array, a_size);
    std::cout << "]";

    //gettimeofday(&start, NULL);
    //std::ios_base::sync_with_stdio(false);
    clock_t start = clock();

    insert_sort(node_array, a_size);

    //gettimeofday(&end, NULL);
    clock_t end = clock();

    std::cout << "\n";
    std::cout << "SORTED: ";
    std::cout << "[";
    print_Values(node_array, a_size);
    std::cout << "]" << std::endl;
    
    /* double time_ran;
    time_ran = (end.tv_sec - start.tv_sec) * 1e6;
    time_ran = (time_run + (end.tv_sec - start.tv_sec)) * 1e6; */
    double time_ran = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time ran for the program is: " << std::fixed << time_ran << std::setprecision(6);
    std::cout << "seconds" << std::endl;
    

    std::cout << "This is the number of steps: " << counter << std::endl;


    return (0);

    
    
    
}//end of main function

/* for (int i = 0; i < MAX; ++i){
        a[i] = rand() % 400;

    }
    for(int i = 0; i<MAX; ++i){
        std::cout <<a[i] << "\n";
    }

    //printValues(a, a_size);
    void random_numGen(int User_Input){
    int i;

    for (int i = 0; i < User_Input; ++i){
        a[i] = rand() % 400;

    }
} */

/* void swap(int *small, int *large){
    int temp;
    temp = *small;
    *small = *large;
    *large = temp;
}//end of swap function */