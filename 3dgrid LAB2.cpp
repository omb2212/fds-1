#include <stdio.h>
#include <stdlib.h>


#define slices 128
#define rows 256
#define cols 256


int main(){
	FILE *fp;
	int slice, row, col, counter=1, k, i, kFlag = 0;
	
	float ***Grid_3D = (float***) malloc(slices * sizeof(float**));
	
	printf("Enter the k : ");
	scanf("%d", &k);
	
	// Intialize to 0
	for(slice = 0; slice < slices; slice++){
		Grid_3D[slice] =  (float**) malloc(rows * sizeof(float*));
		for(row=0;row<rows;row++){
			Grid_3D[slice][row] =  (float*) malloc(cols  * sizeof(float));
			for(col=0;col<cols;col++){
				Grid_3D[slice][row][col] = 0;
			}
		}
	}
	
 	// Intialize Modification
	for(slice = 0; slice < slices; slice++){
		for(row=0;row<rows;row++){
			for(col=0;col<cols;col++){
				if(col<=cols/2 && col>=cols/2-1 && row <= rows/2 && row >= rows/2-1 && slice!=slices/2){
					Grid_3D[slice][row][col] = 0.5;
				}
			}
		}
	}
	
	
	printf("Modification 1 : \n\n");
	
	
	for(slice = 0; slice < slices; slice++){
		printf("Slice : %d\n", slice);
		for(row=0;row<rows;row++){
			for(col=0;col<cols;col++){
				if(col<=cols/2 && col>=cols/2-1 && row <= rows/2 && row >= rows/2-1 && slice!=slices/2){
					printf("%.1f\t", Grid_3D[slice][row][col]);
				}else{
					printf("%.0f\t", Grid_3D[slice][row][col]);
				}
			}
			printf("\n");
		}
		printf("\n\n");
	}
	
	int temp=0;
	
	// Intialize Modification 2
	for(slice = 1; slice < slices/2; slice++){
		if(temp>=k){
			counter++;
			temp=0;
		}
		temp++;
		for(row=0;row<rows;row++){
			for(col=0;col<cols;col++){
				if(col<=(cols/2+(counter)) && col>=cols/2-(counter+1) &&
				 row <= rows/2+counter && row >= rows/2-(counter+1) && counter !=0){
					Grid_3D[slice][row][col] = 255;
				}
			}
		}
	}
	
	counter = 0;
	for(slice = slices-1; slice > slices/2; slice--){
		if(temp>=k){
			counter++;
			temp=0;
		}
		temp++;
		
		for(row=0;row<rows;row++){
			for(col=0;col<cols;col++){
				if(col<=(cols/2+(counter)) && col>=cols/2-(counter+1) &&
				 row <= rows/2+counter && row >= rows/2-(counter+1) && counter !=0){
					Grid_3D[slice][row][col] = 255;
				}
			}
		}
	}
	

	for(slice = 0; slice < slices; slice++){
		for(row=0;row<rows;row++){
			for(col=0;col<cols;col++){
				if(col<=cols/2 && col>=cols/2-1 && row <= rows/2 &&
				 row >= rows/2-1 && slice!=slices/2){
					Grid_3D[slice][row][col] = 0.5;
				}
			}
		}
	}
	
	
	
	printf("Modification 2: \n\n");
	fp = fopen("Lab2Result.csv", "w");
	for(slice = 0; slice < slices; slice++){
		fprintf(fp, "Slice : %d\n", slice);
		for(row=0;row<rows;row++){
			for(col=0;col<cols;col++){
				if(col<=cols/2 && col>=cols/2-1 && row <= rows/2 &&
				 row >= rows/2-1 && slice!=slices/2){
					fprintf(fp, "%.1f,", Grid_3D[slice][row][col]);
				}else{
					fprintf(fp, "%.0f,", Grid_3D[slice][row][col]);
				}
			}
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n\n");
	}
	fclose(fp);
	

		
	return 0;
}
