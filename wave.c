#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>


#define PI 3.14159265359


double boundary(double x){
  return sin(PI*x);
}

int main(int argc, char** argv){
  //printf("here1\n");
  FILE* fp;
  int Nx=200,Nt,i,j,number_threads;
  double h,temp,x0,t0,error,sum,c;
  double dt,alpha,dx;
  number_threads= strtol(argv[1], NULL, 10);
  t0=0;
  x0=0;
  alpha=sqrt(2)/PI;
  dx=12./Nx;
  dt=0.5*dx/alpha;
  Nt=(int) round((5.*PI)/dt);
  c=alpha*dt/dx;
  double *x,*t;
  double **u=malloc(Nx*sizeof(double) );
  x = (double*) malloc(Nx*sizeof(double));
  t = (double*) malloc(Nt*sizeof(double));
  for(i=0;i<Nx;i++){
    u[i]=(double*) malloc(Nt*sizeof(double));
  }
  //printf("here2\n");
#pragma omp parallel num_threads(number_threads) private(i,j) shared(Nx,Nt,x0,t0,x,t,dx,dt) default(none)
  {
#pragma omp for
    for(i=0;i<Nx;i++){
      x[i]=x0+i*dx;
    }
#pragma omp for
    for(i=0;i<Nt;i++){
      t[i]=t0+i*dt;
    }
  }


  //printf("here\n");
  for(i=0;i<Nx;i++){

    if(x[i]>=2 && x[i]<=4){
      u[i][0]=boundary(x[i]);
    }
    else{
      u[i][0]=0;
    } 
    for(j=0;j<Nt;j++){
      u[0][j]=0;
      u[Nx-1][j]=0;
    }
  }
  //printf("here\n");
  for(j=0;j<(Nt-1);j++){
#pragma omp parallel num_threads(number_threads) firstprivate(Nx,j) private(i) shared(u,c) default(none)
    {
#pragma omp for
      for(i=1;i<Nx-1;i++){
	
	u[i][j+1]=u[i][j] - (c/2.)*(u[i+1][j]-u[i-1][j])+(pow(c,2.)/2.)*(  u[i+1][j]-2.*u[i][j]+u[i-1][j] );
      }
    }
  }

  /* fp= fopen("wave2.dat","w"); */

  /* for(j=0;j<Nt;j++){ */

  /*   for(i=0;i<Nx;i++){ */

  /*     fprintf(fp,"%7.20f ",u[i][j]*pow(10,15.)); */
  /*   } */
  /*   fprintf(fp,"\n"); */
  /* } */
  /* fclose(fp); */
  return 0;
}
