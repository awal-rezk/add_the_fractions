using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

class Breakfast{
	private:
		
	public:
		Breakfast();
		void removeMenu(int itemArray);//remove from menu
		int itemArray[3];
		void searchMenu(string item);//look for specific item a customer has a problem with
		string breakfastItems[3][3];//first bracket is for items, second bracket is for key ingredients
	protected:
	
};

class Lunch{
	private:
	public:
		Lunch();
		void setListOfItems(string list[]);
		void removeMenu(int itemArray);//remove from menu
		int itemArray[3];
		void searchMenu(string item);//look for specific item a customer has a problem with
		string lunchItems[3][3];//first bracket is for items, second bracket is for key ingredients
	protected:
	
};

class Sides{
	private:
	public:
		Sides();
		void setListOfItems(string list[]);
		void removeMenu(int itemArray);//remove from menu
		int itemArray[3];
		void searchMenu(string item);//look for specific item a customer has a problem with
		string sides[3][3];//first bracket is for items, second bracket is for key ingredients
	protected:
	
};


int main(){
	ofstream outFile;
	
	outFile.open("personalMenu.txt");
	
	if(!outFile.is_open()){
		cout << "File not found.\n";
		return 0;
	}
	
	Breakfast b;
	Lunch l;
	Sides s;
	
	//dietary restrictions
	string cantEat;
	
	//foods customer doesn't like
	string dontLike;
	
	srand(time(NULL));
	
	//generate random time in the day
	int randHour = (rand() % 24) + 1; //generate random hour (military time)
	int randMinutes = (rand() % 60) + 1;//generate random minute 
	
	if(randMinutes < 10){//so digits between 0 and 10 can be displayed as '0<digit>'
		string one = to_string(randMinutes);
		string two = to_string(0);
		
		string three = one + two;
		randMinutes = stoi(three);
	}
	
	
	if((randHour < 6) || (randHour > 21)){//before 6 am and after 9 pm (21h)
		cout << "Sorry, Burger King is not open for service at this time \n";
		return 0;
	}
	
	cout << "Hello! Welcome to Burger King!!  Since you're a new customer, I will try to narrow down your menu choices by asking some questions first \n";
		
	
	cout << "Alright, do you have any dietary restrictions? Or in other words, are there any ingredients or foods you cannot eat? \n";
	getline(cin, cantEat);
	if(cantEat.compare("no") != 0|| cantEat.compare("No") != 0){
		b.searchMenu(cantEat);
		l.searchMenu(cantEat);
		s.searchMenu(cantEat);
	}
	
	cout << "Okay.  Are there any foods you don't like? \n";
	getline(cin, dontLike);
	if(dontLike.compare("no") != 0|| dontLike.compare("No") != 0){
		b.searchMenu(dontLike);
		l.searchMenu(dontLike);
		s.searchMenu(dontLike);
	}
	
	
	if(randHour > 10){//past 10 am
		cout << "Great.  Since it is " << randHour << ":" << randMinutes << ", we will not be able to serve you Breakfast.  Here is your Menu:\n";
		for(int i = 0; i < 3; i++){
			b.itemArray[i] = 0;//indicates to delete all breakfast items from menu --> better way to do this?
		}
	}else if(randHour < 10){//before 10 am
		cout << "Great.  Since it is " << randHour << ":" << randMinutes << ", we will not be able to serve you neither Lunch nor Sides. Here is your Menu:\n";
		for(int i = 0; i < 3; i++){
			l.itemArray[i] = 0;//indicates to delete all lunch items from menu
			s.itemArray[i] = 0;//indicates to delete all sides from menu
		}
		
	}
	outFile << "Menu:\n";
	
	//send items to txt file (personal menu)
	for(int i = 0; i < 3; i++){
		if(b.itemArray[i] == 1){
			outFile << b.breakfastItems[i][0] << " \n";
		}
	}
	
	for(int j = 0; j < 3; j++){
		if(l.itemArray[j] == 1){
			outFile << l.lunchItems[j][0] << " \n";
		}
	}
	
	for(int k = 0; k < 3; k++){
		if(s.itemArray[k] == 1){
			outFile << s.sides[k][0] << " \n";
		}
	}
	
	outFile.close();
	return 0;
}

Breakfast::Breakfast(){
	for(int i = 0; i < 3; i++){
		itemArray[i] = 1;
	}
	
	breakfastItems[0][0] = "Croissanwich";
	breakfastItems[1][0] = "Pancakes";
	breakfastItems[2][0] = "Hash Browns";
	
	//croissanwich ingredients
	breakfastItems[0][1] = "Flour";
	breakfastItems[0][2] = "Eggs";
	
	//pancake ingredients
	breakfastItems[1][1] = "Flour";
	breakfastItems[1][2] = "Butter";
	
	//hash brown ingredients
	breakfastItems[2][1] = "Potatoes";
	breakfastItems[2][2] = "Salt";
}

Lunch::Lunch(){
	for(int i = 0; i < 3; i++){
		itemArray[i] = 1;
	}
	
	lunchItems[0][0] = "Whopper";
	lunchItems[1][0] = "Chicken Sandwich";
	lunchItems[2][0] = "Fish Sandwich";
	
	//whopper ingredients
	lunchItems[0][1] = "Beef";
	lunchItems[0][2] = "Onion";
	
	//chicken sandwich ingredients
	lunchItems[1][1] = "Chicken";
	lunchItems[1][2] = "Lettuce";
	
	//fish sandwich ingredients
	lunchItems[2][1] = "Salmon";
	lunchItems[2][2] = "Cucumber";
}

Sides::Sides(){
	for(int i = 0; i < 3; i++){
		itemArray[i] = 1;
	}
	
	sides[0][0] = "Chicken Nuggets";
	sides[1][0] = "French Fries";
	sides[2][0] = "Onion Rings";
	
	//ingredients for chicken nuggets
	sides[0][1] = "Chicken";
	sides[0][2] = "Flour";
	
	//ingredients for french fries
	sides[1][1] = "Potatoes";
	sides[1][2] = "Salt";
	
	//ingredients for onion rings
	sides[2][1] = "Chicken Nuggets";
	sides[2][2] = "French Fries";
}

void Breakfast::removeMenu(int arrayElem){
	itemArray[arrayElem] = 0;
}

void Lunch::removeMenu(int arrayElem){
	itemArray[arrayElem] = 0;
}

void Sides::removeMenu(int arrayElem){
	itemArray[arrayElem] = 0;
}

void Breakfast::searchMenu(string item){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(item.compare(breakfastItems[i][j]) == 0){
				itemArray[i] = 0;
			}else if((breakfastItems[i][j]).find(item) != -1){//-1 indicates that the ingredient is not a substring in a food name 
				itemArray[i] = 0;
			}
		}
	}
}

void Lunch::searchMenu(string item){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(item.compare(lunchItems[i][j]) == 0){
				itemArray[i] = 0;
			}else if((lunchItems[i][j]).find(item) != -1){//-1 indicates that the ingredient is not a substring in a food name 
				itemArray[i] = 0;
			}
		}
	}
}

void Sides::searchMenu(string item){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(item.compare(sides[i][j]) == 0){
				itemArray[i] = 0;
			}else if((sides[i][j]).find(item) != -1){//-1 indicates that the ingredient is not a substring in a food name 
				itemArray[i] = 0;
			}
		}
	}
}



