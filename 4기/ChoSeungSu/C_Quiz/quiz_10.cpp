# include <stdio.h>

int main()
{
    char object[170][170][6] = {0, };
    
    // 3000m x 3000m x 2m 공간 
    // 31.8cm의 상자 

    int i , j , k;
    char num = 1; 

    for (i =0 ; i<170; i++)
    {   
        for (j=0; j<170; j++)
        {
            for(k=0; k<6 ; k++)
            {
                object[i][j][k] = num;
            }
        }
    }
}

