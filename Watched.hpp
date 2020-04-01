#pragma once
#include <list>
#include "Watcher.hpp"

template <typename T>
class Watched {
 private :
    std::list<Watcher <T> *> watcher_list_;
 public :
    void notif_watchers(T info) {
        for (auto obs : this->watcher_list_) obs->update(info);
    }
    void add_watcher(Watcher<T>* watcher) {
        this->watcher_list_.push_back(watcher);
    }
};
