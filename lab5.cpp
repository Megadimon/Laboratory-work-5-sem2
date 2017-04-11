#include <iostream>
#include <conio.h>
using namespace std;
 
int tabs = 0;
int number = 0;
unsigned int k = 0;
unsigned int n = 0;

template <class Type>
class BinarySearchTree
{
private:
	Type data;
	BinarySearchTree *left; 
	BinarySearchTree *right; 
	
public:
void Add(Type new_data, BinarySearchTree *&root)
{
	if (!root)
	{
		root = new BinarySearchTree;
		root->data = new_data;
		root->left = 0;
		root->right = 0;
		return;
	}
	else if ( root->data > new_data ) Add(new_data, root->left);
	else if ( root->data < new_data ) Add(new_data, root->right); 
	else return;
}

void Search(BinarySearchTree *root)
{
	if (!root) return;
	
	if ( k == 0 ) 
	{ 
		cout << endl << "Type the number you want to find: "; 
		cin >> number;
	}
	k++; 

	if(root->data == number) 
		{ 
			cout << endl << "[+] The number " << number << " was found!:)";
			n++;
		}
	
	Search(root->left);
	Search(root->right);

}

void print(BinarySearchTree *root)
{
	if (!root) return; 
	
	tabs++; 
	print(root->right);
 
	for (int i = 0; i < tabs; i++) cout << "- "; 
	cout << root->data << endl;

	print(root->left);
 	tabs--;

	return;
}
 
void FreeTree(BinarySearchTree *root)
{
	if (!root) return;
	FreeTree(root->left);
	FreeTree(root->right);
	delete root;
	return;
}
 
};

int main(void)
{
	BinarySearchTree<unsigned int> *root = 0;
	BinarySearchTree<unsigned int> *ptr;

	unsigned int* node;
	unsigned int size = 0;
	auto temp = 0;

	cout << "Print the number of nodes: ";
	cin >> temp;
	try
	{
		if( temp < 0 ) throw 1;
	}
	catch( int test )
	{
		cout << endl << "[-] Exception " << test << ": The number of nodes can't be negative!!!" << endl;
		return 0;
	}
	size = temp;

	node = new unsigned int [size];

	for (unsigned int i = 0; i < size; ++i)
	{
		cout << "Add node " << i+1 << ": ";
		cin >> temp;
		try
		{
			if( temp < 0 ) throw 2;
		}
		catch( int test )
		{
			cout << endl << "[-] Exception " << test << ": The node of tree can't be negative!!!" << endl;
			return 0;
		}
		node[i] = temp;
		cout << endl;
	}


	for (unsigned int i = 0; i < size; ++i)
	{
		ptr->Add(node[i], root);
	}
 
	ptr->print(root);
	ptr->Search(root);
	if( n == 0 ) cout << endl << "[-] The number " << number << " was not found!:(";

	ptr->FreeTree(root);
 	delete [] node;
	cout << endl << endl << "Press any button to exit the program " << endl;
	_getch();
	return 0;
}

