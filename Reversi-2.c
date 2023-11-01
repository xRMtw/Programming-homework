#include<stdio.h>
#define row 8
#define column 8

int CheckChessCanPlayOn ( int chess[row][column] , int next[row][column], int n , int m , int color , int another_color ){

    if( chess[n][m] == 0 ){
        
        next[n][m] = 0;
    
    }
    else{
        //往右檢查//
        for( int i = m + 1; i < column; i++ ){
            if( chess[n][i] == 0){
                break;
            }

            if( chess[n][i] == another_color  && chess[n][i+1] == 0 ){
                next[n][i+1] = color;
            }
        }

        //往左檢查//
        for( int i = m - 1; i > -1; i-- ){
            if( chess[n][i] == 0){
                break;
            }

            if( chess[n][i] == another_color && chess[n][i-1] == 0 ){
                next[n][i-1] = color;
            }
        }

        //往下檢查//
        for( int j = n + 1; j < row; j++ ){
            if( chess[j][m] == 0){
                break;
            }

            if( chess[j][m] == another_color && chess[j+1][m] == 0 ){
                next[j+1][m] = color;
            }
        }

        //往上檢查//
        for( int j = n - 1; j > -1; j-- ){
            if( chess[j][m] == 0){
                break;
            }

            if( chess[j][m] == another_color && chess[j-1][m] == 0 ){
                next[j-1][m] = color;
            }
        }

        //往右上檢查//
        for( int i = n - 1, j = m + 1; i > -1, j < column; i--, j++ ){
                if( chess[i][j] == 0){
                break;
                }

                if( chess[i][j] == another_color && chess[i-1][j+1] == 0 ){
                    next[i-1][j+1] = color;
                }  
        }

        //往右下檢查//
        for( int i = n + 1, j = m + 1; i < row, j < column; i++, j++ ){
                if( chess[i][j] == 0){
                    break;
                }

                if( chess[i][j] == another_color && chess[i+1][j+1] == 0 ){
                    next[i+1][j+1] = color;
                }       
        }

        //往左上檢查//
        for( int i = n  -1, j = m - 1; i > -1, j > -1; i--, j-- ){
                if( chess[i][j] == 0){
                    break;
                }

                if( chess[i][j] == another_color && chess[i-1][j-1] == 0 ){
                    next[i-1][j-1] = color;
                }
        }

        //往左下檢查//
        for( int i = n + 1, j = m - 1; i < row, j > -1; i++, j-- ){
                if( chess[i][j] == 0){
                    break;
                }

                if( chess[i][j] == another_color && chess[i+1][j-1] == 0 ){
                    next[i+1][j-1] = color;
                }
        }
    
    }
}

int main(){
    
    int chess[row][column];
    int next[row][column] = {};

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

    for( int i = 0 ; i < row ; i++ ){
        for( int j = 0 ; j < column ; j++ ){
            if ( chess[i][j] == color )
                n = i, m = j;
                CheckChessCanPlayOn ( chess , next ,  n ,  m , color , another_color );
        }
    }

    color = another_color;
    another_color = 3- color;
    n = 0 , m = 0;

    for( int i = 0 ; i < row ; i++ ){
        for( int j = 0 ; j < column ; j++ ){
            if ( chess[i][j] == color )
                n = i, m = j;
                CheckChessCanPlayOn ( chess , next ,  n ,  m , color , another_color );
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
    
    return 0;
}
