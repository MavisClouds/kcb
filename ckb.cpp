#include <stdio.h>
#include <math.h>

class puzzle
{
public : 

int sttpuzzle [4][4] = {{0,1,3,4}
					   ,{5,2,6,8}
					   ,{9,10,7,11}
					   ,{13,14,15,12}};
int temppuzzle [4][4];
int multichildpuzzle[1000][4][4];
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
int depth[1000];
int depthcount=0;
int counting = 0;
int checker = 0;

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
	printf("\njumlah keping salah = %i\n",falsedchild);

}


void queue ()
{
	int falseplace = 0;
	int tempchild;
	sttchild = child;
	tempchild = child;
	//menghitung keping yang salah pada antrian pertama
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
	//-----------------------------------------------------------------------------------
	//
	if (falsedchild >= falseplace)
	{
		child = 0;
//menentukan tempat mana yang akan ditempati child baru	
		while (falsedchild >= falseplace)
		{
			falseplace = 0;
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
//================================================================================
//mengosongkan tempat yang akan ditempati child baru
		while (tempchild != child)
		{
			for (int j = 0; j<=3; j++)
			{
				for (int k = 0; k<=3; k++)
				{
					multichildpuzzle[tempchild][j][k] = multichildpuzzle[tempchild-1][j][k];
					depth[tempchild] = depth[tempchild-1]; 
				}
			}
			tempchild--;
		}
//==============================================================================================
//penempatan child baru
		for (int j = 0; j<=3; j++)
		{
			for (int k = 0; k<=3; k++)
			{
				multichildpuzzle[child][j][k] = temppuzzle[j][k];
				depth[child] = depthcount;
			}
		}
	}
//=================================================================================================
//penempatan child yang jumlah keping salahnya lebih kecil pada array 0
	else
	{
		checker++;
		while (tempchild != 0)
		{
			for (int j = 0; j<=3; j++)
			{
				for (int k = 0; k<=3; k++)
				{
					multichildpuzzle[tempchild][j][k] = multichildpuzzle[tempchild - 1][j][k];
					depth[tempchild] = depth[tempchild - 1];
				}
			}
			tempchild--;
		}
		for (int j = 0; j<=3; j++)
		{
			for (int k = 0; k<=3; k++)
			{
				multichildpuzzle[0][j][k] = temppuzzle[j][k];
				depth[0] = depthcount;
			}
			printf("\n");
		}
		falsed = falsedchild;
	}
//======================================================================================================================
//pengembalian nilai child
	child = sttchild;
	child++;
//================================================
}
//mengganti node yang akan dibuka
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
				depth[tempchild] = depth[tempchild + 1];
			}
		}
		tempchild++;
	}
}
//=======================================================================================
};

int main ()

{
double maxError=0.01; // the maximum error we accept from a solution 
double delta=0.01;    // how much we change our tested ebf each iteration   
int signOfError=0;    // the sign of the difference between N+1 and 1+b+b^2+......+b^d
double b=0; 
	
puzzle pzl;

pzl.createpuzzle();
pzl.zeroposupdater();
pzl.generatetemp();
pzl.falsecounter();

while (pzl.falsed != 0 )
{
	pzl.depthcount++;
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
	}
	
	if (pzl.checker == 0)
	{
		pzl.depthcount = pzl.depth[0];
	}
	printf("\ndepth = %i",pzl.depthcount);
/*	for (int i = 0; i<= 100; i++)
	{
		if (pzl.depth[i] == 0)
		{
			pzl.depth[counting] = counting;
		}
	}*/
	
	pzl.direction = pzl.directemp;
	pzl.changestt();
	printf("\n falsed = %i",pzl.falsed);
	printf("------------------------------------------------------------");

	
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

while (true) {        // search for b starts here
            // compute the expression 1+b+b^2+......+b^d
            double sum=1;
            for (int i=1; i<pzl.depthcount+1; i++) {
                sum += pow(b, (double)i);
            }
            double error=sum-(1+(double)pzl.child);
            // save previous sign of error
            int signOfPreviousError = signOfError;
            // determine the new sign of error
            if (error<0.0) // negative
                signOfError=-1;
            else // positive
                signOfError=+1;
            /* if the error calculated above is greater than the maximum acceptable error, then check if sign of error
               was changed, if so that means loop missed the root that we are looking for, then decrease b by delta and 
               decrease delta to catch root in next search if sign of error wasnt change then increase 'b' by delta
               otherwise if error is smaller than the limit return the effective branch factor */
            if (abs(error)>maxError) { // error is big
                if (signOfPreviousError==signOfError || signOfPreviousError==0) {  
                    b+=delta;   // taking another step towards solution
                } else {        // change of sign which means that we jumped over the minima
                    b-=delta;   // go back
                    delta/=2;   // take smaller steps
                    signOfError=signOfPreviousError;  // undo change of sign
                }
            } else
			{ 
			// error is small, let's return current estimate
			printf("\nb = %i",b);
                return(b);
            }
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
