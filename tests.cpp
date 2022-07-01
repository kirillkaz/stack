#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>
#include <stack>
#include "stack.h"

void run_tests(){
    RUN_ALL_TESTS();
}

TEST(stack,stackTest){
    srand(time(0));
    int size = rand() % 900 + 100;

    stack<int> myStack;
    std::stack<int> systemStack;

    for(int i =0;i<size;i++){
        int num = rand()%10000;
        myStack.push(num);
        systemStack.push(num);
    }

    for(int i = 0;i<size;i++){
        EXPECT_EQ(myStack.pop(),systemStack.top());
        systemStack.pop();
    }
}