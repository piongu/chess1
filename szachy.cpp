#include <iostream>
#include <string>

using namespace std;

class Szachy {
	char plansza[8][8];
	int nowwhite;
public:
	Szachy()
	{
		plansza[0] = { 'w', 's', 'g', 'h', 'k', 'g', 's', 'w' };
		plansza[1] = { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' };
		plansza[2] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		plansza[3] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		plansza[4] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		plansza[5] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		plansza[6] = { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' };
		plansza[7] = { 'W', 'S', 'G', 'H', 'K', 'G', 'S', 'W' };
		nowwhite = 1;
	}
	void show()
	{
		for(int i=0; i<8; i++)
		{
			for(int j=0; j<8; j++)
			{
				if(plansza[i][j])
				cout << plansza[i][j];
				else cout<<" ";
			}
			cout<<endl;
		}
	}
	void move(string m)
	{
		if (m.length() < 2) throw 1;
		else if (m.length() == 2)
		{
			char r = m[0];
			int c = m[1] - '0';
			cout << r << c << endl;
			if(nowwhite)
			{
				cout << "Teraz bialy" << endl;
				if (*translate(r,c)) throw "cos stoi";

				

				if (*translate(r,c-1) == 'P')
				{
					cout << " o jeden" << endl;
					char *skad = translate(r, c-1);
					char *dokad = translate(r, c);
					*skad = 0;
					*dokad ='P';
				}
				else if(c == 4)
				{
					cout << *translate(r, c-2) << endl;
					if (*translate(r,c-2) == 'P')
					{
						cout << " o dwa" << endl;
						char *skad = translate(r, c-2);
						char *dokad = translate(r, c);
						*skad = 0;
						*dokad ='P';
					}
					else throw 2;
				}

				else throw 2;

			}
		} else {
			cout << "Teraz czarny" << endl;
		}
		nowwhite = !nowwhite;
	}

	char search(string m)
	{
		return plansza[m[0]-'a'][m[1]-1-'0'];
	}

	char* translate(char x, int n)
	{
			int row = 8-n;
			int col = x - 'a';
			cout << "translate(" << x << n << ") = "<<col  << " " << row << endl;
			return &plansza[row][col];
	}

};



int main(int argc, char* argv[])
{
	Szachy nowy;
	nowy.show();
	try {
		nowy.move("c4");
	} catch (int x) {
		cout << "DUPA: " << x << endl;
		return 1;
	}
	nowy.show();

	return 0;
}

