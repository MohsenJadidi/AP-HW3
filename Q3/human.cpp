#include"human.h"
#include<iostream>

/* Constructor */
Human::Human(std::string f, std::string l, int h, int e, int a, bool g, int n)
{
    firstName = f;
    lastName = l;
    hairColor = h;
    eyeColor = e;
    age = a;
    gender = g;
    numberOfChildren = n;
    father = nullptr;
    mother = nullptr;
    spouse = nullptr; 
    childs = nullptr;
}

/* Desstructor */
Human::~Human()
{
	delete[] childs;
}

/* Operator = */
void Human::operator=(const Human& right_human)
{
	firstName = right_human.firstName;
	lastName = right_human.lastName;
	hairColor = right_human.hairColor;
	eyeColor = right_human.eyeColor;
	age = right_human.age;
	gender = right_human.gender;
	numberOfChildren = right_human.numberOfChildren;

	father = right_human.father;
	mother = right_human.mother;
	spouse = right_human.spouse;

	delete[] childs;
	childs = new Human*[this->numberOfChildren];

	for (int i{}; i < numberOfChildren; i++)
		childs[i] = right_human.childs[i];
}

/* Operator > for compring age of two humun */
bool Human::operator>(Human& right_human)
{
    return (age > right_human.getAge());
}

/* Operator == */
bool Human::operator==(Human& right_human)
{
    return(   firstName == right_human.getFirstName()
           && lastName == right_human.getLastName()
           && hairColor == right_human.getHairColor()
           && eyeColor == right_human.getEyeColor()
           && age == right_human.getAge()
           && gender == right_human.getGender()
           && numberOfChildren == right_human.getNumberOfChildren()
          );
}

/* Operator + , creat children*/
Human* Human::operator+(Human& right_human)
{
    srand((unsigned)time(NULL));

	if (this == right_human.spouse)
	{
        // Store children in p1 & p2
		Human** p1{ new Human*[numberOfChildren + 1] }; 
        Human** p2{ new Human*[right_human.numberOfChildren + 1] };

		for (int i{}; i < numberOfChildren; i++) {
			p1[i] = childs[i];
			p2[i] = right_human.childs[i];
		}

		delete[] childs;
		delete[] right_human.childs;

		numberOfChildren++;
        right_human.numberOfChildren++;
		//childs = new Human*[numberOfChildren];
		//right_human.childs = new Human*[right_human.numberOfChildren];

        Human* pChild{new Human {"UNKNOWN", "UNKNOWN", 0, 0, 0, 0, 0}};

        /* Set gender */
        if (rand() % 2 == 0)
			pChild->setGender(true);
		else
			pChild->setGender(false);

        /* Set hair color */
		if (rand() % 2 == 0)
			pChild->setHairColor(right_human.hairColor);
		else
			pChild->setHairColor(this->hairColor);

        /* Set eye color */
        if (rand() % 2 == 0)
			pChild->setEyeColor(right_human.eyeColor);
		else
			pChild->setEyeColor(this->eyeColor);

        /* Set last name */
		if (this->gender == false)
			pChild->setLastName(this->lastName);
		else
			pChild->setLastName(right_human.lastName);

        /* Set mothe & father of pChild */
        if (this->gender == true)
		{
			pChild->mother = this;
			pChild->father = &right_human;
		}
		else
		{
			pChild->mother = &right_human;
			pChild->father = this;
		}    


		//Adding newborn to the Children of the parents
		p1[numberOfChildren - 1] = pChild;
		p2[right_human.numberOfChildren - 1] = pChild;

        childs = p1;
		right_human.childs = p2;

        return pChild;
    }

    return nullptr;
}

/* Increase age*/
void Human::operator++(int)
{
    (this->age)++;
}

/* Increase age*/
void Human::operator++()
{
    (this->age)++;
}

/* Cheak this is child of input */
bool Human::isChildOf(Human* input)
{
    bool result{false};

	for (int i{}; i < input->numberOfChildren; i++)
	{
		if (this == (input->childs)[i])
			result = true;
	}
    
    return result;
}

/* Cheak this is father of input */
bool Human::isFatherOf(Human* input)
{
    return (this == input->father );
}

/* Cheak this is mother of input */
bool Human::isMotherOf(Human* input)
{
    return (this == input->mother );
}

/* Print list of children */
void Human::printChildren()
{
    std::cout << "The children of " << firstName << " are : \n";
	
    for (int i{}; i < numberOfChildren; i++) 
    {		
		std::cout << childs[i]->firstName << " " << childs[i]->lastName << std::endl;
	}
    
}


