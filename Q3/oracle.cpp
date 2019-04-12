#include"oracle.h"
#include<iostream>

/* Constructor */
Oracle::Oracle(std::string name) : Human{"", "", 0, 0, 0, 0, 0}
{
    this->Name = name;
}

bool Oracle::marry(Human* p1, Human* p2)
{
    std::cout << p1->getLastName() << " and " << p2->getLastName() << " Married! \n"; 
    if( (p1->getAge() >= 18) && (p2->getAge() >= 18) )
        if( (p1->spouse == nullptr)  && (p2->spouse == nullptr) )
        {
    		p1->spouse = p2;
		    p2->spouse = p1;
		    return true;
        }

    return false;
}

void Oracle::setChild(Human* pChild, Human* pMother, Human* pFather)
{
    pChild->father = pFather;
    pChild->mother = pMother;

    if (pMother->childs != nullptr && pFather->childs != nullptr)
	{
        // Store children in p1 & p2
        Human** p1{ new Human*[pMother->getNumberOfChildren() + 1] }; 
        Human** p2{ new Human*[pFather->getNumberOfChildren() + 1] };

        for (int i{}; i < pMother->getNumberOfChildren(); i++) 
        {
            p1[i] = pMother->childs[i];
        }

        for (int i{}; i < pFather->getNumberOfChildren(); i++) 
        {
            p2[i] = pFather->childs[i];
        }

        delete[] pMother->childs;
        delete[] pFather->childs;

        pMother->increaseNumberOfChildren();
        pFather->increaseNumberOfChildren();
        
        p1[pMother->getNumberOfChildren() - 1] = pChild;
        p2[pFather->getNumberOfChildren() - 1] = pChild;

        pMother->childs = p1;
        pFather->childs = p2;

        pMother->spouse = pFather;
        pFather->spouse = pMother;
    }
    else
    {
        pMother->childs = new Human*;
		pFather->childs = new Human*;

		pMother->childs[0] = pChild;
		pFather->childs[0] = pChild;

		pMother->spouse = pFather;
		pFather->spouse = pMother;
    }
    
}