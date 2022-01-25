#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <sys/time.h>



#define MAX 100000


/*
used to analyze recursive routines



GENERATE RANDOM NUMBERS TO BE SORTED THROUGH THE METHOD OF MERGE SORT
*/

int counter = 0;

//the function will split the array into two subarrays in order to perform a merge sort
void array_merge(int node_array[], int temp_array[], int left_side, int middle_side, int right_side){

    //in order for a merge to be performed there needs to be two subarrays
    // first half represents one subarray left to the middle
    // second half represents the second subarray right to the middle

    //int first_half1 = middle_side - left_side + 1;
    //int second_half2 = right_side - middle_side;
    

    int first_half1 = middle_side - 1;
    int second_half2 = left_side;
    int elements = right_side - left_side +1;

     //merge the two arrays together
    while (left_side <= first_half1 && middle_side){

        if(node_array[left_side] <= node_array[middle_side]){

            temp_array[ second_half2++] = std::move( node_array[left_side++]);
            counter++;

        }else{

            temp_array[ second_half2++] = std::move( node_array[middle_side++]);
            counter++;

        }//end of if statements

        //transfer the left side of the array
        while(left_side <= first_half1){

            temp_array[ second_half2++] = std::move( node_array[ left_side++]);
            counter++;

        }

        //transfer the right half of the array
        while(middle_side <= right_side){

            temp_array[ second_half2++] = std::move(node_array[middle_side++]);
            counter++;

        }

        //copy the array stored in the temp into the true array
        for(int copy = 0; copy < elements; copy++, --right_side){

            node_array[right_side] = std::move(temp_array[right_side]);
            counter++;

        }//end of for loop

    }

    //creates temporary arrays to be used to store values from the random number generated array
    //the first array will provide the first half of values
    //the second array will provide the second half of values
    //int first_array[first_half1];
    //int second_array[second_half2];



   /* for (int first_subA = 0; first_subA < first_half1; first_subA++){
        
        //copying values into the first sub array from the left side
        first_array[first_subA] = node_array[left_side + first_subA];
        counter++;

    }//end of for loop for first subA

    for (int second_subA = 0; second_subA < second_half2; second_subA++){

        //copying values into the first sub array from the right side
        second_array[second_subA] = node_array[second_half2 + middle_side + 1];
        counter++;

    }//end of for loop for second subA*/

    /* int first_subA = 0;
    int second_subA = 0;
    int merge_subA = left_side; */

    //merges the two sub arrays back into one array
   /*  do{
        if (first_array[first_half1] <= second_array[second_half2]){
            node_array[merge_subA] = first_array[first_half1];
            first_subA++;
        }
        else {
            node_array[merge_subA] = second_array[second_half2];
            second_subA++;
        }
    }
    while(first_subA < first_half1 && second_subA < second_half2); */
    /*
    while(first_subA <= first_half1 && second_subA <= second_half2){

        if (first_array[first_half1] <= second_array[second_half2]){

            node_array[merge_subA++] = std::move(first_array[first_half1++]);
            first_subA++;
            counter++;

        }
        else {

            node_array[merge_subA++] = std::move(second_array[second_half2++]);
            second_subA++;
            counter++;

        }
    }*/


    //to double check the reminding values in the sub array for any values that 
    //didnt get added into the one array


    //checking one of the subarray
  /*   do{
        node_array[merge_subA] = second_array[second_subA];
        second_subA++;
        merge_subA++;
    }
    while(second_subA < second_half2); */
   /*  while(first_subA <= first_half1){

        node_array[merge_subA++] = std::move(first_array[first_subA++]);

        //first_subA++;
        //merge_subA++;
        counter++;

    }
 */
    //checking one of the subarray
   /*  do{
        node_array[merge_subA] = first_array[first_subA];
        first_subA++;
        merge_subA++;
    }
    while(first_subA < first_half1); */
    /* while(second_subA <= second_half2){

        node_array[merge_subA++] = std::move(second_array[second_subA++]);

        //second_subA++;
        //merge_subA++;
        counter++;

    } */

}//end of merging the arrays together after splitting it in half


void merge_sort(int node_array[], int temp_array[], int left_side, int right_side){
    //begin sorting of the array based on the right and left side
    
    //an if statement to compare the two sides based on size
    if (left_side < right_side){

        //combine the sorting of the left side and right side
        int merge_LR = (left_side + right_side) / 2;


        //sort based on the left to the middle within the array
        merge_sort(node_array, temp_array, left_side, merge_LR);


        //sort based on the right to the middle within the array
        merge_sort(node_array, temp_array, merge_LR + 1, right_side);


        //combine the two subarrays into one sorted array
        array_merge(node_array, temp_array, left_side, merge_LR + 1, right_side);

        counter++;

        

    }


    

}//end of merge sort

//prints the values
void print_Values(int node_array1[], int a_size){
    //int i;

    //loops based on the size of the array
    for (int i = 0; i < a_size; i++) {

        //prints out the values in the array
        std::cout << node_array1[i] << " ";
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

    int temp_array[User_Input];
    //int a[User_Input];
    
    //struct timeval start, end;

    std::cout<< "UNSORTED: ";
    std::cout << "[";
    print_Values(node_array, a_size);
    std::cout << "]";

    //gettimeofday(&start, NULL);
    //std::ios_base::sync_with_stdio(false);
    clock_t start = clock();

    merge_sort(node_array, temp_array, 0, a_size - 1);

    //gettimeofday(&end, NULL);
    clock_t end = clock();

    std::cout << "\n";
    std::cout << "SORTED: ";
    std::cout << "[";
    print_Values(node_array, a_size);
    std::cout << "]" << std::endl;
    
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
void swap(int*, int*); */


/* int i;
int x; */

/* int random_numGen(int User_Input){
    int i;
    int node_array1[User_Input];

    int node_array = node_array1[User_Input];
    for (int i = 0; i < User_Input; ++i){
        node_array1[User_Input] = rand() % 400;

    }
    return node_array;
} */

/* void swap(int *small, int *large){
    int temp;
    temp = *small;
    *small = *large;
    *large = temp;
}//end of swap function */