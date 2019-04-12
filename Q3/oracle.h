#ifndef ORACLE_H
#define ORACLE_H

#include<string>
#include"human.h"

class Oracle : public Human
{
private:
    std::string Name;

public:
    Oracle(std::string);

    bool marry(Human*, Human*);
	void setChild(Human*, Human*, Human*);

};

#endif

