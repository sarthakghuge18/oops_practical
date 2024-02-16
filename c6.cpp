/*
Write C++ Program using STL for sorting and searching user defined
records such as item records(code,name,cost,quantity) using vector container.
*/

#include <iostream>
#include <vector>
using namespace std;

class items
{
private:
	string name;
	int cost;
	int quantity;

public:
	int code;  //it declare in public because with the help of it we search and sort the items 

	// Default constructor
	
	items ()
	{
		code=0;
		name="";
		cost=0;
		quantity=0;
	}
	items(int cd, string nm, int cst, int qnt) // parametric constructor
	{
		code = cd;
		name = nm;
		cost = cst;
		quantity = qnt;
	}

	void display()
	{
		cout << " code : " << code;
		cout << " name : " << name;
		cout << " cost : " << cost;
		cout << " quantity : " << quantity << endl;
	}
};

int main()
{
	vector<items> v1;  		//v1 is object of items in vector 
	int choice;
	while (1)
	{
		cout << "\n1.insert\n2.display\n3.searching\n4.sorting\n0.exit\n";
		cin >> choice;
		if (choice == 1)
		{
			string name;
			int code;
			int cost;
			int quantity;
			cout << "enter the item code|name|cost|quantity " << endl;
			cin >> code >> name >> cost >> quantity;
			items item(code, name, cost, quantity);
			v1.push_back(item);
		}
		else if (choice == 2)
		{
			for (int i = 0; i < v1.size(); i++)
			{
				v1[i].display();
			}
		}
		else if (choice == 3)
		{
			int c;
			cout << "enter the item code to be search : ";
			cin >> c;
			int flag = 0;
			for (int i = 0; i < v1.size(); i++)
			{
				if (v1[i].code == c)
				{
					v1[i].display();
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cout << "item not found " << endl;
			}
		}
		else if (choice == 4)
		{
			int min;
			for (int i = 0; i < v1.size(); i++)
			{
				int min = i;
				for (int j = i + 1; j < v1.size(); j++)
				{
					if (v1[j].code < v1[min].code)
					{
						min = j;
					}
				}
				items temp;
				temp = v1[i];
				v1[i] = v1[min];
				v1[min] = temp;
			}

			for (int i = 0; i < v1.size(); i++)
			{

				v1[i].display();
			}
		}

		else if (choice == 0)
		{
			cout << "existed";
			break;
		}
	}
	return 0;
}













