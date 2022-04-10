//
// Created by ypinhas on 4/9/2022.
//

#ifndef VIRUSMUTATIONSIMULATION_RCOBJECT_H
#define VIRUSMUTATIONSIMULATION_RCOBJECT_H


class RCObject {
private:
    int refCount;
protected:
    RCObject(): refCount(0){}
    RCObject(const RCObject&):refCount(0){}
    RCObject& operator=(const RCObject&) {return *this;}
    virtual ~RCObject()=0;
public:
    void addReference(){++refCount;}
    void removeReference(){if(--refCount==0) delete this;}
    bool isShared() const {return refCount>1;}
};


#endif //VIRUSMUTATIONSIMULATION_RCOBJECT_H
