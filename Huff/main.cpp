#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <fstream>

using namespace std;

typedef struct outbyte
{
	char q;
	struct outbyte* next;
};

class node
{
public:
	int a;
	char c;
	node *left, *right;

	node() { left = right = NULL; }

	node(node *L, node *R)
	{
		left = L;
		right = R;
		a = L->a + R->a;
	}
};


struct MyCompare
{
	bool operator()(const node* l, const node* r) const { return l->a < r->a; }
};

void printTree(node* root, unsigned k = 0)
{
	if (root != NULL)
	{
		printTree(root->left, k + 3);
		for (unsigned i = 0; i < k; i++)
		{
			cout << "  ";
		}
		if (root->c) cout << root->a << " (" << root->c << ")" << endl;
		else cout << root->a << endl;
		printTree(root->right, k + 3);
	}
}

vector <bool> code;
map <char, vector<bool> > table;

void BuildTable(node* root)
{
	if (root->left != NULL)
	{
		code.push_back(0);
		BuildTable(root->left);
	}

	if (root->right != NULL)
	{
		code.push_back(1);
		BuildTable(root->right);
	}

	if (root->c)
	{
		table[root->c] = code;
	}
	if (!code.empty())
		code.pop_back();
}

int main()
{
	ifstream f("1.txt");
	map<char, int> m;

	while (true)
	{
		char c = f.get();
		if (!f.eof())
		{
			m[c]++;
		}

		else
			break;
	}



	list<node*> t;
	for (map<char, int>::iterator itr = m.begin(); itr != m.end(); ++itr)
	{
	    node *p = new node;
		p->c = itr->first;
		p->a = itr->second;
		t.push_back(p);
	}

	while (t.size() != 1)
	{
		t.sort(MyCompare());

		node* sonL = t.front();
		t.pop_front();
		node* sonR = t.front();
		t.pop_front();

		node* parent = new node(sonL, sonR);
		t.push_back(parent);
	}

	node* root = t.front();
	root = t.front();

	BuildTable(root);


	f.clear();
	f.seekg(0);


	ofstream g("output.txt");

	int count = 0; char buf = 0;
	while (!f.eof())
	{
		char c = f.get();
		vector<bool> x = table[c];
		for (int n = 0; n < x.size(); n++)
		{
			buf = buf | (x[n] << (7 - count));
			count++;
			if (count == 8) { count = 0;   g << buf; buf = 0; }
		}
	}
	if (count != 0)
	{
		g << buf;
	}

	f.close();
	g.close();


	ifstream F("output.txt");


	node *p = root;
	count = 0; char byte;
	byte = F.get();
	while (!F.eof())
	{
		bool b = byte & (1 << (7 - count));
		if (b) p = p->right; else p = p->left;
		if (p->left == NULL && p->right == NULL) { cout << p->c; p = root; }
		count++;
		if (count == 8) { count = 0; byte = F.get(); }
	}

	F.close();

	putchar('\n');
	getchar();

	return 0;
}