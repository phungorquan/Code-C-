#include <iostream>
using namespace std;

void Xuat(int i,int p[], int stop[],int start[])
{
	cout << "   " << p[i] << "\t\t\t" << start[i] << "\t\t" << stop[i] << endl;
}

int main()
{
	int p[10], burst[10] = { 0 }, start[10] = { 0 }, stop[10] = { 0 }, qtum, n;
	
	cout << "Bao muon nhap bao nhieu process : ";
	cin >> n;
	cout << "Nhap vao quantum time : ";
	cin >> qtum;

	int flag, max = burst[0]; // set flag de tru di gia tri max den khi = 0 -> stop
	for (int i = 0; i < n; i++)
	{
		cout << "Ten process: ";
		cin >> p[i];
		cout << "Burst time process " << p[i] << " = ";
		cin >> burst[i];
		while (burst[i] < 0)
		{
			cout << "Burst time phai lon hon 0 , vui long nhap lai !!!" << endl;
			cout << "Burst time process " << p[i] << " = ";
			cin >> burst[i];
		}
		if (max < burst[i])
		{
			max = burst[i];
			flag = i;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (burst[i - 1] < qtum)
		{
			start[i] = burst[i - 1]+start[i-1];
		}
		else start[i] = start[i - 1] + qtum;
		//wtime[i] = wtime[i - 1] + qtum;
	}
	cout << "Process \t   Start time \t   Stop time" << endl;
	
	int temp = 0;

	// Chay lan dau de lay cac gia tri can thiet
	for (int i = 0; i < n; i++)
	{
		if (burst[i] >= qtum)
		{
			burst[i] -= qtum;
			stop[i] = start[i] + qtum;
			start[i] = temp;
			temp = stop[i];
			Xuat(i, p, stop, start);
		}
		else
		{
			stop[i] = temp + burst[i];
			start[i] = temp;
			temp = stop[i];
			burst[i] = 0;
			Xuat(i, p, stop, start);
		}

		if (flag == i)
		{
			max -= qtum;
		}
	}

	while (max > 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (burst[i] > 0)
			{	
					if (burst[i] >= qtum)
					{
						burst[i] -= qtum;
						//wtime[i] += abs(temp - stop[i]);
						stop[i] = temp + qtum; 
						start[i] = temp;
						temp = stop[i];
						Xuat(i, p, stop, start);
					}
					else
					{
						//wtime[i] += abs(temp - stop[i]);
						stop[i] = temp + burst[i];
						start[i] = temp;
						temp = stop[i];
						burst[i] = 0;
						Xuat(i, p, stop, start);
					}
			}
			if (flag == i)
			{
				max -= qtum;
			}
		}
	}
	system("PAUSE");
}
