#include<stdio.h>
#include<omp.h>
#include<math.h>
#include<stdlib.h>



double f(double x, double y){
  return 10.*exp(-0.5*sqrt(pow((x-0.5),2.) +pow((y-0.5),2.)));
}



int main(int argc, char** argv){

  //FILE *fp;
  int n=200,i,j,N,iter;
  double h,x0,y0,error,tolerance,sum;
  double uold[n][n],unew[n][n],x[n],y[n]; 
  x0=0;
  y0=0;
  error=pow(10,-7);
  tolerance=10.0;
  //fp= fopen("poision.dat","w");
  h=1./n;
  N= strtol(argv[1], NULL, 10);
  // Initialize the data
#pragma omp parallel num_threads(N) private(i,j) shared(n,unew,uold,x0,y0,x,y,h,tolerance,error) reduction(+:sum,iter) default(none)
  {
#pragma omp for collapse(2) 
    for(i=0;i<n;i++)
      {
	
	for(j=0;j<n;j++)
	  {
	    unew[i][0]=1.0;
	    unew[i][199]=1.0;
	    x[i]=x0+i*h;
	    y[i]=y0+i*h;
	    uold[i][j]=1.0;	  
	    unew[0][j]=1.0;
	    unew[199][j]=1.0;
	    
	  }
      }
    // Iterative process
    iter=0;
    while(tolerance>=error)
      {
#pragma omp for collapse(2)
	for(i=1;i<n-1;i++)
	  {	  
	    for(j=1;j<n-1;j++)
	      {
		unew[i][j]=(1./4.)*(uold[i-1][j]+uold[i+1][j]+uold[i][j-1]+uold[i][j+1]-pow(h,2.)*f(x[i],y[j]));
	      }
	  }
	sum=0;
#pragma omp for collapse(2)
	for(i=1;i<n-1;i++)
	  {
	    for(j=1;j<n-1;j++)
	      {
		sum=sum+fabs(unew[i][j]-uold[i][j]);
	      }
	  }
	tolerance=(1./((n-2)*(n-2)))*sum;
#pragma omp for collapse(2)
	for(i=0;i<n;i++)
	  {
	    for(j=0;j<n;j++)
	      {
		uold[i][j]=unew[i][j];
	      }
	  }
	iter=iter+1;
      }
  }
  printf("number of iterations:%d\n",iter);
  printf("Value at the center:%2.5f\n",unew[n/2][n/2]);
  
  /* for(i=0;i<n;i++) */
  /*   { */
  /*     fprintf(fp,"\n"); */
  /*     for(j=0;j<n;j++) */
  /* 	{ */
  /* 	  fprintf(fp,"%2.5f\t",unew[i][j]); */
  /* 	} */
  /*   } */ 
  return 0;
}
