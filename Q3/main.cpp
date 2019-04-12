#include<iostream>
#include"human.h"
#include"oracle.h"

int main()
{
    Human* p1{ new Human{ "ALI", "BAHADORI", 4, 3, 25, 0, 0 } };
	Human* p2{ new Human{ "BAHAR", "SHAMS", 1, 2, 22, 1, 0 } };
    std::cout << p1->getLastName() << "\n";


    std::cout << (p1==p2) << std::endl ;

    std::cout << p1->getAge() << std::endl;
    ++(*p1);
    std::cout << p1->getAge() << std::endl;

    Oracle o1{"SHERVIN"};

	//married couple
	o1.marry(p1, p2);

	//creating new person
	Human* p3{ *p1 + *p2 };

	//setting the firstname of newborn
	if (p3->getGender())
		p3->setFirstName("MAHSHID");
	else
		p3->setFirstName("FARSHID");


    //increasing the age of newborn
	(*p3)++;

	p1->printChildren();

	Human* p4{ new Human{ "SHAHIN", "REZAEE", 0, 5, 58, 1, 1 } };
	Human* p5{ new Human{ "FARHAD", "BAHADORI", 0, 6, 63, 0, 1 } };

    o1.setChild(p1, p4, p5);

    return 0;
}