#pragma once

template<typename T>
class Watcher{
 public:
    virtual void update(T info) = 0;
};
