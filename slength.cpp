
#include <fstream>;
#include <string>;

using namespace std;

struct unit{
	char uname[10];
	char pname[10];
	double uvalue;
}cUnit[10];


FILE *fin = freopen("input.txt","r",stdin);
FILE *fout = freopen("output.txt","w",stdout);

char* getPlural(char* src)
{
	if(strcmp(src,"mile")==0)
		return "miles";

	if(strcmp(src,"yard")==0)
		return "yards";

	if(strcmp(src,"inch")==0)
		return "inches";

	if(strcmp(src,"foot")==0)
		return "feet";

	if(strcmp(src,"fath")==0)
		return "faths";

	if(strcmp(src,"furlong")==0)
		return "furlong";

}

double findV(char* str)
{
	for(int i=0;i<6;i++)
	{
		if(strcmp(cUnit[i].uname,str)==0||strcmp(cUnit[i].pname,str)==0)
			return cUnit[i].uvalue;
	}
}

int main()
{
	char* tmp = new char[50];
	char c,op='+';
	int i=0;
	double d=0.0, result=0.0;

	fprintf(fout,"417533880@163.com\n\n");


	while(i<6)
	{
		fscanf(fin,"%s",tmp);

		fscanf(fin,"%s",tmp);

		strcpy(cUnit[i].uname,tmp);
		strcpy( cUnit[i].pname , getPlural(tmp));

		fscanf(fin,"%s",tmp);

		cUnit[i].uvalue = 0.01;
		fscanf(fin,"%lf",&cUnit[i].uvalue);

		fscanf(fin,"%s",tmp);
		i++;
	}

	i=0;

	while(i<10)
	{
		fscanf(fin,"%lf %s\n",&d,tmp);
		char c = fin->_ptr[0];

		if(d!=0)
		{
			if(op=='+')
				result+=d*findV(tmp);
			else
				result-=d*findV(tmp);
		}

		if(c!='+'&&c!='-')
		{
			fprintf(fout,"%.2lf m\n",result);
			result=0;
			i++;
			op='+';
			continue;
		}

		fscanf(fin, "%c",&op);
	}
	return 0;
}