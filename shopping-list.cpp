/* --------------------------
	shopping list
	implement functions
	arrays, while loop, more item details
	input single item and quantity
	format list to output
------------------------------*/
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int itemCount = 0; // running total of items
const int MAX = 10;

void getItems(string item[], int items[], string units[], float cost[], float &total);
void sizeColumns(int columns[], string item[], string units[]);
void printList(int columns[], string item[], int items[], string units[], float cost[], float total);

int main()
{

	// declaring some variables	
	string item[MAX]; // list items
	int items[MAX]; // quantity
	string units[MAX]; // example, "loaf" of bread
	float cost[MAX]; // cost per unit 

	float total = 0; // running total of cost
	
	int columns[] = {6,10,11,9}; // minimum length of columns
	
	cout<<"\nWelcome to your shopping list..."<<endl
		<<MAX<<" items max."<<endl;

	// prompt for user input	
	getItems(item, items, units, cost, total);		
		
	// resize columns
	sizeColumns(columns, item, units);

	// print out formatted list
	printList(columns, item, items, units, cost, total);
	
	return 0;
}

/* ---------------------------------------------------------
	FUNCTION: getItems
	PURPOSE: asks for user input and saves to appropriate arrays
	PARAMS: the list arrays and the total
	RETURNS: nothing
----------------------------------------------------------- */
void getItems(string item[], int items[], string units[], float cost[], float &total)		
{	
	cout<<"Enter an item (or \"done\"): ";
	getline(cin, item[itemCount]);
	while(item[itemCount]!="done" && itemCount < MAX)
	{
		cout<<"\tHow much "<<item[itemCount]<<" do you need(in units)? ";
		cin>>items[itemCount]>>units[itemCount];
		cin.ignore();
		cout<<"\tWhat is the cost per "<<units[itemCount]<<" of "
			<<item[itemCount]<<"? ";
		cin>>cost[itemCount];
		cin.ignore();
		total+=items[itemCount]*cost[itemCount];
		itemCount++;	
		
		if(itemCount==MAX)
		{
			cout<<"\nmaximum list items reached..."<<endl;
			break;
		}
		cout<<"\nEnter an item (or \"done\"): ";
		getline(cin, item[itemCount]);
	}
}

/* ---------------------------------------------------------
	FUNCTION: sizeColumns
	PURPOSE: to update needed column sizes for clean printing
	PARAMS: the column array and the item and units arrays
	RETURNS: nothing
----------------------------------------------------------- */
void sizeColumns(int columns[], string item[], string units[])
{
	for(int i = 0; i < itemCount; i++)
	{
		if(columns[0]<item[i].length()+2)
			columns[0]=item[i].length()+2;
		if(columns[1]<units[i].length()+2+3)
			columns[1]=units[i].length()+2+3;
		if(columns[2]<units[i].length()+2+6)
			columns[2]=units[i].length()+2+6;
	}
}

/* ---------------------------------------------------------
	FUNCTION: printList
	PURPOSE: outputs the formatted list to the screen
	PARAMS: all of the arrays, the column array and the total
	RETURNS: nothing
----------------------------------------------------------- */
void printList(int columns[], string item[], int items[], string units[], float cost[], float total)
{
	string border; // sized list border
	border.assign(columns[0]+columns[1]+columns[2]+columns[3], '-');
	cout<<"\nYour list:\n"
		<<border<<endl
		<<left<<setw(columns[0])<<"item"
		<<setw(columns[1])<<"quantity"
		<<setw(columns[2])<<"unit cost"
		<<setw(columns[3])<<"item cost"
		<<endl;
	for(int i = 0; i < itemCount; i++)
	{
		cout<<left<<setw(columns[0])<<item[i]
			<<right<<setw(2)<<items[i]<<" "
				<<left<<setw(columns[1]-3)<<units[i]
			<<"$"<<right<<fixed<<setprecision(2)<<cost[i]<<"/"
				<<left<<setw(columns[2]-6)<<units[i]
			<<"$"<<setw(columns[3])<<fixed<<setprecision(2)<<items[i]*cost[i]
			<<endl;
	}
	cout<<border<<endl;
	cout<<right<<setw(columns[0]+columns[1]+columns[2])<<"total: "
		<<left<<"$"<<total<<endl;
	cout<<"\nGo get your items!!"<<endl<<endl;
}