#ifndef ISTEPPABLE_H_INCLUDED
#define ISTEPPABLE_H_INCLUDED

struct ISteppable {
    virtual void step(int elapsed) = 0;
};

#endif // ISTEPPABLE_H_INCLUDED
