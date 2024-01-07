#include<stdio.h>
#include<string.h>
#define row 8
#define column 8
int PrintBoard ( int chess[row][column] ) {
    
    for ( int i = 0; i < row ; i++ ) {
        for ( int j = 0; j < column ; j++ ) {
            printf ("%d ", chess[i][j] );
        }
        printf ("\n");
    }
    printf ("\n");

}
int CheckChessCanPlayOn ( int chess[row][column] , int next[row][column] , int color , int another_color ) {
    
    for( int n = 0 ; n < row ; n++ ) {
        for( int m = 0 ; m < column ; m++ ) {
            
            if ( chess[n][m] == color ) {
                for ( int dx = -1 ; dx < 2 ; dx++ ) {
                    for ( int dy = -1 ; dy < 2 ; dy++ ) {
                            
                        int k=1;
                        
                        if ( chess[n+dx][m+dy] == another_color ) {
                                
                            while ( chess[n+k*dx][m+k*dy] == another_color ) {
                                    
                                if ( n+k*dx<0 || n+k*dx>=8 || m+k*dy<0 || m+k*dy>=8 || chess[n+k*dx][m+k*dy]==0 ) {
                                    break;
                                }
                                else {
                                    k++;
                                }
                            }
                            
                            next[n+k*dx][m+k*dy] = color;
                        }
                            
                    }
                }
            }
        }
    }
}

int TurnOver ( int chess[row][column] , int x , int y , int color , int another_color  ) {
    
    chess[x][y] = color;
    for ( int dx = -1 ; dx < 2 ; dx++ ) {
        for ( int dy = -1 ; dy < 2 ; dy++ ) {
                
            int k = 1; 
                 
            if ( chess[x+dx][y+dy] == another_color ) {
                
                while ( chess[x+k*dx][y+k*dy] != 0 ) {
                    if ( chess[x+k*dx][y+k*dy] == another_color ) {
                        k++;
                    }
                    else if ( chess[x+k*dx][y+k*dy] == color )  {
                        for ( int a = 1 ; a < k ; a++ ) {
                            chess[ x+a*dx ][ y+a*dy ] = color;
                        }
                        break;
                    }
                    else {
                        k = 0;
                        break;
                    }
                }
            }
        }
    }
}

int AIPlayer ( int chess[row][column] , int next[row][column] , int color , int another_color , int *X1 , int *Y1 ) {
   
    int MaxK = 0;
    
    for ( int i = 0 ; i < row ; i ++ ) { 
        for ( int j = 0 ; j < column ; j ++ ) { 
           
            if ( next[i][j] == color ) {
                
                for ( int dx = -1 ; dx < 2 ; dx++ ) {
                    for ( int dy = -1 ; dy < 2 ; dy++ ) {
                
                        int k = 1; 
            
                        if ( chess[i+dx][j+dy] == another_color ) {
                                
                            while ( chess[i+k*dx][j+k*dy] != color ) {
                                    
                                if ( i+k*dx<0 || i+k*dx>=8 || j+k*dy<0 || j+k*dy>=8 || chess[i+k*dx][j+k*dy] == 0 ) {
                                    break;
                                }
                                else {
                                    k++;
                                }
                            
                            }
                            if ( k > MaxK ) { 
                                MaxK = k;
                                *X1 = i;
                                *Y1 = j;
                            }
                        }

                    }
                }
            }
        }
    }
}

int main ( ) {
    
    int chess[row][column] = {{0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0},
                              {0,0,0,1,2,0,0,0},
                              {0,0,0,2,1,0,0,0},
                              {0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0}
                        };
    
    int next[row][column] = {};
    memset(next , 0 ,sizeof(next));

    int x, y;
    int color, another_color;
        
    int Count = 60;

    while ( Count != 0 ) {
        
        color = 1;
        another_color = 3 - color;

        printf ( "Black is Your Turn\n");
        PrintBoard ( chess );
        CheckChessCanPlayOn ( chess , next , color , another_color );

        printf("1 Black Chess Can Play on:\n");
        for( int i = 0 ; i < row ; i++ ){
            for( int j = 0 ; j < column ; j++ ){
                if ( next[i][j] == 1 )
                printf("(%d,%d) ", i, j );
            }
        }
        
        printf("\nEnter (x,y) 0<=(x,y)<=7\n");
        scanf ( "%d %d" ,&x ,&y);   
        TurnOver ( chess , x ,y , color , another_color );
        
        memset(next , 0 ,sizeof(next));
        
        color = 2;
        another_color = 3 - color;
        
        CheckChessCanPlayOn ( chess , next , color , another_color );

        printf ( "White is PC Turn\n");
        
        int *X1 , *Y1 ;
        AIPlayer ( chess , next , color , another_color , X1 , Y1 );
        
        int X2 = *X1,Y2 = *Y1;
        printf ("PC play on (%d,%d)\n", X2 ,Y2 );
        
        TurnOver ( chess , X2 ,Y2 , color , another_color );

        Count -=2;

    }
    
    /*int CountWhite = 0, CountBlack = 0;
    
    for ( int i = 0 ; i < row ; i++ ) {
        for ( int j = 0 ; j < column ; j++ ) {
            if ( chess[i][j] == 1 ) {
                CountBlack ++;
            }
            else { 
                CountWhite ++;
            }
        }
    }
    printf ("GameOver");
    
    if ( CountBlack > CountWhite ) {
        printf ( "Black Win %d:%d",CountBlack,CountWhite);
    }
    else {
        printf ( "White Win %d:%d",CountWhite,CountBlack);
    }*/
    
    
    return 0;
}
