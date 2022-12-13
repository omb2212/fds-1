
#include <stdio.h>
#include <stdlib.h>

// Define the matrix size here
#define SLICE 128
#define ROWS 256
#define COLS 256


int main()
{
    int slice, row, col, r_num, curr_pos;
    FILE *raw_fp, *grid_fp, *grid_fp2, *output_fp;
    char ch, c2, c3;

// Part 1: Creating files

    raw_fp = fopen("raw.txt", "w");
    for(slice=0;slice<SLICE; slice++){
        for(row=0;row<ROWS; row++){
            for(col=0;col<COLS; col++){            	
                fprintf(raw_fp, "%d,", (rand() % + 26) + 65);
            }
        }
    }
    fclose(raw_fp);

    raw_fp = fopen("raw.txt", "r");
    grid_fp = fopen("grid.csv", "w");
 
    for(slice=0;slice<SLICE; slice++){
        for(row=0;row<ROWS; row++){
            for(col=0;col<COLS; col++){
                fscanf(raw_fp, "%d,", &r_num);
                ch = (char) r_num;
                if(col == (COLS-1)){
                	fprintf(grid_fp, "%c\n", ch );
				}else{
					fprintf(grid_fp, "%c,", ch );
				}
            }
        }
    }
    fclose(grid_fp);
	fclose(raw_fp);


// To run the file first uncomment below code and generate raw file and grid.txt
// Part 2 : Searching



	grid_fp = fopen("grid.csv", "r");
	output_fp = fopen("output.txt", "w");

	for(slice=0;slice<SLICE; slice++){
        for(row=0;row<ROWS; row++){
            for(col=0;col<COLS; col++){
                if(col == (COLS-1)){
                	fscanf(grid_fp, "%c\n", &ch);
				}else{
					fscanf(grid_fp, "%c,", &ch);
				}
            	curr_pos = ftell(grid_fp);
				if(ch == 'F'){
					fseek(grid_fp, COLS*2-1, 1);
					if(col == (COLS-1)){
	                	fscanf(grid_fp, "%c\n", &c2);
					}else{
						fscanf(grid_fp, "%c,", &c2);
					}
					if(c2 == 'D'){
						fseek(grid_fp, COLS*2-1, 1);
						if(col == (COLS-1)){
		                	fscanf(grid_fp, "%c\n", &c3);
						}else{
							fscanf(grid_fp, "%c,", &c3);
						}
						if(c3 == 'S'){
							fprintf(output_fp, "FDS found at location as follows\nslice: %d\nrow: [%d, %d, %d]\ncol: %d\n\n", slice, row, row+1, row+2, col);
						}
					}	
				}
				fseek(grid_fp, curr_pos, 0);
			}
		}
	}
	
	fclose(output_fp);	
    fclose(grid_fp);
    
	printf("Done, checkout the output.txt!");
    return 0;
}
