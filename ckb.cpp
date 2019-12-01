#include <stdio.h>

class puzzle
{
	public : 
	
	int sttpuzzle [4][4][4] = {{{5,1,3,4},{2,0,7,8},{9,6,10,12},{13,14,11,15}}};
	int temppuzzle [4][4][4];
	int beforepuzzle[4][4];
	int endpuzzle [4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
	int zeroposx,zeroposy;
	int child = 0;
	int sttchild = 0;
	int falsed = 16;
	int falsedchild = 16;
	int falsedtempchild[4] = {0,0,0,0};
		
	void createpuzzle()
	{
		int x,y;
	
		for ( y = 0; y <= 3; y++ )
		{
			for ( x = 0; x <= 3; x++ )
			{
				printf("| %i |",sttpuzzle[sttchild][y][x]);
			}
		
			printf("\n");
		}
		
	}
	
	void createtemppuzzle()
	{
		int x,y;
	printf("%i",child);
		for ( y = 0; y <= 3; y++ )
		{
			for ( x = 0; x <= 3; x++ )
			{
				printf("| %i |",temppuzzle[child][y][x]);
			}
		
			printf("\n");
		}
	}
	
	void zeroposupdater()
	{
		for (int i = 0; i<=3; i++)
		{
			for (int j = 0; j<=3; j++)
			{
				if(sttpuzzle[sttchild][i][j] == 0)
				{
					zeroposx = j; 
					zeroposy = i;
				}
			}
		}
	}
	
	void generatetemp ()
	{
		for (int i = 0; i<=3; i++)
		{
			for (int j = 0; j<=3; j++)
			{
				temppuzzle[child][i][j] = sttpuzzle[sttchild][i][j];
			}
		}
	}
	
	void chosenstate ()
	{
		for (int i = 0; i<=3; i++)
		{
			for (int j = 0; j<=3; j++)
			{
			 sttpuzzle[sttchild][i][j] = temppuzzle[child][i][j];
			}
		}
	}
	
	void upwards ()
	{
		int tempvalue;
		
		temppuzzle[child][zeroposy][zeroposx] = sttpuzzle[sttchild][zeroposy - 1][zeroposx];
		temppuzzle[child][zeroposy - 1][zeroposx] = 0;
		
	}
	
	void downwards ()
	{
		int tempvalue;
		
		temppuzzle[child][zeroposy][zeroposx] = sttpuzzle[sttchild][zeroposy + 1][zeroposx];
		temppuzzle[child][zeroposy + 1][zeroposx] = 0;
		
	}
	
	void leftwards ()
	{
		int tempvalue;
		
		temppuzzle[child][zeroposy][zeroposx] = sttpuzzle[sttchild][zeroposy][zeroposx - 1];
		temppuzzle[child][zeroposy][zeroposx - 1] = 0;
		
	}
	
	void rightwards ()
	{
		int tempvalue;
		
		temppuzzle[child][zeroposy][zeroposx] = sttpuzzle[sttchild][zeroposy][zeroposx + 1];
		temppuzzle[child][zeroposy][zeroposx + 1] = 0;
		
	}
	
	void falsecounter ()
	{
		falsedchild = 0;
		for (int i = 0; i<=3; i++)
		{
			for (int j = 0; j<=3; j++)
			{
				if (temppuzzle[child][i][j] != endpuzzle[i][j])
				{
					falsedchild++;
				}
			}
		}
		printf("\nweight = %i",falsedchild);

	}
	
/*	void movechildnum ()
	{
		if (zeroposx - 1 <= 0 && zeroposx + 1 >= 3 && zeroposy - 1 >= 0 && zeroposy + 1 <= 3)
		{
			upwards();
			downwards();
			leftwards();
			rightwards();
		}
	}*/
};

int main ()
{
	puzzle pzl;
	
	pzl.createpuzzle();
	pzl.zeroposupdater();
	pzl.generatetemp();
	pzl.falsecounter();

	e

}
