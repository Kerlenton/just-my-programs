// ������� ���������
#include <iostream>
using namespace std;

enum { _ = 5 };

enum { Red, Green, Yellow, Blue, White };
const char *ColorStr[] = { "Red", "Green", "Yellow", "Blue", "White", "-" };

enum { Tea, Milk, Water, Beer, Coffee };
const char *DrinkStr[] = { "Tea", "Milk", "Water", "Beer", "Coffee", "-" };

enum { Cat, Bird, Dog, Horse, Fish };
const char *PetStr[] = { "Cat", "Bird", "Dog", "Horse", "Fish", "-" };

enum { Rothmans, Dunhill, Marlboro, PallMall, Winfield };
const char *CigarettesStr[] = { "Rothmans", "Dunhill", "Marlboro", "Pall Mall", "Winfield", "-" };

enum { Norwegian, Englishman, Dane, German, Swede };
const char *NationalityStr[] = { "Norwegian", "Englishman", "Dane", "German", "Swede", "-" };

enum Property { Color, Drink, Pet, Cigarettes, Nationality, PropertiesCount };

// �� ����� ����� ������ ����� ���� �����,
const size_t HousesCount = 5;

int s[HousesCount][PropertiesCount];

bool neighborOf(size_t i, int property, int value)
{
	return (i >= 1 && (s[i - 1][property] == _ || s[i - 1][property] == value)) ||
		(i < HousesCount - 1 && (s[i + 1][property] == _ || s[i + 1][property] == value));
}

bool check()
{
	// ������ � ������ �����. � ������ ���� �������, ��� ���� � ������ ���������������.
	// ������ ������� ������������ ���������� ����� �������, ������� � �������� ��������.
	for (size_t i = 0; i < HousesCount; ++i)
	{
		for (size_t j = 0; j < PropertiesCount; ++j)
		{
			int &p1 = s[i][j];
			for (size_t k = i + 1; k < HousesCount; ++k)
			{
				int &p2 = s[k][j];
				if (p1 != _ && p2 != _ && p1 == p2)
					return false;
			}
		}
	}

	// ����� ����:
	// �������� ���� � ������ ����.
	if (s[0][Nationality] != Norwegian && s[0][Nationality] != _)
		return false;
	// ���������� ���� � ������� ����.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Nationality] == Englishman && s[i][Color] != _ && s[i][Color] != Red)
			return false;
	// ������ ��� ��������� ����� �� ������, ����� � ���.
	for (size_t i = 0; i < HousesCount - 1; ++i)
		if (s[i][Color] == Green && s[i + 1][Color] != _ && s[i + 1][Color] != White)
			return false;
	// �������� ���� ���.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Nationality] == Dane && s[i][Drink] != _ && s[i][Drink] != Tea)
			return false;
	// ���, ��� ����� Marlboro, ���� ����� � ���, ��� ���������� �����.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Cigarettes] == Marlboro && !neighborOf(i, Pet, Cat))
			return false;
	// ���, ��� ���� � ����� ����, ����� Dunhill.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Color] == Yellow && s[i][Cigarettes] != _ && s[i][Cigarettes] != Dunhill)
			return false;
	// ����� ����� Rothmans.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Nationality] == German && s[i][Cigarettes] != _ && s[i][Cigarettes] != Rothmans)
			return false;
	// ���, ��� ���� � ������, ���� ������.
	if (s[2][Drink] != _ && s[2][Drink] != Milk)
		return false;
	// ����� ����, ��� ����� Marlboro, ���� ����.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Cigarettes] == Marlboro && !neighborOf(i, Drink, Water))
			return false;
	// ���, ��� ����� Pall Mall, ���������� ����.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Cigarettes] == PallMall && s[i][Pet] != _ && s[i][Pet] != Bird)
			return false;
	// ���� ���������� �����.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Nationality] == Swede && s[i][Pet] != _ && s[i][Pet] != Dog)
			return false;
	// �������� ���� ����� � ����� �����.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Nationality] == Norwegian && !neighborOf(i, Color, Blue))
			return false;
	// ���, ��� ���������� �������, ���� � ����� ����.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Pet] == Horse && s[i][Color] != _ && s[i][Color] != Blue)
			return false;
	// ���, ��� ����� Winfield, ���� ����.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Cigarettes] == Winfield && s[i][Drink] != _ && s[i][Drink] != Beer)
			return false;
	// � ������ ���� ���� ����.
	for (size_t i = 0; i < HousesCount; ++i)
		if (s[i][Color] == Green && s[i][Drink] != _ && s[i][Drink] != Coffee)
			return false;
	// ������:
	// ��� �������� �����?
	return true;
}

bool findSolution(int y, int x)
{
	int tmp = s[y][x];
	for (int i = 0; i < 5; ++i)
	{
		s[y][x] = i;
		if (check())
		{
			const size_t newX = (x + 1) % PropertiesCount;
			const size_t newY = y + (newX != 0 ? 0 : 1);
			if (newY >= HousesCount || findSolution(newY, newX))
				return true;
		}
	}
	s[y][x] = tmp;
	return false;
}

void print()
{
	for (size_t i = 0; i < HousesCount; ++i)
	{
	    cout << i + 1 << " " <<
        ColorStr[s[i][Color]] << " "  <<
        DrinkStr[s[i][Drink]] << " "  <<
        PetStr[s[i][Pet]] << " "  <<
        CigarettesStr[s[i][Cigarettes]] << " "  <<
        NationalityStr[s[i][Nationality]] << " "  <<
        endl;
	}
}

int main(void)
{
	for (size_t i = 0; i < HousesCount; ++i)
		for (size_t j = 0; j < PropertiesCount; ++j)
			s[i][j] = _;
	if (findSolution(0, 0))
		print();
	else
		cout << "Solution is not found" << endl;

	return 0;
}
