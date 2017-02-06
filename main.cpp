#include<stdio.h>

struct dreptunghi{ int x1,y1,x2,y2;
   };
void normalizare(dreptunghi &a)//aici nici 0.00009% nu sunt sigura
{

	if(a.x1<1)
		a.x1=1;

	if(a.x1>80)
		a.x1=80;

	if(a.x2<1)
		a.x2=1;

	if(a.x2>24)
		a.x2=24;

}
// ai uitat sa trimiti parametrul a prin referinta
//	void citire(dreptunghi a){

	void citire(dreptunghi &a){
		//Cand faci citire nu uita de &

		printf("Introduceti coordonatele coltului stanga-sus sub forma x1,y1:");scanf("%d,%d",&a.x1,&a.y1);
		printf("\nIntroduceti coordonatele coltului dreapta-jos sub forma x1,y1:");scanf("%d,%d",&a.x2,&a.y2);
	}
//la afisare nu trimiti prin referinta..
//void afisare(dreptunghi &a)
	void afisare(dreptunghi a){
		printf ("\n Coordonatele dreptunghiului sunt : (%d,%d) si (%d,%d).",a.x1,a.y1,a.x2,a.y2);
    }
	int aria(dreptunghi &a){
		// nu inteleg de ce ai redeclrata aici o variabila cu aceasi denumire int a;
		int Aa=(a.x2-a.x1)*(a.y2-a.y1);
		return Aa;
	}
	int maimare(dreptunghi &a, dreptunghi &b){
		if(aria(a)>aria(b))
		       return aria(a);
	else
		       return aria(b);

	}

	void deplasare( dreptunghi &a,int x,int y){
		a.x1+=x;
	    a.x2+=x;
		a.y1+=y;
		a.y2+=y;
		normalizare(a);
		printf("(%d,%d),(%d,%d)",a.x1,a.x2,a.y1,a.y2);
	}
	void intersectie(dreptunghi &A, dreptunghi &B){
		//te las pe tine

		/*
		 *  ----------
		 *  |     ---|--
		 *  |    |   |  |
		 *  ---------   |
		 *       |      |
		 *        -------
		 */
		dreptunghi C;


		C.x1 = A.x1>B.x1?A.x1:B.x1;//ii dau valoarea maxima
		C.x2 = A.x2<B.x2?A.x2:B.x2;//ii dau valoarea minima
		C.y1 = A.y1<B.y1?A.y1:B.y1;//ii dau valoarea minima
		C.y2 = A.y2>B.y2?A.y2:B.y2;//ii dau valoarea maxima


		/*
		 * Ideea este ca trebuie sa formezi un dreptungi ff mic(pt ca e intersectie)
		 * si astfel incerci sa alegi laturile astfel incat sa gasesti laturile intersectiei
		 * Desenati cateva exemple pe hartie si poate va dati seama cum m-am gandit aici..
		 */

		// Am incercat sa explic aici: https://postimg.org/image/b1gs3xra7/


		if(!(C.x1<C.x2)||!(C.y1<C.y2)){
			// in acest caz inseamna ca intersectia este nula
			C.x1=C.x2=C.y1=C.y2=0;
		}

		printf("Intersectia primelor 2 elemente din tablou este:\n");
		afisare(C);
	}
	int main(){
	     int  i,j, n;
        printf("Introduceti dim tabloului:  ");
        scanf("%d", &n);
        dreptunghi *tab = new dreptunghi[n];
		for(i=0;i<n;i++){
			citire(tab[i]);
		}
		for(i=0;i<n;i++){
			afisare(tab[i]);
			printf(" Aria:%d",aria(tab[i]));
		}

// NU inteleg de ce faci acest for, functia aria introace int si nu afiseaza nimic in interiorul ei
//         for(i=0;i<n;i++){
//			aria(tab[i]); }



		//TODO Ca sa gasesti maximul compari elm maxim cu fiecare din celelalte
//		 for(i=0;i<n;i++){
//			 int max;
//			 max=maimare(tab[i],tab[i+1]);
//			//deplasare(2,3,max[i]);
//			//afisare(max[i]);
//			}
		//TODO Maximul il afisezi dupa ce ai parcurs for-urile.. nu in for, altfel iti afiseaza acel mesaj la fiecare iteratie

		int max = aria(tab[0]);//initializez cu aria primului dreptunghi
		for(i=1;i<n;i++){
			if(max<aria(tab[i])) max = aria(tab[i]);
		}
		printf("\nAria maxima din tablou este: %d", max);

		intersectie(tab[0],tab[1]);
			return 0;
	}
