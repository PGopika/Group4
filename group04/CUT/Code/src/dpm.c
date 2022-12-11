#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.c"
#include "doctor.c"
#include "dph.h"
int main()
{
	int ch=0;
	doctor_file_to_list();
	patient_file_to_list();
	book_appointment_file_to_list();
	record_patient_history_file_to_list();
	while (ch!=4)
	{
		printf(".............DOCTOR PATIENT MANAGEMENT SYSTEM..............\n\n\n");
		printf("1.Select admin corner \n2.Select doctor corner \n3.Select patient corner \n4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:admin_corner();
			       break;
			case 2:doctor_corner();
			       break;
			case 3:patient_corner();
			       break;
			case 4:break;
			default:printf("\nInvalid choice\n");
		}
	}
	doctor_list_to_file();
	patient_list_to_file();
	book_appointment_list_to_file();
	record_patient_history_list_to_file();
	return EXIT_SUCCESS;
}


//*********************************************************************************


int admin_corner()
{
	int login=9999;
	char passwd[10]="Dhnmk$9";
	int login_id;
	char pass[10];
	while(1)
	{
		printf("Enter Id:");
		scanf("%d",&login_id);
		printf("Enter Password:");
		scanf("%s",pass);
		if(login!=login_id || strcmp(passwd,pass)!=0)
		{
			printf("\n Invalid login id or password\n");
			continue;
		}
		else
		{
			int ch=0;
			while(ch!=4)
			{
				printf("\n\n\n.............Admin corner.........\n\n\n");
				printf("\n1.Patient File Maintenance\n2.Doctor File Maintenance\n3.View Doctor Appointments by License ID\n4.Exit\n");

				scanf("%d",&ch);
				switch(ch)
				{
					case 1: patient_file_maintenance();
						break;
					case 2: doctor_file_maintenance();
						break;
					case 3: doctor_license_query();
						break;
					case 4: break;
					default:printf("Invalid input.Enter a valid Number from the above options");

				}
				system("read a");
				system("clear");

			}

			//list_to_file();
			return EXIT_SUCCESS;
		}
	}
}



int patient_file_maintenance()
{
	int ch=0;
	while(ch!=5)
	{
		printf("\n................Patient File maintenance...................\n");
		printf("1.add patient data\n2.edit patient data\n3.view patient data\n4.delete patient data\n5.exit\n");
		printf("\nEnter choice-\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:patient_registration();
			       break;
			case 2:edit_patient_data();
			       break;
			case 3:view_patient_data();
			       break;
			case 4:delete_patient_data();
			       break;
			case 5:break;
			default:printf("\ninvalid choice\n");
		}
		system("read a");
		system("clear");

	}
	return EXIT_SUCCESS;
}



int doctor_file_maintenance()
{
	int ch=0;
	while(ch!=5)
	{
		printf("\n................Doctor File maintenance...................\n");
		printf("1.add doctor data\n2.edit doctor data\n3.view doctor data\n4.delete doctor data\n5.exit\n");
		printf("\nEnter choice-\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:doctor_registration();
			       break;
			case 2:edit_doctor_info();
			       break;
			case 3:view_doctor_info();
			       break;
			case 4:delete_doctor_data();
			       break;
			case 5:break;
			default:printf("\ninvalid choice\n");
		}
		system("read a");
		system("clear");

	}
	return EXIT_SUCCESS;
}




//*****************************************************************************************
int doctor_corner()
{
	int ch=0;
	while(ch!=3)
	{
		printf("\n..........Doctor corner.........\n");
		printf("1.Doctor registration\n2.Doctor login\n3.Exit\n");
		printf("\nEnter choice-\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:doctor_registration();
			       break;
			case 2:doctor_login();
			       break;
		 	case 3:break;
                        default:printf("\ninvalid choice\n");
		}
		system("read a");
		system("clear");

	}
	return EXIT_SUCCESS;
}

int doctor_login()
{
	doctor *ptr;
	int mci;
	char p[16];
	while(1)
	{
		printf("Enter your MCI no\n");
		scanf("%d",&mci);
		printf("Enter the password \n");
		scanf("%s",p);
		int i=1;
		for(ptr=start;(ptr) && ptr->MCI_no!=mci ;ptr=ptr->next);
		if(!ptr)
		{
			printf("\n Invalid MCI no or  password\n");
			continue;
		}
		if(ptr)
		{
			i = strcmp(p,ptr->password);
		}
		if(i!=0)
		{
			printf("\nInvalid password");
			continue;
		}


		if(i == 0)
		{

			int choice=0;
			//  doctor_file_to_list();
			while(choice!=6)
			{
				printf("\n.........Doctor Login.........\n");
				printf("1.view_bookings\n2.record_patient_history\n3.view_patient_history\n4.edit_doctor_info\n5.view_doctor_info\n6. Exit");
				printf("\nEnter choice-");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:view_bookings();
					       break;
					case 2:record_patient_history();
					       break;
					case 3:view_patient_history();
					       break;
					case 4:edit_doctor_info();
					       break;
					case 5:view_doctor_info();
					       break;
					case 6:break;
					default:printf("\ninvalid choice\n");
				}
				system("read a");
				system("clear");

			}
		}
		return EXIT_SUCCESS;
	}
}

//********************************************************************************************************

int patient_corner()
{
	int ch=0;
	while(ch!=3)
	{
		printf("\n......enter patient data......\n");
		printf("1.patient registration\n2.existing patient\n3.Exit");
		printf("\nEnter choice-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:patient_registration();
			       break;
			case 2:book_appointment();
			       break;
			case 3:break;
			default:printf("\ninvalid choice\n");
		}
		system("read a");
		system("clear");
	}
	return EXIT_SUCCESS;
}





