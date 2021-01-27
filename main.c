#include<stdio.h>
#include<math.h>
//#include<conio.h>
void saisie(float*,int);
void affiche_vec(float*,int);
void calcul_mat(float*,float*,float*,int,int);
void affiche_mat(float*,int);
void pivot(float*,int);
int main()
{
float x[10],y[10],B[10][11];
int nm,nd ;
//saisie de nombre de mesure .
printf("donner le nombre du mesures nm \n ");
scanf("%d",&nm);
//saisie de nombre de degre de polynome .
printf("donner le nombre de degre de polynome \n ");
scanf("%d",&nd);
//appel de fonction saisie pour x
printf("=====donner les elements du tablau x =====\n");
saisie (x,nm);
//appel de fonction saisie pour y
printf("=====donner les elements du tablau Y =====\n");
saisie (y,nm);
//printf("\n================le vecteur x ================\n");
//affiche_vec(x,nm);
//printf("\n================le vecteur y================\n");
//affiche_vec(y,nm);
//appel fonction calcul-mat
calcul_mat(x,y,B[0],nd,nm);
printf("\n******************la matrice initial************************\n\n");
//appel fontion affiche-mat
affiche_mat(B[0],nd);
//appel fonction pivot
pivot(B[0],nd);
printf("\n ****************la matrice diagonalisee*********************\n\n\n");
affiche_mat(B[0],nd);
//fin
getch();
}
//fonction saisie
void saisie (float*q,int nm)
{
int i;

for (i=0;i<=nm-1;i++)
{
printf("donner la mesure %d\t",i);
scanf("%f",(q+i));
}
}
//fonction affiche-vec
void affiche_vec(float*q,int nm)
{
int i;
for (i=0;i<=nm-1;i++)
{
printf("%f\t",*(q+i));
}
}
//fonction calcul-mat
void calcul_mat(float*p,float*q,float*r,int nd ,int nm)
{
int i,j,k,N;
float s;
N=nd+1;
for (i=0;i<=N-1;i++)
{
for (j=0;j<=N-1;j++)
{
s=0;
for (k=0;k<=nm-1;k++)
{

s=s+pow(*(p+k),i+j);
*(r+j+i*(N+1))=s;
}

}
}
//remplissage de la dernière colonne
for (i=0;i<=N-1;i++)
{
j=N;
s=0;
for (k=0;k<=nm-1;k++)

{
s=s+*(q+k)*pow(*(p+k),i);
*(r+j+i*(N+1))=s;
}
}
}
//fonction affiche-mat
void affiche_mat (float* q,int nd)
{
int i,j,N;
N=nd+1;
for (i=0;i<=N-1;i++)
{
for (j=0;j<=N;j++)
{
printf("%f\t",*(q+j+i*(N+1)));
}
printf("\n");
}
}
//fonction pivot
void pivot(float*q,int nd)
{
int i,k,l,N;
float P,S;
N=nd+1;

for (i=0;i<=N-1;i++)
{
//normalisation
P=*(q+i+i*(N+1));
for (k=0;k<=N;k++)
{
*(q+k+i*(N+1))=*(q+k+i*(N+1))/P;
}
//annulation
for (l=0;l<=N-1;l++)
{
if(l!=i)
{
S=*(q+i+l*(N+1));
for (k=0;k<=N;k++)
{
*(q+k+l*(N+1))= *(q+k+l*(N+1))-S*(*(q+k+i*(N+1)));
}
}
}
}
}