#include <iostream>
#include <stdlib.h>
using namespace std;

class Menu
{
   protected:
	double price;
   public:
	Menu () : price(0) {}
	virtual void display_menu() = 0;
};

class Pasta : virtual public Menu
{
   protected:
	string pasta_type;
	int pasta_choice;
	double pasta_price;
	double price_total;
	
   public:
	Pasta() {}
	Pasta (string pasta_type, double pasta_price) : pasta_type(pasta_type), pasta_price(pasta_price)
	{
		cout << "A pasta is in order : " << endl;
		cout << "Pasta type : " << pasta_type << endl;
		cout << "Pasta price : RM " << pasta_price << endl;	
	}
	string getPasta_type () {return pasta_type;}
	double getPasta_price () {return pasta_price;}
	virtual void display_menu()
	{
		string pasta_type[3];
		pasta_type[0] = "Spaghetti";
		pasta_type[1] = "Fettucine";
		pasta_type[2] = "Penne    ";
		
		double pasta_price[3];
		pasta_price[0] = 7;
		pasta_price[1] = 6.50;
		pasta_price[2] = 9.90;
		
		cout << endl <<"Pasta type & price = "<< endl << endl;
		int a;
		a = 1;
		for(int i = 0; i < 3; i++)
		{	
			cout << "[" << a << "] " << pasta_type[i] << "       RM " << pasta_price[i] << endl;
			a = a+1;
		}
			
	}
};

class Pizza : virtual public Menu
{
   private:
	string pizza_crust;
	string pizza_size;
	double pizza_price;
	int pizza_choice;
	
   public:
	Pizza() {}
	Pizza (string pizza_crust, double pizza_price, string pizza_size) : pizza_crust(pizza_crust), pizza_price(pizza_price), pizza_size(pizza_size)
	{
		cout << "A pizza is in order : " << endl;
		cout << "Pizza type of crust : " << pizza_crust << endl;
		cout << "Pizza size : " << pizza_size << endl;
		cout << "Pizza price : RM " << pizza_price << endl;	
	}	
	string getPizza_type () {return pizza_crust;}
	double getPizza_price () {return pizza_price;}
	virtual void display_menu()
	{
		string pizza_crust[3];
		pizza_crust[0] = "Classic Crust";
		pizza_crust[1] = "Thin Crust   ";
		pizza_crust[2] = "Cheesy Crust ";
			
		double pizza_price[3];
		pizza_price[0] = 20;
		pizza_price[1] = 25;
		pizza_price[2] = 30;
		
		cout << endl << "Pizza :- " << endl;
		cout << "Type of crust & price = "<< endl << endl;
		int a;
		a= 1;
		for(int i = 0; i < 3; i++)	
			{
			cout << "[" << a << "] " << pizza_crust[i] << "          RM " << pizza_price[i] << endl;
			a++;
			}
	}
};

