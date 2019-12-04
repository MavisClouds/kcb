#include <stdio.h>
#include <math.h>

class puzzle
{
public : 

int sttpuzzle [4][4] = {{5,1,3,4} // state awal
					   ,{9,2,6,8}
					   ,{13,10,7,11}
					   ,{0,14,15,12}};
int temppuzzle [4][4]; // penyimpan child
int multichildpuzzle[1000][4][4]; // penyimpan antrian
int endpuzzle [4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}}; // state akhir
int zeroposx,zeroposy; // penyimpan posisi x dan y pada ruang kosong
int child = 0; // penentu posisi pada array
int sttchild = 0; // tempat sementara
int falsed; // penyimpan kesalahan keping
int falsedchild = 16; // penyimpan kesalahan keping pada child
int direction = 0; // penentu arah
int directemp = 0; // penentu arah pada child
int depth[1000]; // penyimpan kedalaman
int depthcount=0; // penyimpan akhir kedalaman
int counting = 0; // penghitung
int checker = 0; // pengecek jika berganti cabang

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
		checker++; // menandai jika berganti cabang
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
	
puzzle pzl; //inisialisasi kelas dan objek

pzl.createpuzzle(); // mencetak state awal
pzl.zeroposupdater(); // mengupdate posisi kosong
pzl.generatetemp(); // mengkopi state awal ke array untuk state sementara
pzl.falsecounter(); // menghitung jumlah keping yang salah

while (pzl.falsed != 0 ) // akan terus mengulang sampai keping yang salah = 0
{
	pzl.depthcount++; // menambah kedalaman
	//membuat child yang bergerak ke kanan
	if (pzl.zeroposx < 3 && pzl.direction != 2)
	{
		int counto = 0;
		pzl.generatetemp();
		pzl.rightwards(); // penggerakkan ruang kosong ke kanan
		pzl.createtemppuzzle(); // mencetak child kanan
		pzl.falsecounter(); 
	//	pzl.childexpander();
		pzl.queue();
		//men-cek jika child yang di generate berada pada awal array
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
		//======================================================================
		// jika benar maka dilarang untuk bergerak ke kiri untuk pengulangan selanjutnya
		if (counto == 16)
		{
			pzl.directemp = 1;
		}
		
	}
	//===========================================================================================
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
	// men-cek jika cabang berubah
	if (pzl.checker == 0)
	{
		pzl.depthcount = pzl.depth[0];
	}
	pzl.checker = 0;
	printf("\ndepth = %i\n",pzl.depthcount);

	
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
// penghitung EBF

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
			printf("\nEffective Branching Factor = %lf",b);
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
