#pragma once

#include <exception>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <vector>

using void_pointer = void*;
using size_type = std::size_t;
using difference_type = std::ptrdiff_t;
using propagate_on_container_move_assignment = std::true_type;
using is_always_equal = std::true_type;

struct Page {
    size_t blockSize;
    bool isFree;
};

class TwinAllocator {
    private:
        std::vector<std::vector<Page*>> freeLists;
        size_t maxSize;

        Page* getBuddy(Page*);
        void removeBlock(Page*);
    
    public:
        TwinAllocator() = delete;
        TwinAllocator(size_t);

        virtual ~TwinAllocator();

        void_pointer alloc(size_type);
        void free(void_pointer);
};