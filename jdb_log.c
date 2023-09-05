#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{	
	int boucle_principale;

	do
	{

	//Accueil et menu principal.
	
	system("clear");
	
	printf("############################################\n");
	printf("## Journal de Bord Radioamateur de F4LCF  ##\n");
	printf("## -------------------------------------  ##\n");
	printf("## Version de contruction septembre 2023  ##\n"); 
	printf("############################################\n\n");


	int choix_debut;
	printf("1 >> Saisir un nouveau QSO.\n");
	printf("2 >> Recherche par Indicatif [NON FONCTIONNEL]\n");
	printf("3 >> Modification d'un QSO [NON FONCTIONNEL]\n");
	printf("4 >> Création du Journal de Bord [EN DEVELOPPEMENT]\n\n");
	printf("Choix ? > ");
	scanf("%d" , &choix_debut);

		if (choix_debut == 1)
		{
			int boucle_saisie;

			do
			{
				// Saisie des éléments du QSO. [09/2023 >> Le minimum légal].
				
				system("clear");


					char date[12];
					int heure_d = 0;
					int heure_f = 0;
					char indicatif_correspondant[12];
					char suffixe[4]; 
					long fréquence_emission = 0;
					char classe_emission[4];
					char lieu_emission[256];
					int validation_saisie;

					printf("Saisie d'un nouveau QSO\n\n");
					printf("Date (JJ-MM-AAAA): ");
					scanf("%s" , date);
					printf("Début du QSO, en Heure Universelle > (Format hhmm) : " );
					scanf("%d" , &heure_d);
					printf("Fin du QSO, en Heure Universelle  >  (Format hhmm) : " );
					scanf("%d" , &heure_f);
					printf("Indicatif du correspondant :");
					scanf("%s" , indicatif_correspondant);
					printf("Fréquence d'émission (en kHz) : ");
					scanf("%ld" , &fréquence_emission);
					printf("Classe d'émission : ");
					scanf("%s" , classe_emission);
					printf("Lieu d'émission : ");
					scanf("%s" , lieu_emission);
				

					system("clear");

						printf("Résumé de la saisie : \n");
						printf("-------------------\n");
						printf("QSO du %s\n", date);
						printf("De %04d T.U à" , heure_d);
						printf(" %04d T.U\n" , heure_f);
						printf("Avec %s " , indicatif_correspondant);
						printf("sur %ld kHz ," , fréquence_emission );
						printf("en %s .\n" , classe_emission);
						printf("Depuis %s ." , lieu_emission);	
						printf("\n\n\n");

						printf("Validez vous la saisie ? (1 oui / 2 non ) : \n");
						scanf("%d" , &boucle_saisie);
		
			} while (boucle_saisie == 2);

			printf("Votre QSO a été validé et inscrit dans le Journal de Bord\n\n");

		}

		if (choix_debut == 4)
		{
			int boucle_indicatif;

			do
			{	
				// Création du Journal de Bord [sans création du nom du dossier]

				char indicatif_personnel[12];

				printf("Allons préparer le Journal de Bord\n\n");
				printf("Quels est votre indicatif : ");
				scanf("%s" , indicatif_personnel);
				printf("%s\n", indicatif_personnel );
				
				system("touch journal_indicatif.txt");

				FILE *journal_indicatif = fopen("journal_indicatif.txt" , "a");

				if (journal_indicatif == NULL)
					exit(1);

				fprintf(journal_indicatif, "Journal de Bord de : %-12s .\n", indicatif_personnel );
				fprintf(journal_indicatif, "En Heure Universelle (UTC)\n" );
				fprintf(journal_indicatif, "##################################\n");
				fclose(journal_indicatif);

			} while (boucle_indicatif == 2);
		}



	printf("0 pour retour menu >> ");
	scanf("%d" , &boucle_principale);

	} while (boucle_principale == 0);

	return 0;
}