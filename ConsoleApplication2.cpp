#include <string>
#include <iostream>
using namespace std;

class House
{
public:
	virtual void print() = 0;
	virtual int* area(int,int*,int*) = 0;
	virtual int* ar(int,int*,int*) = 0;
};

class Flat :public House
{
protected:
	int** flatt;
	int m;
	int n;
	int* lngth;
	int* wdth;
	int* areaB;
	
public:
	Flat(int n1, int m1)
	{
		n = n1;
		m = m1;
		areaB = new int[n * m];
		flatt = new int* [n];


		for (int i = 0; i < n; i++)
		{
			flatt[i] = new int[m];
		}
	}
	virtual int*  area(int,int*,int*) = 0;
	virtual int* ar(int,int*,int*) = 0;
	~Flat();

};

Flat::~Flat()
{
	delete[]flatt;
}

class Bath :public Flat
{

public:
	Bath(int n, int m, int *lngth1, int *wdth1) :Flat(n, m)
	{
		lngth = lngth1;
		wdth = wdth1;
		
	}
	~Bath();
	void print()
	{
		cout << "Ванна" << endl;
	}

	int* area(int count,int *lngth1, int *wdth1)
	{
		for (int i = 0; i < count; i++)
		{
			areaB[i] = lngth[i] * wdth[i];	
		}

		return areaB;
	}

	int* ar(int count,int* lngth1, int* wdth1)
	{
		
		for (int i = 0; i < count; i++)
		{
			cout << "Площадь ванны " << i + 1 << " квартиры " << areaB[i] << endl;
		}
		return areaB;
	}
};

Bath::~Bath()
{
	delete[]areaB;
}

class Bedroom :public Flat
{

public:
	Bedroom(int n, int m,int *lngth1, int *wdth1) :Flat(n, m) {
		lngth = lngth1;
		wdth = wdth1;	
	}
	~Bedroom();
	void print()
	{
		cout << "Спальня" << endl;
	}

	int* area(int count, int* lngth1, int* wdth1)
	{


		for (int i = 0; i < count; i++)
		{
			areaB[i] = lngth[i] * wdth[i];
		}
		return areaB;
	}
	int* ar(int count, int* lngth1, int* wdth1)
	{
		
		for (int i = 0; i < count; i++)
		{
			cout << "Площадь спальни " << i + 1 << " квартиры " << areaB[i] << endl;
		}
		return areaB;
	}
};
Bedroom::~Bedroom()
{
	delete[]areaB;
}
class Kitchen :public Flat
{

	
public:
	Kitchen(int n, int m, int* lngth1, int* wdth1) :Flat(n, m) {
		lngth = lngth1;
		wdth = wdth1;
		
	}
	~Kitchen();
	void print()
	{
		cout << "Кухня" << endl;
	}

	int* area(int count, int* lngth1, int* wdth1)
	{
		for (int i = 0; i < count; i++)
		{
			areaB[i] = lngth[i] * wdth[i];
		}
		return areaB;
	}

	int* ar(int count, int* lngth1, int* wdth1)
	{
		
		for (int i = 0; i < count; i++)
		{
			cout << "Площадь кухни " << i + 1 << " квартиры " << areaB[i] << endl;
			
		}
		
		
		return areaB;
	}
};
Kitchen::~Kitchen()
{
	delete[]areaB;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	bool check = false;

	int cFloor;
	int cFlat;
	cout << "Введите количество этажей " << endl;

	while (!(cin >> cFloor))
	{
		cout << "Введите целочисленное значение" << endl;
		cout << "";
		cout << "Введите количество этажей " << endl;
		cin.clear();
		cin.ignore();
	}
	cout << "Введите количетсво квартир на этаже " << endl;

	while (!(cin >> cFlat))
	{
		cout << "Введите целочисленное значение" << endl;
		cout << "";
		cout << "Введите количество этажей " << endl;
		cin.clear();
		cin.ignore();
	}





	int* bathWdth = new int[cFlat * cFloor];
	int* bathLngth = new int[cFlat * cFloor];
	int* areaB = new int[cFlat * cFloor];

	int* bedWdth = new int[cFlat * cFloor];
	int* bedLngth = new int[cFlat * cFloor];

	int* kitchWdth = new int[cFlat * cFloor];
	int* kitchLngth = new int[cFlat * cFloor];

	int* areaBath = new int[cFlat * cFloor];
	int* areaBedroom = new int[cFlat * cFloor];
	int* areaKitchen = new int[cFlat * cFloor];
	int* areaMain = new int[cFlat * cFloor];


	
	House* hs[3];
	Bath bth(cFlat, cFloor,bathWdth,bathLngth);
	Bedroom bdr(cFlat, cFloor, bedWdth, bedLngth);
	Kitchen ktch(cFlat, cFloor, kitchWdth, kitchLngth);
	hs[0] = &bth;
	hs[1] = &bdr;
	hs[2] = &ktch;


	for (int i = 0; i < cFlat * cFloor; i++)
	{
		cout << "Введите длину ванны " << i + 1 << " квартиры" << endl;
		cin >> bathLngth[i];
		cout << "Введите ширину ванны " << i + 1 << " квартиры" << endl;
		cin >> bathWdth[i];

		cout << "Введите длину спальни " << i + 1 << " квартиры" << endl;
		cin >> bedLngth[i];
		cout << "Введите ширину спальни " << i + 1 << " квартиры" << endl;
		cin >> bedWdth[i];

		cout << "Введите длину кухни " << i + 1 << " квартиры" << endl;
		cin >> kitchLngth[i];
		cout << "Введите ширину кухни " << i + 1 << " квартиры" << endl;
		cin >> kitchWdth[i];
		cout << endl;
		hs[0]->area(cFlat * cFloor, bathLngth, bathWdth);
		hs[1]->area(cFlat * cFloor, bedLngth, bedWdth);
		hs[2]->area(cFlat * cFloor, kitchLngth, kitchWdth);
		cout << endl;
	}

		hs[0]->print();
		areaBath = hs[0]->ar(cFlat * cFloor, bathLngth, bathWdth);
		cout << endl;
		hs[1]->print();
		areaBedroom = hs[1]->ar(cFlat * cFloor, bedLngth, bedWdth);
		cout << endl;
		hs[2]->print();
		areaKitchen = hs[2]->ar(cFlat * cFloor, kitchLngth, kitchWdth);
	


	cout << "" << endl;

	for (int i = 0; i < cFlat * cFloor; i++)
	{
		cout << "Общая площадь " << i + 1 << " квартиры = ";
		areaMain[i] = areaBath[i] + areaBedroom[i] + areaKitchen[i];
		cout << areaMain[i] << endl;
	}
}

