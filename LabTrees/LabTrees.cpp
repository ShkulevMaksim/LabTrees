//Вариант 16
#include <iostream>
using namespace std;

//Структура ветки
struct Branch
{
	char Data; //Поле данных
	Branch* LeftBranch; //УКАЗАТЕЛИ на соседние веточки
	Branch* RightBranch;
};


//Функция внесения данных
void Add(char aData, Branch*& aBranch)
{
	//Если ветки не существует
	if (!aBranch)
	{ //создадим ее и зададим в нее данные
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else //Иначе сверим вносимое
		if (aBranch->Data > aData)
		{ //Если оно меньше того, что в этой ветке - добавим влево
			Add(aData, aBranch->LeftBranch);
		}
		else
		{ //Иначе в ветку справа
			Add(aData, aBranch->RightBranch);
		};
}

void printOrder(Branch* element) {
	if (element == NULL)
		return;
	printOrder(element->LeftBranch);
	cout << element->Data << " ";
	printOrder(element->RightBranch);
}

void FreeTree(Branch* aBranch)
{
	if (!aBranch) return;
	FreeTree(aBranch->LeftBranch);
	FreeTree(aBranch->RightBranch);
	delete aBranch;
	return;
}


int main()
{
	Branch* Root = nullptr;
	char data = ' ';
	cout << "Choose an option:" << endl << endl;
	cout << "1. Create tree" << endl;
	cout << "2. Add node to a tree" << endl;
	cout << "3.Print tree" << endl;
	cout << "4. Exit" << endl;
	cout << endl;
	auto a = -1;
	auto While = true;
	while (While) {
		cin >> a;
		switch (a)
		{


		case 1:
			cout << "Enter a data: // Enter 0 to exit" << endl;
			while (data != '0') {
				cin >> data;
				if(data!='0')
				Add(data, Root);
			}
			break;
		case 2:
			cout << "Enter a node data to add:" << endl;
			cin >> data;
			Add(data, Root);
			break;

		case 3:
			printOrder(Root);
			break;
		case 4:
			While = false;
			break;

		default:
			cout << "Not an option" << endl;
			While = false;

			break;
		}
	}


	FreeTree(Root);

	cin.get();
	return 0;
}