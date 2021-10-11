/*Ex1 devoir4 CSI2772A*/

#include <iostream> 
#include "myFile1a.h"
#include "myFile1b.h"
using namespace std;

//  definitions pour la classe Course.
Course::Course(int num, int hours){
    this->num = num;
    this->hours = hours;
}
int Course::getNum(){
    return this->num;
}
int Course::getHours(){
    return this->hours;
}

// definitions pour la classe Student
Student::Student(int numID, int maxCourses){
    this->numID      = numID;
    this->maxCourses = maxCourses;
    this->nbCourses  = 0;
    this->List_grades = new int[maxCourses];
    this->List_courses =  new Course* [maxCourses];
}

Student::~Student(){
    delete List_grades;
    delete List_courses;
}

double Student::average(){
    double average = 0;
    for(int i = 0; i < this->nbCourses; i++){
        average += this->List_grades[i];
    }
    average /= this->nbCourses;

    return average;
}

int Student::totalHours(){
    Course* course; 
    int totalHours = 0;
    for(int i = 0; i < this->nbCourses; i++){
        course =  this->List_courses[i];
        totalHours += course->getHours();
    }
    return totalHours;
}

bool Student::addCourse(Course* course, int grade){

    if(this->nbCourses >= this->maxCourses) // nbre maximal de cours dépassé
        return false;
    else{
       // utilisation de la variable nbCourses comme ID 
       this->List_grades[nbCourses] = grade;
       this->List_courses[nbCourses++] = new Course(course->getNum(), course->getHours());
    }

    return true;
}

int main() {
	Course* Math = new Course(100, 60);
	Course* ITI = new Course(200, 120);
	Student* Yan = new Student(1, 35);
	Student* Jane = new Student(2, 35);
	Yan->addCourse(Math, 15);
	Yan->addCourse(ITI, 12);
	Jane->addCourse(Math, 11);
	Jane->addCourse(ITI, 16);
	cout << "The total hours of Yan is " << Yan->totalHours() << endl;
	cout << "The average of Yan is " << Yan->average() << endl;
	cout << "The total hours of Jane is " << Jane->totalHours() << endl;
	cout << " The average of Jane is " << Jane->average() << endl;
	delete Math;
	delete ITI;
	delete Yan;
	delete Jane;
	cout << " Enter a number to exit..." << endl;
	return 0;
}