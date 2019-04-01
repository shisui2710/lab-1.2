#include "header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[50];
	int n = 0;

	ofstream fout("complex.txt");
	if (!fout.is_open())
		cout << "Невозможно открыть файл.\n";
	else
	{
		cout << "Введите количество комплексных чисел." << endl;
		cin >> n;

		cout << "Введите комплексные числа, каждое с новой строчки, где первое число - x, а второе - у." << endl;

		for (int i = 0; i < n + 1; i++)
		{
            cin.getline(str, 50);
			fout << str << endl;
		}
		fout.close();
	}

	ifstream fin("complex.txt");
	if (!fin.is_open())
		cout << "Невозможно открыть файл!\n";
	else
	{
		complex *a = new complex[n];

		for (int i = 0; i < n; i++)
		{
			a[i].x = 0;
			a[i].y = 0;
		}

		char s;

		int p = 0, e = -1, m = 1;

		while (fin.get(s))
		{
			switch (s)
			{
                case ' ':
                p = 1; a[e].x = a[e].x * m; m = 1;
                break;

                case '\n':
                if (e > -1)
					a[e].y = a[e].y * m; m = 1;
				e++; p = 0;
				break;
                case '-':
                m = -1;
				break;
                default:
                if (e > -1)
				{
					if(p == 0)
						a[e].x = (a[e].x + s - 48) * 10;
					else
						a[e].y = (a[e].y + s - 48) * 10;
				}
			}
		}
		fin.close();

		for (int i = 0; i < n; i++)
		{
			a[i].x /= 10;
			a[i].y /= 10;
			cout << endl;
			print(a[i].x, a[i].y);
			cout << endl;
		}
		float mod = sqrt(a[0].x * a[0].x + a[0].y * a[0].y);
		int k = 0;
		for (int i = 1; i < n; i++)
			if (sqrt(a[i].x * a[i].y + a[i].x * a[i].y) > mod)
			{
				mod = sqrt(a[i].x * a[i].x + a[i].y * a[i].y);
				k = i;
			}
		cout << endl << k << endl;
		print(a[k].x, a[k].y);
		cout << endl;
        cout << "Наибольший модуль: " << mod << endl;
		delete a;
    }
	return 0;
}


