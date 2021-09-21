//Created by Ali Jamil

#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

// functions declaration //
void enter_into();
void laboratory();
void house();
void door_first();
void door_second();
void door_third();
void clear_security_guards();
void search_room(int search_door_no);
void inventory(int items_no);
int pin_code();
void back(int type_no);
void errors(int error_no);

// vector declaration //
vector <int> inventory_items;

// globad variables declaration //
char select = '0', read = '0', door_opened  = 'N';
int door_code = 0, enter_code = 0, count_enemy_killed = 0, total_enemies = 3, unlock_door = 0, sequence = 0;
char kill;
// return values //
int building_type_no;

// true false variables //
bool check_key = false, check_door_no = false, get_key_code = false, get_torch =  false, clear_enemies = false, key_inserted = false;

// A game start from here //
main()
{
	
	cout<<"Story Objects: [Find the key to open the laboratory door.]"<<endl<<endl;
	
	enter_into();
	
	getch();
}

// functions deffination //


// This function is use for to enter which building //
void enter_into()
{
	select  = '0';
	
	cout<<"1.Enter into Laboratory.\n2.Enter into House."<<endl<<endl;
	cout<<"Where to enter first: ";
	
	cin>>select;
	
	if((select<48 || select >57))
	{
		errors(14);
		
		cout<<endl;
		
		enter_into();
		
	}
		else if(select == '1')
	{
		laboratory();
	}
	else if(select == '2')
	{
		house();
	}
	else
	{		
		errors(0);
		
		cout<<endl;
		
		enter_into();
	}

		
}
// This function is use for to enter into laboratory //
void laboratory()
{

	select  = '0';
	unlock_door = 0;

if(key_inserted == true)
{
	 goto Key_Inserted;
}

		cout<<"\n1. Insert a key to unlock the door.";
		
Key_Inserted:
		
		cout<<"\n2. Open door and searching."<<endl<<endl;
		cout<<"Select from the following options: ";
		cin>>select;
		
		
		if((select<48 || select >57))
	{
		errors(14);
	
		laboratory();
		
	}
		else if(select == '1' && check_key == false || select == '2' && check_key == false )
		{
			errors(1);
			
			cout<<endl;
			
			enter_into();
			
		}
		else if(select == '1' && check_key == true)
		{
			key_inserted = true;
			
			errors(17);
			
			 goto Key_Inserted;	
		}
			else if(select == '2' && check_key == true && key_inserted == false)
		{
			
			errors(18);
			
			laboratory();
			
		}
		else if(select == '2' && check_key == true && key_inserted == true)
		{
			search_room(4);
		}
		else
		{
			errors(2);
			
			cout<<endl;
			
			enter_into();
		}
		
		
}
// This function is use for to enter into house //
void house()
{
	select  = '0';
		
			
		cout<<"\n1. Open Door A.\n2. Open Door B.\n3. Open Door C and Search.\n4. Get Back."<<endl<<endl;
		cout<<"Select from the following options: ";
		cin>>select;
		
		if((select<48 || select >57))
	{
		errors(14);
		
		house();
		
	}
		else if(select == '1')
		{
			door_first();
		}
		else if(select == '2')
		{
			door_second();
		}
		else if(select == '3')
		{
			door_third();
		}
		else if(select == '4')
		{
			back(1);
		}
		else
		{
			errors(3);
			
			house();
		}
	
}
// This function is use for to enter into door first //
void door_first()
{
	select  = '0';
		
		if(clear_enemies == true)
		{
			goto Clear_Enemies;
		}
		
		cout<<"\n1. Kill Enemies.";
		
Clear_Enemies:
	
		cout<<"\n2. Searching.";
		
	
		cout<<"\n3. Get Back."<<endl<<endl;
		
		cout<<"Select from the following options: ";
		cin>>select;

if(select == '2' && get_torch == true)
{
		errors(16);
		
		goto Clear_Enemies;
}		

		if((select<48 || select >57))
		{
		errors(14);
		
		door_first();
		
		}
	
		else if(select == '1')
		{
			clear_security_guards();
			
			door_first();
		}
		else if(select == '2')
		{
			if(clear_enemies == false)
			{
				errors(10);
				
				door_first();
			}
			else if(clear_enemies == true)
			{
				search_room(2);
				
				inventory(2);
				
				errors(12);

				get_torch = true;
									
				door_first();
			}
		}
		else if(select == '3')
		{
			back(2);
		}
		else
		{
			errors(2);
				
			door_first();
		}
	
	
}
// This function is use for to enter into door second//
void door_second()
{
	select  = '0';
		
		if(door_opened  == 'Y')
		{
			goto Code_Inserted;
		}
		
		cout<<"\n1. Type a code.";
		
 Code_Inserted:
 	
		cout<<"\n2. Door open and search.";
		cout<<"\n3. Get Back."<<endl<<endl;
		
		cout<<"Select from the following options: ";
		cin>>select;

if(select == '2' && check_key == true)
{
		errors(16);
		
		goto Code_Inserted;
}
		
		if((select<48 || select >57))
	{
		errors(14);
		
		door_second();
		
	}
	
		else if(select == '1')
		{
			if(get_key_code == false)
			{
				errors(5);
				
				door_second();
			}
			else if(get_key_code == true)
			{
				
				cout<<"\nPlease enter a security code: ";
				cin>>enter_code;
			
			if(enter_code == door_code)
				{
					
				door_opened  = 'Y';
				
				check_door_no =  true;
				
				errors(7);
				
				door_second();
				
				}
				else if(enter_code != door_code)
				{
					
				errors(6);
				
				door_second();
				
				}
			
			}
		}
		else if(select == '2')
		{
			if(check_door_no == true)
			{
				if(get_torch == false)
				{
					errors(9);
					
					door_second();
				}
				else if(get_torch == true)
				{
					search_room(3);
					
					inventory(3);
					
					errors(12);
					
					check_key = true;
					
					door_second();
				}	
			}
			else if(get_key_code == true && check_door_no == false)
			{
				errors(8);
				
				door_second();
			}
			else
			{
				errors(5);
				
				door_second();
			}
		}
		else if(select == '3')
		{
			back(2);
		}
		else
		{
			errors(2);
			
			door_second();
		}
}
// This function is use for to enter into door third //
void door_third()
{
	select = '0';


	
	if(get_key_code ==  true)
	{
		errors(15);

Code_Get:
		
		cout<<"\n1. Get Back."<<endl;
		cout<<"\nSelect from the following options: ";
		cin>>select;
		
			if((select<48 || select >57))
		{
			errors(14);
		
			door_third();
		
		}
		else if(select == '1')
		{
			house();
		}
		else
		{
			errors(2);
			
			goto Code_Get;
		}
	
	}
	
	cout<<"\nRead a paper."<<endl;
	cout<<"\n1. Yes.\n2. No."<<endl;
	cout<<"\nSelect from the following: ";
	cin>>read;
	
		if((read<48 || read >57))
	{
		errors(14);
	
		
		door_third();
		
	}
	
	else if(read == '1')
	{
		search_room(1);
		
		inventory(1);
		
		cout<<"\nYou have a code to unlock the door B [ "<<pin_code()<<" ]."<<endl;
		
		get_key_code =  true;
		
		errors(12);
		
		goto Code_Get;
	}
	else if(read == '2')
	{
		errors(4);
		
		house();
	}
	else
	{
		errors(2);
		
		house();
	}
}
// This function is use for to prompt the player to clear guards firstly //
void clear_security_guards()
{
	
	if(count_enemy_killed == total_enemies)
	{
		clear_enemies = true;
		
		errors(11);
	}
	else if(count_enemy_killed != total_enemies)
	{
		for(int i=1;i<=total_enemies;i++)
		{
			cout<<"\nY/N"<<endl;
			cout<<"Shoot --->: ";
			cin>>kill;
			
			if(kill == 'Y' || kill == 'y')
			{
				count_enemy_killed ++;
			}
		}
		
		if(count_enemy_killed != total_enemies)
		{
			count_enemy_killed = 0;
			
			errors(10);
		}
		else
		{
			clear_enemies = true;
			
			errors(11);
		}
	}
}
// This function is use for to search the rooms accoring to passing room no //
void search_room(int search_door_no)
{
	if(search_door_no == 1)
	{
		cout<<"\nFound the key code."<<endl;
	}
	else if(search_door_no == 2)
	{
		cout<<"\nFound the torch."<<endl;
	}
	else if(search_door_no == 3)
	{
		cout<<"\nFound the key of the laboratory."<<endl;
	}
	else if(search_door_no == 4)
	{
		cout<<"\nYou won the game."<<endl;
		getch();
	}
}
// This function is use for to store items //
void inventory(int items_no)
{
	if(items_no == 1)
	{
		inventory_items.push_back(1);
	}
	else if(items_no == 2)
	{
		inventory_items.push_back(2);
	}
	else if(items_no == 3)
	{
		inventory_items.push_back(3);
	}
		
}

