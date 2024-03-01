#pragma once

#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>

using void_pointer = void*;
using size_type = std::size_t;
using difference_type = std::ptrdiff_t;
using propagate_on_container_move_assignment = std::true_type;
using is_always_equal = std::true_type;

namespace fb_alloc {

struct BlockHeader {
    size_t _size;
    BlockHeader* _next;
};

class Allocator{
  private:
    BlockHeader* _free_blocks_list;

  public:
    Allocator() = delete;
    Allocator(size_t);

    virtual ~Allocator();

    void* Alloc(size_t blockSize);
    void Free(void *block);
};

}
