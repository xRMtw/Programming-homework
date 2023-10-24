#include<stdio.h>
#define row 8
#define column 8

int main(){
    
    int chess[row][column];
    
    for(int i=0 ; i < row; i++)
        for(int j=0 ; j < column; j++)
            scanf("%d",&(chess[i][j]));

    int n,m,color;
    
    printf("Enter (i,j) 0<=i,j<=7\n");
    scanf("%d %d",&n,&m);
    
    if( n,m < 0 || n,m > 7 )
        return 0;
    
    color=chess[n][m];
    
    //周圍都是沒有顏色//
    if(color == 0){
        
        printf("Can't play chess\n");
        printf("Color is %d\n",color);
 
    }
    
    //選中的棋子是白色//   
    if( color == 2){
        
        printf("Color is %d\n",color);

        //往右檢查//
        for( int i=m+1; i < column; i++ ){
            if( chess[n][i] == 0){
                break;
            }

            if( chess[n][i] == 1  && chess[n][i+1] == 0 ){
                printf("Can play on (%d,%d)\n", n , i+1 );
            }
        }

        //往左檢查//
        for( int i=m-1; i > -1; i-- ){
            if( chess[n][i] == 0){
                break;
            }

            if( chess[n][i] == 1 && chess[n][i-1] == 0 ){
                printf("Can play on (%d,%d)\n", n , i-1 );
            }
        }

        //往下檢查//
        for( int j=n+1; j < row; j++ ){
            if( chess[j][m] == 0){
                break;
            }

            if( chess[j][m] == 1 && chess[j+1][m] == 0 ){
                printf("Can play on (%d,%d)\n", j+1 , m );
            }
        }

        //往上檢查//
        for( int j=n-1; j > -1; j-- ){
            if( chess[j][m] == 0){
                break;
            }

            if( chess[j][m] == 1 && chess[j-1][m] == 0 ){
                printf("Can play on (%d,%d)\n", j-1 , m );
            }
        }

        //往右上檢查//
        for( int i=n-1, j=m+1; i > -1, j < column; i--, j++ ){
                if( chess[i][j] == 0){
                    break;
                }

                if( chess[i][j] == 1 && chess[i-1][j+1] == 0 ){
                    printf("Can play on (%d,%d)\n", i+1 , j-1 );
                }  
        }

        //往右下檢查//
        for( int i=n+1, j=m+1; i < row, j < column; i++,j++ ){
                if( chess[i][j] == 0){
                    break;
                }

                if( chess[i][j] == 1 && chess[i+1][j+1] == 0 ){
                    printf("Can play on (%d,%d)\n", i+1 , j+1 );
                }
            
        }

        //往左上檢查//
        for( int i=n-1, j=m-1; i > -1, j > -1; i--, j-- ){
                if( chess[i][j] == 0){
                    break;
                }

                if( chess[i][j] == 1 && chess[i-1][j-1] == 0 ){
                    printf("Can play on (%d,%d)\n", i-1 , j-1 );
                }
        }

        //往左下檢查//
        for( int i=n+1, j=m-1; i < row, j > -1; i++, j-- ){
                if( chess[i][j] == 0){
                    break;
                }

                if( chess[i][j] == 1 && chess[i+1][j-1] == 0 ){
                    printf("Can play on (%d,%d)\n", i-1 , j+1 );
                }
        }
    
    }
    
    //選中的棋子是黑色//
    if( color == 1){
        
        printf("Color is %d\n",color);

        //往右檢查//
        for( int i=m+1; i < column; i++ ){
            if( chess[n][i] == 0){
                break;
            }

            if( chess[n][i] == 2  && chess[n][i+1] == 0 ){
                printf("Can play on (%d,%d)\n", n , i+1 );
            }
        }

        //往左檢查//
        for( int i=m-1; i > -1; i-- ){
            if( chess[n][i] == 0){
                break;
            }

            if( chess[n][i] == 2 && chess[n][i-1] == 0 ){
                printf("Can play on (%d,%d)\n", n , i-1 );
            }
        }

        //往下檢查//
        for( int j=n+1; j < row; j++ ){
            if( chess[j][m] == 0){
                break;
            }

            if( chess[j][m] == 2 && chess[j+1][m] == 0 ){
                printf("Can play on (%d,%d)\n", j+1 , m );
            }
        }

        //往上檢查//
        for( int j=n-1; j > -1; j-- ){
            if( chess[j][m] == 0){
                break;
            }

            if( chess[j][m] == 2 && chess[j-1][m] == 0 ){
                printf("Can play on (%d,%d)\n", j-1 , m );
            }
        }

        //往右上檢查//
        for( int i=n-1, j=m+1; i > -1, j < column; i--, j++ ){
                if( chess[i][j] == 0){
                    break;
                }

                if( chess[i][j] == 2 && chess[i-1][j+1] == 0 ){
                    printf("Can play on (%d,%d)\n", i+1 , j-1 );
                }
        }

        //往右下檢查//
        for( int i=n+1, j=m+1; i < row, j < column; i++, j++ ){
                if( chess[i][j] == 0){
                    break;
                }

                if( chess[i][j] == 2 && chess[i+1][j+1] == 0 ){
                    printf("Can play on (%d,%d)\n", i+1 , j+1 );
                }
        }

        //往左上檢查//
        for( int i=n-1, j=m-1; i > -1, j > -1; i--, j-- ){
                if( chess[i][j] == 0){
                    break;
                }

                if( chess[i][j] == 2 && chess[i-1][j-1] == 0 ){
                    printf("Can play on (%d,%d)\n", i-1 , j-1 );
                }
        }

        //往左下檢查//
        for( int i=n+1, j=m-1; i < row, j > -1; i++, j-- ){
                if( chess[i][j] == 0){
                    break;
                }

                if( chess[i][j] == 2 && chess[i+1][j-1] == 0 ){
                    printf("Can play on (%d,%d)\n", i-1 , j+1 );
                }
        }
    
    }

    return 0;
}