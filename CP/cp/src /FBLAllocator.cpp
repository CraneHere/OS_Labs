#include "include/FBLAllocator.hpp"

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

    size_type adjustedSize = newBlockSize + sizeof(BlockHeader);

    while (curBlock) {
        if (curBlock->size >= adjustedSize) {
            if (curBlock->size >= adjustedSize + sizeof(BlockHeader)) {
                BlockHeader* newBlock = reinterpret_cast<BlockHeader*>(reinterpret_cast<int8_t*>(curBlock) + adjustedSize);

                newBlock->size = curBlock->size - adjustedSize - sizeof(BlockHeader);
                newBlock->next = curBlock->next;
                curBlock->next = newBlock;
                curBlock->size = adjustedSize;
            }

            if (prevBlock) {
                prevBlock->next = curBlock->next;
            } else {
                this->freeBlocksList = curBlock->next;
            }

            return reinterpret_cast<int8_t*>(curBlock) + sizeof(BlockHeader);
        }

        prevBlock = curBlock;
        curBlock = curBlock->next;
    }

    return nullptr;
}

void FBLAllocator::free(void_pointer block) {
    if (block == nullptr) return;

    BlockHeader* header = reinterpret_cast<BlockHeader*>(static_cast<int8_t*>(block) - sizeof(BlockHeader));
    header->next = this->freeBlocksList;
    this->freeBlocksList = header;
}