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
int CheckChessCanPlayOn ( int chess[row][column] , int next[row][column], int n , int m , int color , int another_color ) {
    
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
    
    if (chess[n][m] == another_color ) {
        for ( int dx = -1 ; dx < 2 ; dx++ ) {
            for ( int dy = -1 ; dy < 2 ; dy++ ) {
                
                int k=1; 
                 
                if ( chess[n+dx][m+dy] == color ) {
                    
                    while ( chess[n+k*dx][m+k*dy] == color ) {
                        
                        if ( n+k*dx<0 || n+k*dx>=8 || m+k*dy<0 || m+k*dy>=8 || chess[n+k*dx][m+k*dy]==0 ) {
                            break;
                        }
                        else {
                            k++;
                        }
                    }

                    next[n+k*dx][m+k*dy] = another_color;
                
                }
            }
        }
    }
}

int TurnOver ( int chess[row][column] , int x1 , int y1 , int color1 , int another_color1  ) {
    
    chess[x1][y1] = color1;
    for ( int dx = -1 ; dx < 2 ; dx++ ) {
        for ( int dy = -1 ; dy < 2 ; dy++ ) {
                
            int k = 1; 
                 
            if ( chess[x1+dx][y1+dy] == 2 ) {
                
                while ( chess[x1+k*dx][y1+k*dy] != 0 ) {
                    if ( chess[x1+k*dx][y1+k*dy] == 2 ) {
                        k++;
                    }
                    else if ( chess[x1+k*dx][y1+k*dy] == 1)  {
                        for ( int a = 1 ; a < k ; a++ ) {
                            chess[ x1+a*dx ][ y1+a*dy ] = 1;
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
    printf ("Enter your chess board\n");
    /*for( int i = 0 ; i < row; i++ ){
        for( int j = 0 ; j < column; j++ ){
            scanf("%d", &( chess[i][j] ) );
        }
    }*/

    int x, y, n, m;
    int color, another_color;
    
    printf("Enter (i,j) 0<=i,j<=7\n");
    scanf("%d %d", &x, &y );
    
    if( x,y < 0 || x,y > 7 )
        return 0;
    
    color = chess[x][y];
    another_color = 3 - color;

    if( color == 0 ){
        
        printf("Can't play chess\n");
        return 0;
    
    }

    for( int i = 0 ; i < row ; i++ ) {
        for( int j = 0 ; j < column ; j++ ) {
            
            if ( chess[i][j] == color || chess[i][j] == another_color ) {
                n = i, m = j;
                CheckChessCanPlayOn ( chess , next ,  n ,  m , color , another_color );
            }
        }
    }
    
    printf("White Chess Can Play on:\n");
    for( int i = 0 ; i < row ; i++ ){
        for( int j = 0 ; j < column ; j++ ){
            if ( next[i][j] == 2 )
                printf("(%d,%d) ", i, j );
        }
    }

    printf("\nBlack Chess Can Play on:\n");
    for( int i = 0 ; i < row ; i++ ){
        for( int j = 0 ; j < column ; j++ ){
            if ( next[i][j] == 1 )
                printf("(%d,%d) ", i, j );
        }
    }

    printf ("\n");

    PrintBoard( chess );

    int x1 ,y1,color1,another_color1;
    
    scanf ( "%d" , &color1 );
    another_color1 = 3 - color1;
    scanf ( "%d %d", &x1 ,&y1 );
    
    TurnOver ( chess , x1 ,y1 , color1 , another_color1 );

    PrintBoard( chess );
    
  
    return 0;
}
