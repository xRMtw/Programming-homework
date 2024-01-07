#include<stdio.h>
#include<string.h>
#define row 8
#define column 8

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
    for( int i = 0 ; i < row; i++ ){
        for( int j = 0 ; j < column; j++ ){
            scanf("%d", &( chess[i][j] ) );
        }
    }

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
    CheckChessCanPlayOn ( chess , next ,  x ,  y , color , another_color );
    
    for( int i = 0 ; i < row ; i++ ){
        for( int j = 0 ; j < column ; j++ ){
            if ( next[i][j] != 0 )
                printf("(%d,%d) ", i, j );
        }
    }
    return 0;
}