int main()
{
	
	string pasta_type[3];
	pasta_type[0] = "Spaghetti";
	pasta_type[1] = "Fettucine";
	pasta_type[2] = "Penne    ";

	double pasta_price[3];
	pasta_price[0] = 7.00;
	pasta_price[1] = 6.50;
	pasta_price[2] = 9.90;
	
	string pizza_crust[3];
	pizza_crust[0] = "Classic Crust";
	pizza_crust[1] = "Thin Crust   ";
	pizza_crust[2] = "Cheesy Crust ";
		
	string pizza_size[3];
	pizza_size[0] = "Personal (Normal Price)";
	pizza_size[1] = "Regular (Add RM 5)";
	pizza_size[2] = "Large (Add RM 10)";
		
	double pizza_price[3];
	pizza_price[0] = 20;
	pizza_price[1] = 25;
	pizza_price[2] = 30;
	
	int choose1;
	int start;
	double total_pricePasta,total_pricePizza,total_price;
	//total_price = total_pricePasta + total_pricePizza;
	
	start = 2; //start = 2 will loop 1st page 
	
	while (start == 2)
	{
		cout << "---------------------------------------------------------------------" << endl;
		cout << "                    Welcome to Italian Restaurant                  " << endl;
		cout << "---------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "Please choose: " << endl;
		cout << "[1] Modify Menu <Manager>" << endl;
		cout << "[2] New Order" << endl;
		cin >> choose1;
		
		if (choose1 ==1)
		{
			start = 2;
			system("cls");
			cout << "Modify Menu" << endl;
			cout << "Sorry, this section is under construction." << endl;
			cout << "Please try again" << endl;
		}
		else if (choose1 ==2)
		{	
			int start2;
			start2 = 2; //start2 = 2 will loop 2nd page 
			start = 1;
			
			while (start2 ==2)
			{
				int choose2,choose3,choose_size,pasta_choice,pizza_choice;
				double price_total;
				
				system("cls");
				cout << "---- New Order ---" << endl;
				cout << "[1] Pasta" << endl;
				cout << "[2] Pizza" << endl;
				cout << "[3] Drink" << endl;
				cout << "[4] Back" << endl;
				cout << "Enter : " ;
				cin >> choose2;
				
				switch(choose2)
				{
				case 1:
				{
					start2 = 1;
					Menu* a = new Pasta;
					a->display_menu();
					cout << "Enter : " ;
					cin >> pasta_choice;
					cout << endl;
					
					switch (pasta_choice)
					{
					case 1:
						{
						Pasta(pasta_type[0], pasta_price[0]);
						total_pricePasta = total_pricePasta + 7;
						total_price = total_pricePasta + total_pricePizza;
						break;
						}
					case 2:
						{
						Pasta(pasta_type[1], pasta_price[1]);
						total_pricePasta = total_pricePasta + 6.5;
						total_price = total_pricePasta + total_pricePizza;
						break;
						}	
					case 3:
						{
						Pasta(pasta_type[2], pasta_price[2]);
						total_pricePasta = total_pricePasta + 9.9;
						total_price = total_pricePasta + total_pricePizza;
						break;
						}
					default:
						cout << "Error input, try again." << endl;
					}

					cout << endl;
					cout <<	"Total price: RM " << total_price << endl;
					cout << "Add new item? <[1]Yes/[2]No>" << endl;
					cout << "Enter : " ;
					cin >> choose3;
					if (choose3 == 1)
					{
						start2 = 2;
					}
					else if(choose3 == 2)
					{
						start2 = 1;
						cout << "Your total price is : RM " << total_price << endl;
						cout << "Thanks You" << endl;
					}
						
					break;
				}
				case 2:
				{
					start2 = 1;
					Menu* a = new Pizza;
					a->display_menu();
					cout << "Enter : " ;
					cin >> pizza_choice;
					switch (pizza_choice)
					{
						case 1:
						{	
							int b = 1;
							choose_size = 0;
							cout << "Please choose size : " << endl;
							for(int i = 0; i < 3; i++)
							{
								cout << "[" << b << "] " << pizza_size[i] << endl;
								b++;
							}
							cout << "Size : ";
							cin >> choose_size;
							choose_size = choose_size - 1;
							Pizza(pizza_crust[0], pizza_price[0],pizza_size[choose_size]);
							if(choose_size == 1)
							{
								total_pricePizza = total_pricePizza + 5;
								total_price = total_pricePasta + total_pricePizza;
							}
							else if(choose_size == 2)
							{
								total_pricePizza = total_pricePizza + 10;
								total_price = total_pricePasta + total_pricePizza;
							}
							break;
						}
						case 2:
						{	
							int b = 1;
							choose_size = 0;
							cout << "Please choose size : " << endl;
							for(int i = 0; i < 3; i++)
							{
								cout << "[" << b << "] " << pizza_size[i] << endl;
								b++;
							}
							cout << "Size : ";
							cin >> choose_size;
							choose_size = choose_size - 1;
							Pizza(pizza_crust[1], pizza_price[1],pizza_size[choose_size]);
							if(choose_size == 1)
							{
								total_pricePizza = total_pricePizza + 5;
								total_price = total_pricePasta + total_pricePizza;
							}
							else if(choose_size == 2)
							{
								total_pricePizza = total_pricePizza + 10;
								total_price = total_pricePasta + total_pricePizza;
							}
							break;
						}
						case 3:
							{
							int b = 1;
							choose_size = 0;
							cout << "Please choose size : " << endl;
							for(int i = 0; i < 3; i++)
							{
								cout << "[" << b << "] " << pizza_size[i] << endl;
								b++;
							}
							cout << "Size : ";
							cin >> choose_size;
							choose_size = choose_size - 1;
							Pizza(pizza_crust[2], pizza_price[2],pizza_size[choose_size]);
							if(choose_size == 1)
							{
								total_pricePizza = total_pricePizza + 5;
								total_price = total_pricePasta + total_pricePizza;
							}
							else if(choose_size == 2)
							{
								total_pricePizza = total_pricePizza + 10;
								total_price = total_pricePasta + total_pricePizza;
							}							
							break;
							}
						default:
						cout << "Error input, try again." << endl;
					}
					
					cout << endl;
					cout <<	"Total price: RM " << total_price << endl;
					cout << "Add new item? <[1]Yes/[2]No>" << endl;
					cout << "Enter : " ;
					cin >> choose3;
					if (choose3 == 1)
						{
							start2 = 2;
						}
					else if(choose3 == 2)
					{
						start2 = 1;
						cout << "Your total price is : RM " << total_price << endl;
						cout << "Thanks You" << endl;
					}
							
					break;
				}
				case 3:
				{
					start2 = 1;
					cout << "Drink not yet" << endl;
					break;
				}
				case 4:
				{
					start2 = 1;
					start = 2;
					break;
				}
				default:
					{
					start = 2;
					cout << "Error, please try again.";
					}
				}
		
			}
			
			
		}
		
		else
		{
			system("cls");
			cout << "Invalid input! Please insert again." << endl << endl << endl;
		}
	};
	
}