#include <stdio.h>

class puzzle
{
	public : 
	
	int sttpuzzle [4][4] = {{5,1,3,4},{2,0,7,8},{9,6,10,12},{13,14,11,15}};
	int temppuzzle [4][4];
	int multichildpuzzle[30000][4][4];
	int sutemp[4][4];
	int endpuzzle [4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
	int zeroposx,zeroposy;
	int child = 0;
	int sttchild = 0;
	int falsed;
	int falsedchild = 16;
	int falsedtempchild[4] = {0,0,0,0};
	int direction = 0;
	int directemp = 0;
		
	void createpuzzle()
	{
		int x,y;
	
		for ( y = 0; y <= 3; y++ )
		{
			for ( x = 0; x <= 3; x++ )
			{
				printf("| %i |",sttpuzzle[y][x]);
			}
		
			printf("\n");
		}
		
	}
	
	void createtemppuzzle()
	{
		int x,y;

		for ( y = 0; y <= 3; y++ )
		{
			for ( x = 0; x <= 3; x++ )
			{
				printf("| %i |",temppuzzle[y][x]);
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
				if(sttpuzzle[i][j] == 0)
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
				temppuzzle[i][j] = sttpuzzle[i][j];
			}
		}
	}
	
	void generatestt ()
	{
		for (int i = 0; i<=3; i++)
		{
			for (int j = 0; j<=3; j++)
			{
				sttpuzzle[i][j] = temppuzzle[i][j];
			}
		}
	}
	
	void chosenstate ()
	{
		for (int i = 0; i<=3; i++)
		{
			for (int j = 0; j<=3; j++)
			{
			 sttpuzzle[i][j] = temppuzzle[i][j];
			}
		}
	}
	
	void upwards ()
	{
		int tempvalue;
		
		temppuzzle[zeroposy][zeroposx] = sttpuzzle[zeroposy - 1][zeroposx];
		temppuzzle[zeroposy - 1][zeroposx] = 0;
		
	}
	
	void downwards ()
	{
		int tempvalue;
		
		temppuzzle[zeroposy][zeroposx] = sttpuzzle[zeroposy + 1][zeroposx];
		temppuzzle[zeroposy + 1][zeroposx] = 0;
		
	}
	
	void leftwards ()
	{
		int tempvalue;
		
		temppuzzle[zeroposy][zeroposx] = sttpuzzle[zeroposy][zeroposx - 1];
		temppuzzle[zeroposy][zeroposx - 1] = 0;
		
	}
	
	void rightwards ()
	{
		int tempvalue;
		
		temppuzzle[zeroposy][zeroposx] = sttpuzzle[zeroposy][zeroposx + 1];
		temppuzzle[zeroposy][zeroposx + 1] = 0;
		
	}
	
	void falsecounter ()
	{
		falsedchild = 0;
		for (int i = 0; i<=3; i++)
		{
			for (int j = 0; j<=3; j++)
			{
				if (temppuzzle[i][j] != endpuzzle[i][j])
				{
					falsedchild++;
				}
			}
		}
		printf("\nweight = %i\n",falsedchild);

	}
	
/*	void childexpander ()
	{
		int tiebreaker = 0;
		
			if (falsedchild < falsed)
			{
				if (tiebreaker != 0)
				{
					sttchild = sttchild - tiebreaker;
					tiebreaker = false;
				/	for (int j = 0; j<=3; j++)
					{
						for (int k = 0; k<=3; k++)
						{
							multchildpuzzle[sttchild][j][k] = sttpuzzle[j][k];
						
						}
					}/
				}
			
				for (int j = 0; j<=3; j++)
				{
					for (int k = 0; k<=3; k++)
					{
						sutemp[j][k] = temppuzzle[j][k];
					}
				}
				 falsed =falsedchild;
				printf("%i",falsedchild);
				
			}
			else if (falsedchild == falsed)
			{
				tiebreaker++;
				for (int j = 0; j<=3; j++)
				{
					for (int k = 0; k<=3; k++)
					{
						multchildpuzzle[sttchild][j][k] = temppuzzle[j][k];
						
					}
				}
				sttchild++;
			}
	}*/
	
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
	
	void queue ()
	{
		int falseplace = 0;
		int tempchild;
		sttchild = child;
		tempchild = child;
		
		for (int i = 0; i<=3; i++)
				{
					for (int j = 0; j<=3; j++)
					{
						if (multichildpuzzle[0][i][j] != endpuzzle[i][j])
						{
							falseplace++;
						}
					}
				}
		printf("|%i  |  %i|\n",falsedchild,falseplace);
		if (falsedchild >= falseplace)
		{
			child = 0;
			while (falsedchild >= falseplace)
			{
				child++;
				for (int i = 0; i<=3; i++)
				{
					for (int j = 0; j<=3; j++)
					{
						if (multichildpuzzle[child][i][j] != endpuzzle[i][j])
						{
							falseplace++;
						}
					}
				}	
			}
			while (tempchild != child)
			{
				for (int j = 0; j<=3; j++)
				{
					for (int k = 0; k<=3; k++)
					{
						multichildpuzzle[tempchild][j][k] = multichildpuzzle[tempchild-1][j][k];
					}
				}
				tempchild--;
			}
			for (int j = 0; j<=3; j++)
		{
			for (int k = 0; k<=3; k++)
			{
				multichildpuzzle[child][j][k] = temppuzzle[j][k];
			}
		}
		}
		else
		{
			while (tempchild != 0)
			{
				for (int j = 0; j<=3; j++)
				{
					for (int k = 0; k<=3; k++)
					{
						multichildpuzzle[tempchild][j][k] = multichildpuzzle[tempchild - 1][j][k];
					}
				}
				tempchild--;
			}
			for (int j = 0; j<=3; j++)
		{
			for (int k = 0; k<=3; k++)
			{
				multichildpuzzle[0][j][k] = temppuzzle[j][k];
			}
			printf("\n");
		}
		falsed = falsedchild;
		}
		
		child = sttchild;
		child++;
	}
	void changestt ()
	{
		int tempchild = 0;
		
		for (int j = 0; j<=3; j++)
		{
			for (int k = 0; k<=3; k++)
			{
				sttpuzzle[j][k] = multichildpuzzle[0][j][k];
			}
			printf("\n");
		}
		while (tempchild!=child)
		{
			for (int j = 0; j<=3; j++)
			{
				for (int k = 0; k<=3; k++)
				{
					multichildpuzzle[tempchild][j][k] = multichildpuzzle[tempchild + 1][j][k];
				}
			}
			tempchild++;
		}
	}
	
};

int main ()

{
	puzzle pzl;
	
	pzl.createpuzzle();
	pzl.zeroposupdater();
	pzl.generatetemp();
	pzl.falsecounter();
	
	while (pzl.falsed != 0 )
	{
		if (pzl.zeroposx < 3 && pzl.direction != 2)
		{
			int counto = 0;
			pzl.generatetemp();
			pzl.rightwards();
			pzl.createtemppuzzle();
			pzl.falsecounter();
		//	pzl.childexpander();
			pzl.queue();
			for (int j = 0; j<=3; j++)
			{
				for (int k = 0; k<=3; k++)
				{
					if (pzl.multichildpuzzle[0][j][k] == pzl.temppuzzle[j][k])
					{
						counto++;
					}
				}
			}
			if (counto == 16)
			{
				pzl.directemp = 1;
			}
			
		}
		if (pzl.zeroposx > 0 && pzl.direction != 1)
		{
			int counto = 0;
			pzl.generatetemp();
			pzl.leftwards();
			pzl.createtemppuzzle();
			pzl.falsecounter();
		//	pzl.childexpander();
			pzl.queue();
			for (int j = 0; j<=3; j++)
			{
				for (int k = 0; k<=3; k++)
				{
					if (pzl.multichildpuzzle[0][j][k] == pzl.temppuzzle[j][k])
					{
						counto++;
					}
				}
			}
			if (counto == 16)
			{
				pzl.directemp = 2;
			}
		}
		if (pzl.zeroposy < 3 && pzl.direction != 4)
		{
			int counto = 0;
			pzl.generatetemp();
			pzl.downwards();
			pzl.createtemppuzzle();
			pzl.falsecounter();
		//	pzl.childexpander();
			pzl.queue();
			for (int j = 0; j<=3; j++)
			{
				for (int k = 0; k<=3; k++)
				{
					if (pzl.multichildpuzzle[0][j][k] == pzl.temppuzzle[j][k])
					{
						counto++;
					}
				}
			}
			if (counto == 16)
			{
				pzl.directemp = 3;
			}
		}
		if (pzl.zeroposy > 0 && pzl.direction != 3)
		{
			int counto = 0;
			pzl.generatetemp();
			pzl.upwards();
			pzl.createtemppuzzle();
			pzl.falsecounter();
		//	pzl.childexpander();
			pzl.queue();
			for (int j = 0; j<=3; j++)
			{
				for (int k = 0; k<=3; k++)
				{
					if (pzl.multichildpuzzle[0][j][k] == pzl.temppuzzle[j][k])
					{
						counto++;
					}
				}
			}
			if (counto == 16)
			{
				pzl.directemp = 4;
			}
		}
	
		pzl.direction = pzl.directemp;
		pzl.changestt();
		printf("\n falsed = %i",pzl.falsed);
		printf("-----------%i",pzl.direction);
		printf("-----------%i\n\n",pzl.directemp);
		printf ("\nchild : %i",pzl.child);
		
	/*	for(int i = 0; i<= pzl.child; i++)
		{
			for (int j = 0; j<=3; j++)
			{
				for (int k = 0; k<=3; k++)
				{
					printf("| %i |",pzl.multichildpuzzle[i][j][k]);
						
					//	printf("| %i |",	pzl.sutemp[j][k]);
				}
				printf("\n");
			}
				printf("\n");
				printf("\n");
		}
		
	*/
		
		printf("\n\n");
		pzl.zeroposupdater();
		
	}
/*	for(int i = 0; i<= pzl.child; i++)
		{
			for (int j = 0; j<=3; j++)
			{
				for (int k = 0; k<=3; k++)
				{
					printf("| %i |",pzl.multichildpuzzle[i][j][k]);
						
					//	printf("| %i |",	pzl.sutemp[j][k]);
				}
				printf("\n");
			}
				printf("\n");
				printf("\n");
		}*/
	
}
