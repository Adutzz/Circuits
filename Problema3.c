#include <stdio.h>
#include <math.h>
#include <string.h>

//verific daca e circuit deschis
int open_circuit(int N, int *fr)
{
	for (int k = 1; k <= N; k++) {
		if (fr[k] <= 1) {
			printf("Circuitul este deschis in nodul %d.\n", k);
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	int N = 0, W = 0, nr_componente = 0, fr[1000] = {0};
	double circuit[1000][1000] = {0};
	char legea[3], componenta;
	double suma_consumatori = 0, suma_surse = 0, valoare = 0;
	int not_I = 0;//daca not_I se face 1, legea I nu se respecta
	scanf("%s%d%d", legea, &N, &W);
	//Legea 1
	if ((legea[0] == 'I') && (legea[1] == '\0')) {
		for (int i = 0; i < W; i++) {
			scanf("%lf%lf%lf", &circuit[i][0], &circuit[i][1], &circuit[i][2]);
			int v1 = circuit[i][0], v2 = circuit[i][1];
			fr[v1]++; fr[v2]++;
		}
		int circuit_deschis = open_circuit(N, fr);
		if (circuit_deschis == 0) {
			for (int i = 1; i <= N; i++) {
				int j = 0;
				double x = 0;//x este suma curentilor care intră în nodul i
				double y = 0;//y este suma curentilor care ies din nodul i
				while (j < W) {
					if (circuit[j][0] == i)
						x += circuit[j][2];
					if (circuit[j][1] == i)
						y += circuit[j][2];
					j++;
				}
				if (fabs(x - y) >= 0.00000001) {
					printf("Legea 1 a lui Kirchhoff nu se respecta pentru ega");
					printf("litatea %0.9lfA = %0.9lfA in nodul %d.\n", y, x, i);
					not_I = 1; break;
				}
			}
			if (not_I == 0) {
				printf("Legea 1 a lui Kirchhoff se ");
				printf("respecta pentru circuitul dat.\n");
			}
		} //Legea 2
	} else if ((legea[0] == 'I') && (legea[1] == 'I') && (legea[2] == '\0')) {
		int tensiune_negativa = 0, componenta_incorecta = 0;
		for (int i = 0; i < W; i++) {
			scanf("%lf%lf%lf", &circuit[i][0], &circuit[i][1], &circuit[i][2]);
			int v1 = circuit[i][0];
			int v2 = circuit[i][1];
			fr[v1]++;
			fr[v2]++;
			scanf("%d", &nr_componente);
			for (int k = 0; k < nr_componente; k++) {
				scanf(" %c%lf", &componenta, &valoare);
				if (componenta == 'R') {
					suma_consumatori += circuit[i][2] * valoare;
				} else if (componenta == 'E') {
					suma_surse += valoare;
					if (valoare < 0) {
						printf("Sursa de tensiune nu poate fi negativa.\n");
						tensiune_negativa = 1;
						break;
					}
				} else if (tensiune_negativa == 0) {
					printf("Componenta dorita nu exista.\n");
					componenta_incorecta = 1;
				}
			}
		}
		int circuit_deschis = 0;//verific daca e circuit deschis
		if (tensiune_negativa == 0 && componenta_incorecta == 0)
			circuit_deschis = open_circuit(N, fr);
		if (circuit_deschis == 0 && tensiune_negativa == 0) {
			if (fabs(suma_consumatori - suma_surse) >= 0.00000001) {
				printf("Legea a 2-a lui Kirchhoff nu se ");
				printf("respecta pentru egalitatea ");
				printf("%.9lfV = %.9lfV.\n", suma_consumatori, suma_surse);
			} else {
				printf("Legea a 2-a lui Kirchhoff se respecta ");
				printf("pentru circuitul dat.\n");
			}
		}
	} else
		printf("Legile existente sunt doar Legea 1 si Legea a 2-a\n");
	return 0;
}
