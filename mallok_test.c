//Wesley Stahl
//7/31/2017
//TCSS 333 Assignment 6
//Time Spent: About 3hrs
//Test code that checks multiple test cases for allocating 1000 bytes of memory.

#include "mallok.h"
#define num 5
#define NUM 1000

/** Perfroms the first test of allocating 10 bytes a number of times **/
void test1(int count) {
  create_pool(NUM);
  int *i;
  for(; (int *)my_malloc(10) != 0; count++);
  printf("Memory allocated %d times.", count);
}

/** Perfroms the second test of making sure memory can be freed **/
void test2(int val, int val2, int val3) {
  int *test2[num];  
  create_pool(NUM);
  for(val2 = 0; val2 < num; val2++) {
    for(val = 0; val < num; val++){
      test2[val] = my_malloc(200);  
      printf("Memory is allocated! %d\n", test2[val]);          
    }
    printf("\n");
    for(val3 = 0; val3 < num; val3++){    
      my_free(test2[val3]);
      printf("Memory is freed! %d\n",test2[val3]);
    }    
    printf("\n");
  }
}

/** Runs the third test to make sure we can't allocate more memory than we have available **/
void test3(int val) {
  int *test3[num];
  create_pool(NUM);
  for(val = 0; val < num; val++){
    test3[val] = my_malloc(200);
    printf("Memory allocated to %d\n",test3[val]);
  }  
  my_free(test3[2]);   
  printf("\nFreed third position for memory reallocation.\n\n");
  test3[2] = my_malloc(210);
  if (test3[2] == 0) {
    printf("Failed to allocate 210 bytes to the third position. Not enough memory space.\n");
  } else {
    printf("Allocated 210 bytes. Starts at: %d\n", test3[2]);
  }
  test3[2] = my_malloc(150);
  if (test3[2] == 0) {
    printf("Failed to allocate 150 bytes to the third position. Not enough memory space.\n");
  } else {
    printf("Allocated 150 bytes. Starts at: %d\n",test3[2]);
  }
  test3[2] = my_malloc(60);
  if (test3[2] == 0) {
    printf("Failed to allocate 60 bytes to the third position. Not enough memory space.\n");
  } else {
    printf("Allocated 60 bytes. Starts at: %d\n", test3[2]);
  }
  test3[2] = my_malloc(50);
  if (test3[2] == 0) {
    printf("Failed to allocate 50 bytes to the third position. Not enough memory space.\n");
  } else {
    printf("Allocated 50 bytes. Starts at:  %d\n", test3[2]);
  }
  for (val = 0; val < num; val++) {
    my_free(test3[val]);
  }
}

/** Runs test4, which creates 5 200 byte blocks, and fills each block with characters, starting at 'A' and ending at 'B' **/
void test4(int val, int val2, char ch) {
  char *test4[num];
  char *test, *tests;
  create_pool(NUM);      
  for(val = 0; val < num; val++){
    test4[val] = my_malloc(200);
  }
  for (val2 = 0; val2 < num; val2++) {   
    test = test4[val2];     
    for(val = 0; val < 200; val++) {
      test[val] = ch;
    }
    ch++; 
  }
  printf("\n");
  tests = test4[0];
  val = 0;
  for (val2 = 0; val2 < 5; val2++) {
    for(; val < 200 *(val2+1); val++) {
      printf("%c", tests[val]);   
    }
    printf("\n");
  }
}

/** Perfroms test 5, which is supposed to allocate memory blocks at size 250, free those blocks, and reallocate with size 100 byte blocks **/
void test5(int val) {
  int *test5[10];
  create_pool(NUM);
  test5[0] = my_malloc(NUM);
  printf("1000 bytes allocated to memory starting at: %d\n", test5[0]);
  my_free(test5[0]);
  printf("\n");
  for(val = 0; val < 4; val++){
    test5[val] = my_malloc(250);
    printf("Memory allocated to %d\n", test5[val]);
  }
  for(val = 0; val < 4; val++){
    my_free(test5[val]);
  }
  printf("\n");
  for(val = 0; val < (num * 2); val++){
    test5[val] = my_malloc(100);
    printf("Memory reallocated to %d\n", test5[val]);
  }
  for(val = 0; val < (num * 2); val++){
    my_free(test5[val]);
  }
} 

int main(void) {
  int val, val2, val3, count = 0;  
  char ch = 'A';
  printf("\n****************************START OF TESTING****************************\n\nTEST 1: \n\n");
  test1(count);
  printf("\n\n************************************************************************\n\n");
  printf("TEST 2:\n\n");
  test2(val, val2, val3);
  printf("\n****************************************************************************\n\n");
  printf("TEST 3: \n\n");
  test3(val);
  printf("\n****************************************************************************\n\n");
  printf("TEST 4: \n");
  test4(val, val2, ch);
  printf("\n\n**************************************************************************\n\n");
  printf("TEST 5: \n\n");
  test5(val);
  printf("\n\n*****************************END OF TESTING*****************************\n\n");
  return 1;
}

