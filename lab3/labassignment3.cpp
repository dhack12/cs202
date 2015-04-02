#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct student{ 

	char first[10];
	char last[10];
	int age;
	double gpa;
};

bool loadstudents( student s[], char filename[]);
int lowestgpa( student s[]);
int highestgpa( student s[]);
double calculateaverage( student s[]);
void printstudent( student s[], int index);

int main()
{ 

	// initialize function/variables
	student s[10];
	char file[]= "students";
	bool test;
	double average;
	int lowIndex, highIndex;

	test = loadstudents( s, file);
	if(test == false)
		cout << "failed to upload file" <<endl<< endl;
	else{ 
		cout << "Students uploaded" <<endl <<endl;

		average = calculateaverage(s);
		
		lowIndex = lowestgpa( s );		
		cout << "Lowest grade: ";
		printstudent( s, lowIndex );

		highIndex = highestgpa( s);
		cout << "Highest grade: ";
		printstudent(s, highIndex);

		cout << "Class average: " << average<<endl<<endl;

	} 	
	

	return 0;
} 

bool loadstudents( student s[], char filename[])
{ 
	ifstream fin;
	int index = 0;

	fin.clear();
	fin.open(filename);
	
	if(!fin.good())
	return false;

	else{ 

	for( int i =0; i< 10; i++){ 
		fin >> s[i].first >> s[i].last >> s[i].age >> s[i].gpa;
		} 

	fin.close();

	return true;
	} 

} 

int lowestgpa( student s[])
{ 
	int index = 0;
	int answer = 0;
	for( index = 1; index < 9; index++){ 
		if( s[answer].gpa > s[index].gpa){ 
			answer = index;
		} 
	} 

	return answer;
} 

int highestgpa( student s[])
{ 
	int index = 0;
	int answer = 0;
	for( index = 1; index < 9; index++){ 
		if( s[answer].gpa < s[index].gpa){ 
			answer = index;
		} 
	} 

	return answer;

	return 0;
} 


double calculateaverage( student s[])
{ 
	int index;
	double sum;
	double average;

	for( index = 0; index<10;index++){ 
		sum += s[index].gpa;
		} 
	average = sum/index;

	return average;
} 


void printstudent( student s[], int index)
{ 

	cout << s[index].first << ' '; 
	cout << s[index].last << ' ';
	cout << s[index].age << ' ';
	cout << s[index].gpa << endl << endl;
} 