// This function is use for get the pin code of door second //
int pin_code()
{
	if(inventory_items[0] == 1 || inventory_items[1] == 1 )
	{
		door_code = 1234;
	}
	else
	{
		door_code = 0;
	}
	
	return door_code;
}
// This function is use for to get back //
void back(int type_no)
{
	if(type_no == 1)
	{
		cout<<endl;
		
		enter_into();
	}
	else if(type_no == 2)
	{
		house();
	}
	
}

// This function is use for to display error //
void errors(int error_no)
{
	if(error_no == 0)
	{	
		cout<<"\nYou enter into unknown building."<<endl;
	}
	else if(error_no == 1)
	{
		cout<<"\nYou don't have a key to unlock the door."<<endl;
	}
	else if(error_no == 2)
	{
		cout<<"\nNothing been selected."<<endl;
	}
	else if(error_no == 3)
	{		
		cout<<"\nNo door is found."<<endl;
	}
	else if(error_no == 4)
	{		
		cout<<"\nHave a nice day !."<<endl;
	}
	else if(error_no == 5)
	{
		cout<<"\nYou don't have a code to open the door."<<endl;
	}
	else if(error_no == 6)
	{
		cout<<"\nIncorrect code."<<endl;
	}
	else if(error_no == 7)
	{	
		cout<<"\nYou successfull unlock the key code."<<endl;
	}
	else if(error_no == 8)
	{		
		cout<<"\nPlease unlock the key code."<<endl;
	}
	else if(error_no == 9)
	{		
		cout<<"\nYou don't have a torch to serach around."<<endl;
	}
	else if(error_no == 10)
	{	
		cout<<"\nLost Game."<<endl;
	}
	else if(error_no == 11)
	{
			
		cout<<"\nRoom cleared."<<endl;
	}
	else if(error_no == 12)
	{
		cout<<"\nNew items added."<<endl;
	}
	else if(error_no == 13)
	{		
		cout<<"\nInsert key to unlock the door."<<endl;
	}
	else if(error_no == 14)
	{	
		cout<<"\nPlease enter a valid number which belongs to an integer type."<<endl;
	}
	else if(error_no == 15)
	{	
		cout<<"\nAlready Get Code."<<endl;
	}
	else if(error_no == 16)
	{
		cout<<"\nNo items found."<<endl;
	}
	else if(error_no == 17)
	{	
		cout<<"\nYou successfull unlock the Laboratory key."<<endl;
	}
	else if(error_no == 18)
	{
		cout<<"\nPlease unlock the key."<<endl;
	}
	
}
