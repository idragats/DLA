/* 2D improvment DLA factal structure*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define p1 0.25
#define p2 0.50
#define p3 0.75

int main(){

	int i,j,x,y,flag,x1,y1,stop,
	M=400,
	r=200,
	min=(M-2*r)/2,
	seed=4375,
	a=0,
	b=M;
	
	
	int (*grid)[M] = malloc(sizeof(int[M][M]));


	double k;
	
	 FILE *DLA;
	
	 DLA=fopen("DLA.txt","w"); // open file

		
	
	srand(seed);
	
	//initialization grid
	



	for (i=0; i<M; i++){
	   for (j=0; j<M; j++){
	      double distance = sqrt((double)(i-r)*(i-r) + (j-r)*(j-r));
	      
              if (distance>r-0.5 && distance<r+0.5) 
			
			     
			     grid[i+min][j+min]=-1;
			     
  	 else
			   	   grid[i][j]=0;	    
       }
	   
    }
	// first particle at the center
	
	grid[M/2][M/2]=1;
	


	
	
do{
	   
	
flag=0;


 do{
		  x=a+rand()%(b-a); 
		  y=a+rand()%(b-a);
		  
	     }
		while(grid[x][y]!=-1); 
	
	//random walk 

  do{
	
    
		k=(double)rand() / (double)((unsigned)RAND_MAX + 1);	
			
				if(k<=p1) 		
				  x+=1;	
				  
				else if(k<=p2) 	
				  x-=1;
				  
				else if(k<=p3)  
				   y+=1;
				   
				 else
				    y-=1;  
				    
	 double distance = sqrt((double)(x-r)*(x-r) + (y-r)*(y-r));			    
				    
				    
		 if ( x>M-1 || x<1 || y>M-1 || y<1){
		 
		  	
		  	
			   while(grid[x][y]!=-1) {
		            x=a+rand()%(b-a); 
		            y=a+rand()%(b-a);
		  
	           }
	        	
		
           }
       
       
 	
					  
				    
	
	
	  if (grid[x+1][y]==1 || grid[x-1][y]==1 || grid[x][y+1]==1 || grid[x][y-1]==1){
	   
		  
	        grid[x][y]=1;
	        flag=1; // a new naighboor
	       
	        
	        	printf("%d %d %d \n",x,y,grid[x][y]);
	        
	        fprintf(DLA,"%d %d\n", x,y);
	      
	    
     }
     
     

     
     
     
}
    while(flag==0);



}
while (grid[x+1][y]!=-1 && grid[x-1][y]!=-1 && grid[x][y+1]!=-1 && grid[x][y-1]!=-1);

  
    free(grid);
  fclose(DLA);
   
	return 0;
}
