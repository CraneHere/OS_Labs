#include "FBLAllocator.hpp"

FBLAllocator::FBLAllocator(void_pointer realMemory, size_type memorySize)
{
    freeBlocksList = reinterpret_cast<BlockHeader*>(realMemory + sizeof(FBLAllocator));
    freeBlocksList->size = memorySize - sizeof(FBLAllocator) - sizeof(BlockHeader);
    freeBlocksList->next = nullptr;
}

FBLAllocator::~FBLAllocator()
{
    BlockHeader* curBlock = this->freeBlocksList;

    while (curBlock) {
        BlockHeader* toDelete = curBlock;
        curBlock = curBlock->next;
        toDelete = nullptr;
    }

    this->freeBlocksList = nullptr;
}

void_pointer FBLAllocator::alloc(size_type newBlockSize)
{
    BlockHeader* prevBlock = nullptr;
    BlockHeader* curBlock = this->freeBlocksList;

    
}