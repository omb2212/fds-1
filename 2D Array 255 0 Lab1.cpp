#include <stdio.h>

#define ROWS 12
#define COLS 12

int main(){
	
	int mat[ROWS][COLS];
	
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			mat[i][j]=255;
		}
	}
	
	for(int i=0;i<ROWS/2;i++){
		for(int j=0;j<COLS;j++){
			if(j>(COLS/2-1)-i && j<=(COLS/2-1)-i + (i*2) && i <ROWS/2) mat[i][j]=0;
		}
	}
	
	int k;
	for(int i=ROWS/2,k=ROWS/2-1;i<ROWS;i++,k--){
		for(int j=0;j<COLS;j++){
			 mat[i][j]=mat[k][j];
		}
	}
	
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
