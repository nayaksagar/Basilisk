//#include "grid/cartesian.h"
#include "saint-venant.h"

event init (t = 0) {
  foreach()
    h[] = 0.1 + 1.*exp(-200.*(x*x + y*y));
}

event images(i++){   //(i++)
 output_ppm(h,linear=true);
 // scalar l[];
 //  foreach()
 //   l[]=level;
 // FILE*fp=fopen("grid.ppm","w");
 // output_ppm(l,fp,min=0,max=8);
}

event graphs(i++){
 stats s=statsf(h);
 fprintf(stderr,"%g\t%g\t%g\n",t,s.min,s.max);
}

event adapt(i++){
  adapt_wavelet({h},(double[]){4e-3},maxlevel=8);
}

event end(i=1000){             //(i=300)
printf("i=%d t=%g\n",i,t);

}

// event stop(i+=10){
//   if(i==300)
//      return 1;
// }

int main(){
origin(-0.5,-0.5);
init_grid(128);
run();
}
