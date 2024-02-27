#include "include/TwinAllocator.hpp"

TwinAllocator::TwinAllocator(size_t totalMemorySize) {
    maxSize = totalMemorySize;
    size_t numLevels = static_cast<size_t>(std::log2(totalMemorySize));
    freeLists.resize(numLevels + 1);
    freeLists[numLevels].push_back(new Page{maxSize, true});
}

TwinAllocator::~TwinAllocator() {
    for (auto &list : freeLists) {
        for (Page* block : list) {
            delete block;
        }
    }
}

Page* TwinAllocator::getBuddy(Page* block) {
    size_t buddyAddress = reinterpret_cast<size_t>(block) ^ block->blockSize;
    return reinterpret_cast<Page*>(buddyAddress);
}

void TwinAllocator::removeBlock(Page* block) {
    size_t level = static_cast<size_t>(std::log2(block->blockSize));
    auto it = std::find(freeLists[level].begin(), freeLists[level].end(), block);
    if (it != freeLists.end()) {
        freeLists[level].erase(it);
    }
}

void_pointer TwinAllocator::alloc(size_t size) {
    size_t level = static_cast<size_t>(std::log2(size));
    while (level < freeLists.size() && freeLists[level].empty()) {
        ++level;
    }
    if (level == freeLists.size()) {
        return nullptr;
    }

    Page* block = freeLists[level].front();
    freeLists[level].erase(freeLists[level].begin());
    while (block->blockSize > size) {
        Page* buddy = new Page{block->blockSize / 2, true};
        block->blockSize -= buddy->blockSize;

        size_t buddyLevel = static_cast<size_t>(std::log2(buddy->blockSize));
        freeLists[buddyLevel].push_back(buddy);
    }
    block->isFree = false;
    return block;
}

void TwinAllocator::free(void_pointer block) {
    Page* page = reinterpret_cast<Page*>(block);

    size_t level = static_cast<size_t>(std::log2(page->blockSize));
    page->isFree = true;
    while (level < freeLists.size() - 1) {
        Page* buddy = getBuddy(page);
        if (buddy != nullptr && buddy->isFree && buddy->blockSize == page->blockSize) {
            removeBlock(page);
            removeBlock(buddy);

            page->blockSize += buddy->blockSize;
            delete buddy;
        } else {
            break;
        }
        ++level;
    }
    freeLists[level].push_back(page);
}