#include<stdio.h>
#include<math.h>
int main()
{
  int a;
  scanf("%d",&a);
   int n , m ;
  int a1 = a, a0 = 0;
  for (; a1 != 1; a1-=2, a0+=1) {
     for (n = a0; n > 0; n--) {
      printf("0 ");
      }
     for (m = a1; m > 0; m--) {
       printf("1 ");
     }
  	for (n = a0; n > 0; n--) {
  	 printf("0 ");
 		 }
// 	 printf("\n");
// 		}
// 		for (a1=1,a0=a/2; a1 <=a ; a1 += 2, a0 -= 1) {
// 	 for (n = a0; n > 0; n--) {
//  	 printf("0 ");
//  	}
// 	 for (m = a1; m > 0; m--) {
// 	  printf("1 ");
//	  }
//  	for (n = a0; n > 0; n--) {
// 	  printf("0 ");
// 	 }
 	 printf("\n");
 	}
	 return 0;
}
