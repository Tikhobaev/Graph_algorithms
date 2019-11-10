cmake_minimum_required(VERSION 3.14)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structures main.cpp Stack_Queue_List/sList.h Stack_Queue_List/dList.h Stack_Queue_List/rList.h Stack_Queue_List/Stack.h Stack_Queue_List/LStack.h Stack_Queue_List/Queue.h Stack_Queue_List/LQueue.h Graph/Node.h Graph/Graph.h Graph/Graph.cpp Graph/DSet.cpp Graph/DSet.h)