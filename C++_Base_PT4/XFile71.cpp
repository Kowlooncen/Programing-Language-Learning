#include "pt4.h"
#include <fstream>
#include <stdlib.h>
using namespace std;

struct Date{
	char day[2];
	char month[2];
	char year[4];
};

void Solve()
{
    Task("XFile71");
    
    string s;
    
    pt >> s;
    
    fstream f(s, ios::binary | ios::in);
	
	
	Date date[100];
	
	int i = 0;
	
	while(f.peek()!=-1)
	{
		char x;
		f.read((char*)&x, sizeof(x));	
		if(x == ' ')
			continue;
			
		
		for(int j = 0;j < 10; j++)
		{
			if(j < 2) 
			{
				date[i].day[j] = x;
			}
			else if(j > 2 && j < 5)
			{
				date[i].month[j - 3] = x;
			}
			else if(j > 5 && j < 10)
			{
				date[i].year[j - 6] = x;
			} 
			f.read((char*)&x,sizeof(x));
		}
		i++;
	}
	
	int min_y = 2022;
	int min_m = 12;
	int min_d = 31;
	int m;
	int v=0;
	
	for(int k = 0; k < i; k ++)
	{
		int month = (date[k].month[0]-'0')*10+(date[k].month[1]-'0');
		int day = (date[k].day[0]-'0')*10+(date[k].day[1]-'0');
		if(month >= 3 && month <= 5)
		{
			v=1;
			int year = (date[k].year[0]-'0')*1000+(date[k].year[1]-'0')*100+(date[k].year[2]-'0')*10+(date[k].year[3]-'0')*1;
			if(year < min_y)
			{
				m=k;
				min_y = year;
				min_m = month;
				min_d = day;
			}
			else if(year == min_y)
			{
				if(month < min_m)
				{
					m = k;
					min_m = month;
					min_d = day;
				}
				else if(month == min_m)
				{
					if(day < min_d)
					{
						min_d = day;
						m = k;
					}
				}
			}
		}
	}
	
	if(v==0)
	{
		pt << "";
		exit(1);
	}
	
	char ch[11];
	int n = 0;
	for(int k = 0; k < 10; k++)
	{
		if(k==2) 
		{
			ch[k]='/';
			n--;
		}
		else if(k==5)
		{
			ch[k]='/';
			n--;
		}
		else{
			ch[k] = date[m].day[n];			
		}	
		n++;
	}
	
//	Show(ch);
	pt << ch;	
//	pt << date[m].day[0] << date[m].day[1] << "\\" <<date[m].month[0] <<date[m].month[1] << "\\" << date[m].year ; 
}
