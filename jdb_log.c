#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{	
	int boucle_principale;
	FILE *journal_indicatif;

	do
	{

	//Accueil et menu principal.
	
	int choix_debut;
	
	system("clear");
	
	printf("##################################################\n");
	printf("##                     JDB_log                  ##\n");
	printf("## -------------------------------------------- ##\n");
	printf("##  Un programme simple pour consigner ses QSO. ##\n");
	printf("## -------------------------------------------- ## \n");
	printf("##     Version de contruction septembre 2023    ##\n"); 
	printf("##################################################\n\n");
	
	printf("1 >> Saisir un nouveau QSO.\n");
	/*printf("2 >> Recherche par Indicatif [NON FONCTIONNEL]\n");
	printf("3 >> Modification d'un QSO [NON FONCTIONNEL]\n");*/
	printf("4 >> Création, ou remise à zéro, du Journal de Bord [EN DEVELOPPEMENT]\n\n\n");
	printf("0 >> Quitter\n\n\n");
	printf("Choix > ");
	scanf("%d" , &choix_debut);

		if (choix_debut == 1)
		{
			int boucle_saisie;

			char date[12];
			int heure_d = 0;
			int heure_f = 0;
			char indicatif_correspondant[12];
			char suffixe[4]; 
			long fréquence_emission = 0;
			char classe_emission[4];
			char lieu_emission[256];
			
			int validation_saisie;
			
			int boucle_qso;				

			do
			{	// Boucle pour possible nouveau QSO
				
				do
				{	// Saisie des éléments du QSO. [09/2023 >> Le minimum légal].
					
					system("clear");		

					printf("Saisie d'un nouveau QSO\n\n");
					printf("Date du QSO (JJ-MM-AAAA): ");
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
						
						printf("Validez vous la saisie ? ( 1 Oui / 2 Non ) : ");
						scanf("%d" , &boucle_saisie);	

				} while (boucle_saisie != 1);


				// Inscrire le QSO dans le fichier .TXT
				FILE *journal_indicatif = fopen("journal_indicatif.txt" , "a");
							
				fprintf(journal_indicatif, "%-10s   %4d    %-4d      %-9s   %6ld kHz   %-3s     %-25s\n" 	, date , heure_d , heure_f , 
			    indicatif_correspondant, fréquence_emission , classe_emission , lieu_emission);
				fclose(journal_indicatif);	

				printf("Votre QSO a été validé et inscrit dans le Journal de Bord\n\n\n");

				printf("Voulez-vous saisir un nouveau QSO ? (1 oui / 2 non)\n");
				scanf("%d" , &boucle_qso);			
			
			}while (boucle_qso != 2);
		}			
						


		if (choix_debut == 4)
		{
			int boucle_indicatif;
			
			do
			{	
				// Création du Journal de Bord [sans création du nom du dossier personnel]

				char indicatif_personnel[12];
				char date_debut_journal[12];
				int validation_saisie_journal;

				printf("Allons préparer le Journal de Bord\n\n");
				printf("Quels est votre indicatif ? : ");
				scanf("%s" , indicatif_personnel);
				printf("A quelle date créez vous ce journal ? : ");
				scanf("%s" , date_debut_journal);

				printf("Votre Indicatif est : %s\n", indicatif_personnel );
				printf("Vous créez ce journal le %s : \n\n" , date_debut_journal );
				printf("1 pour valider / 0 pour refaire la saisie\n");
				scanf("%d", &validation_saisie_journal );

						if (validation_saisie_journal == 1)
						{
						
						system("touch journal_indicatif.txt");

						FILE* journal_indicatif = fopen("journal_indicatif.txt" , "a");

						if (journal_indicatif == NULL)
							exit(1);

						fprintf(journal_indicatif, "Journal de Bord de : %-12s .   Date de début du Journal : %-12s .\n"
							, indicatif_personnel , date_debut_journal );
						fprintf(journal_indicatif, "En Heure Universelle (UTC)\n" );
						fprintf(journal_indicatif, "--------------------------------------------------------------------------------\n");
						fprintf(journal_indicatif, "Date      ;  Début;  Fin  ;    Indicatif;  Fréquence;  Mode;    Lieu d'émission;\n");
						fprintf(journal_indicatif, "--------------------------------------------------------------------------------\n");
						fclose(journal_indicatif);	

						printf("Votre Journal de Bord a été créé avec succés.\n");
						printf("Il sera visible dans le dossier du programme sous le nom : 'journal_indicatif.txt' .\n");
						break;
						}
						
			} while (boucle_indicatif == 0);			
		}

		if (choix_debut == 0)
		{
			exit(0);
		}

	printf("\n\nTaper 0 pour retourner au Menu Principal \n >> ");
	scanf("%d" , &boucle_principale);

	} while (boucle_principale == 0);






	return 0;
}