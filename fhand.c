#include <stdio.h>
#include <stdlib.h>

int main(){
    /*
    int count=0,i=0;
    char filename[100];
    printf("Enter the file name:");
    scanf("%99s",filename);
    FILE *fhand = fopen(filename, "r");
    if(fhand == NULL){
        printf("Failed to open");
    }
    */

    int* newCalloc = (int *)calloc( 11, sizeof(int));
    int* newMalloc = (int *)malloc( sizeof(int)*11);
    int i = 0;
    for(i=0;i<10;i++){
        newCalloc[i]= (i+100);
        newMalloc[i]= (i+1000);
    }
    for(i=0;i<10;i++){
        printf("  %d\n",i);
        printf("++%d\n",newCalloc[i]);
        printf("--%d\n",newMalloc[i]);
    }
}
