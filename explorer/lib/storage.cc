#include "explorer/storage.h"

#include "miner/common/miner.h"

using namespace explorer;

InMemoryStorage::InMemoryStorage() : explored_() {}

std::optional<miner::common::WorkItem> InMemoryStorage::get(const miner::common::Coordinate &coord) const {
    auto item = explored_.find(coord);
    if (item == explored_.end()) {
        return {};
    }
    return item->second;
}

void InMemoryStorage::store(miner::common::WorkItem item) {
    auto coord = miner::common::Coordinate(item.x, item.y);
    explored_[coord] = item;
}