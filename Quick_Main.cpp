#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <sys/time.h>




#define MAX 100000

/* 
quick sort is the fastest sorting algorithm
uses a system called pivot.
when the array is small, the run time is slower

GENERATE RANDOM NUMBERS TO BE SORTED THROUGH THE METHOD OF QUICK SORT
*/


int counter = 0;

//swaps the value that it was being compared with in the position function
void swap(int *small, int *large){

    //create a temp storage memory
    int temp;

    temp = *small;
    *small = *large;
    *large = temp;

    counter++;

}//end of swap function

//checks the position of the array and uses a pivot to swap
//just separates the large values from the small values but is not sorted yet
int position (int node_array[], int small_Value, int large_Value){

    int rotation = node_array[large_Value];
    int a = (small_Value - 1);

    //if the value is smaller than the large value then swap
    for (int b = small_Value; b <= large_Value - 1; b++){

        if (node_array[b] < rotation){
            a++;
            swap(&node_array[a], &node_array[b]);
            counter++;
        }
        counter++;
    }
    swap(&node_array[a + 1], &node_array[large_Value]);
    counter++;
    return (a + 1);


}

//sorts the values in the array after the 
//values that are small on one side and the large values on the otherside
void quick_sort(int node_array[], int small_Value, int large_Value){
    
    if (small_Value < large_Value){

        int correct_position = position(node_array, small_Value, large_Value);

        quick_sort(node_array, small_Value, correct_position - 1);
        quick_sort(node_array, correct_position + 1, large_Value);
        counter++;
    }
}


//prints the values from the sort
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
        

        node_array[i] = (rand()%400);
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

    quick_sort(node_array, 0, a_size-1);

    //gettimeofday(&end, NULL);
    clock_t end = clock();

    
    std::cout << "\n";
    std::cout << "SORTED: ";
    std::cout << "[";
    print_Values(node_array, a_size);
    std::cout << "]";
    std::cout << " " << std::endl;

    /* double time_ran;
    time_ran = (end.tv_sec - start.tv_sec) * 1e6;
    time_ran = (time_ran + (end.tv_sec - start.tv_sec)) * 1e6; */

    double time_ran = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time ran for the program is: " << std::fixed << time_ran << std::setprecision(6);
    std::cout << "seconds" << std::endl;

    std::cout << "This is the number of steps: " << counter << std::endl;

    
    return (0);
    
}//end of main function

/* void print_Values();
void sort();
void swap(int*, int*);
int i;
int x;
void random_numGen(int User_Input){
    int i;
    for (int i = 0; i < User_Input; ++i){
        a[i] = rand() % 400;
    }
} */