#include <stdio.h>
#include <string.h>

int checkprime(char *left, int nattr, char *attr, int *prime, int primelen){
  int i,j;

  if(strlen(left) != primelen)
    return 0;

  for(i = 0; left[i] != '\0'; i++)
    for(j = 0; j < nattr; j++)
      if(attr[j] == left[i] && !prime[j])
        return 0;
  return 1;
}

int checksuper(char *left, int nattr, char *attr, int *super, int superlen){
  int i,j;

if(strlen(left) != superlen)
    return 0;



  if(strlen(left) != superlen)
      return 0;
  for(i = 0; left[i] != '\0'; i++)
    for(j = 0; j < nattr; j++)
      if(attr[j] == left[i] && !super[j])
        return 0;

 
  return 1;
}


int main(){

  char attr[256];
  int super[256];
  int prime[256];

  char primekey[256], superkey[256], fds[16][32], *left, *right, tempstr[32], tempstr2[32];
  char attrset[32];

  int i, j, nattr, superlen, primelen, nfd, status = -1, reason;



  bzero(super, 256);
  bzero(prime, 256);

  printf("Enter no. of attributes: ");
  scanf("%d", &nattr);
  printf("Enter the attributes: ");
  scanf("%s", attrset);
  for(i = 0; attrset[i] != '\0'; i++)
    attr[i] = attrset[i];


  printf("Enter the prime key: ");
  scanf("\n%s", primekey);
  for(i = 0; primekey[i] != '\0'; i++)
    for(j = 0; j < nattr; j++)
      if(attr[j] == primekey[i])
        prime[j] = 1;

  primelen = strlen(primekey);

  printf("Enter the super keys: ");
  scanf("\n%s", superkey);
  for(i = 0; superkey[i] != '\0'; i++)
    for(j = 0; j < nattr; j++)
      if(attr[j] == superkey[i])
        super[j] = 1;

  superlen = strlen(superkey);

  printf("Enter no. of functional dependencies: ");
  scanf("%d", &nfd);

  printf("Enter functional dependencies: \n");
  for(i = 0; i < nfd; i++)
    scanf("\n%s", fds[i]);

  for(i = 0; i < nfd; i++){
    strcpy(tempstr, fds[i]);
    strcpy(tempstr2, fds[i]);
    left = strtok(tempstr, "->");
    right = strtok(NULL,"->");	 

  if(!checksuper(left, nattr, attr, super, superlen)){
      status = 1;
      reason = i;
    }
  else
    continue;
    if(!checkprime(right, nattr, attr, prime, primelen)){

      status = 0;
      reason = i;
      break;
    }
 

    
  }

  if(status == -1)
    printf("The schema is BCNF\n");
  else if(status == 0){
      printf("The relation is not 3NF\n");
      printf("Reason: The functional dependency '%s'.\n", fds[reason]);
  }else if(status == 1){
      printf("The relation is 3NF only.\n");
      printf("Reason: The functional dependency '%s'.\n", fds[reason]);
  }


      
  return 0;
}

