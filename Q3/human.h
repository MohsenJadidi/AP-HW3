#ifndef HUMAN_H
#define HUMAN_H

#include<string>

class Human
{
private:
    std::string firstName;  //
    std::string lastName;
    int hairColor, eyeColor;
    int age;
    int numberOfChildren;
    bool gender;

public:
    Human(std::string, std::string, int=-1, int=-1, int=-1, bool=0, int=-1);// Constructor
    Human() = default;  // Default constructor
    ~Human();

    Human* father;
    Human* mother;
    Human* spouse;

    Human** childs;

    std::string getFirstName(){return firstName;};
    std::string getLastName(){return lastName;};
    bool getGender(){return gender;};
    int getHairColor(){return hairColor;};
    int getEyeColor(){return eyeColor;};
    int getAge(){return age;};
    int getNumberOfChildren(){return numberOfChildren;};
    
    void setFirstName(std::string name){firstName = name;};
    void setLastName(std::string name){lastName = name;};
    void setGender(bool g){gender = g;};
    void setHairColor(int c){hairColor = c;};
    void setEyeColor(int c){eyeColor = c;};

    /* Define operators */
	void operator=(const Human&);
    bool operator>(Human&);
    bool operator==(Human&);
    void operator++(int);
    void operator++();
    Human* operator+(Human&);

    bool isChildOf(Human*);
    bool isFatherOf(Human*);
    bool isMotherOf(Human*);

    void printChildren();

    void increaseNumberOfChildren(){numberOfChildren++;};


};

#endif