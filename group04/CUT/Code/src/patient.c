#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "dph.h"

//patient *new,*ptr1,*prev,*last;
int patient_registration()
{
	patient *ptr1,*new,*prev;
	if((new=(patient *)calloc(1,sizeof(patient)))==NULL)
	{
		printf("\nMemory Allocation failed\n");
		return EXIT_FAILURE;
	}

	char str[20];
	while(1)
	{
		printf("\nEnter Aadhar no-\n");
		scanf("%s",str);
		int len;
		len = strlen(str);
		if(isdigit_validation1(str))
		{
			printf("\nAadhar number should contain only digits\n");
			continue;
		}
		if(len!= 6)
		{
			printf("\nAadhar number must be of 6 digits please try again...\n");
			continue;
		}
		new->aadhar_no=atoi(str);

		if(start1)
		{
			for(ptr1=start1;(ptr1) && ptr1->aadhar_no!=new->aadhar_no;ptr1=ptr1->next);
			if(ptr1)
			{
				printf("\naadhar no %s is duplicate\n",new->aadhar_no);
				continue;
				
			}
			else
				break;
		}
		else
		{
			break;
		}
	}
	while(1)
	{
		printf("\nEnter Name:\n");
		scanf("%s",new->name);
		int max_len=15;
		if(strlen(new->name)>max_len)
		{
			printf("\nlength of name should be less than 15 characters\n");
			continue;
		}
		if(isalpha_validation1(new->name))
		{
			printf("\nname should contain only characters\n");
			continue;
		}
		break;
	}

	while(1)
	{
		printf("\nEnter Age:\n");
		scanf("%s",str);
		int a=0;
		a = strlen(str);
		if(isdigit_validation1(str))
		{
			printf("\nage should contain only digits\n");
			continue;
		}
		new->age=atoi(str);
		if(new->age<=0 || new->age>151)
		{
			printf("\nage must be in range fom 0 to 150...\n");
			continue;
		}
		else
		{
			break;
		}
	}

	while(1)
	{
		printf("\nEnter Weight:\n");
		scanf("%s",str);
		int w=0;
		w = strlen(str);
		if(isdigit_validation1(str))
		{
			printf("\nage should contain only digits\n");
			continue;
		}
		new->weight=atoi(str);
		if(new->weight<1 || new->weight>150)
		{
			printf("\nweight must be with in range that is between 1 and 150  please try again...\n");
			continue;
		}
		else
		{
			break;
		}
	}

	while(1)
	{
		printf("\nEnter Gender:\n");
		scanf("%s",new->gender);
		if(isalpha_validation1(new->name))
		{
			printf("\ngender should contain only characters\n");
			continue;
		}
		if(strcmp("male",new->gender)==0||strcmp("female",new->gender)==0)
			break;
		else
		{
			printf("\nInvalid input.Enter male or female\n");
			continue;
		}

		break;
	}
	while(1)
	{
		printf("\nEnter your Phone Number-");
		scanf("%s",new->phone_no);
		int len;
		len = strlen(new->phone_no);
		if(len != 10)
		{
			printf("\nPhone number must be of 10 digits please try again...\n");
			continue;
		}
		if(isdigit_validation1(new->phone_no))
		{
			printf("\nPhone number should contain only digits\n");
			continue;
		}
		else
		{

			break;
		}
	}


	if(!start1)
	{
		start1=new;
		new->next=NULL;
	}
	else if(new->aadhar_no<start1->aadhar_no)
	{
		new->next=start1;
		start1=new;
	}
	else
	{
		for(ptr1=start1;(ptr1) &&  ptr1->aadhar_no!=new->aadhar_no;prev=ptr1,ptr1=ptr1->next);
		prev->next=new;
		new->next=ptr1;
	}
	return EXIT_SUCCESS;
}

int isalpha_validation1(char *str)
{
	for(char *p=str; *p!='\0'; p++)
	{
		if(!isalpha(*p))
		{
			return 1;
		}
	}
	return 0;
}

int isdigit_validation1(char *str)
{
	for(char *p=str; *p!='\0'; p++)
	{
		if(!isdigit(*p))
		{
			return 1;
		}
	}
	return 0;
}

int book_appointment()
{
	doctor *ptr;
	patient *ptr1;
	book_app *new,*ptr2,*prev;
	char str[20],s[10];
	int s1_count=0,s2_count=0;
	int aan;
	while(1)
	{
		printf("Enter aadhar  no\n");
		scanf("%d",&aan);
		for(ptr1=start1;(ptr1) && ptr1->aadhar_no!=aan ;ptr1=ptr1->next);
		if(!ptr1)
		{
			printf("\n Invalid aadhar number\n");
			continue;
		}
		else
			break;
	}

		while(1)
		{

			printf("\n1.orthopedician\n2.cardiologist\n3.neurologist\n4.pediatrician\n5.dermatologist\n");
			printf("choose specialization\n");
			int choice;
			scanf("%d",&choice);
			if(choice<=0 || choice>=6)
			{
				printf("\nInvalid choice enter valid choice\n");
				continue;
			}
			if(choice == 1)
			{
				strcpy(str,"orthopedician");
				break;
			}	
			if(choice == 2)
			{
				strcpy(str,"cardiologist");
				break;
			}
			if(choice == 3)
			{
				strcpy(str,"neurologist");
				break;
			}
			if(choice == 4)
			{
				strcpy(str,"pediatrician");
				break;
			}
			if(choice == 5)
			{
				strcpy(str,"dermatologist");
				break;
			}


			else
				break;
		}


		for(ptr=start;(ptr) && strcmp(str,ptr->specialization)==0;ptr=ptr->next)
		{
			printf("%s  %d  %s\n",ptr->name,ptr->MCI_no,ptr->slot);
		}

		for(ptr=start;(ptr) && strcmp(str,ptr->specialization)!=0;ptr=ptr->next);
		if(!ptr)
		{
			printf("Invalid");
			return EXIT_FAILURE;
		}


		if(ptr)
		{
			while(1)
			{
				if((new=(book_app *)calloc(1,sizeof(book_app)))==NULL)
				{
					printf("\ninvalid memory allocation\n");
					return EXIT_FAILURE;
				}
				printf("\nChoose Doctor's License Number-");
				scanf("%d",&new->license_no);

				for(ptr=start;(ptr);ptr=ptr->next)
				{ 
					if(new->license_no==ptr->MCI_no)
					{
						if(strcmp(ptr->slot,"Both")==0)
						{
							printf("The doctor is available in both slot-1 and slot-2....");
							scanf("%s",s);
							if(strcmp(s,"slot-1")==0 && s1_count<=10)
							{
								printf("\nSlot 1 Booked");	
								s1_count=s1_count+1;
								s2_count=0;
								break;
							}
							if(strcmp(s,"slot-2")==0 && s2_count<=10)
							{
								printf("\nSlot 2 Booked");	
								s2_count=s2_count+1;
								s1_count=0;
								break;
							}
							printf("Slots are filled...please try another doctor\n");
							continue;

						}
						else
						{
						//	while(1)
						//	{
								printf("Enter slot-");
								scanf("%s",s);
						//		if(strcmp(s,ptr->slot)!=0)
						//		{
						//			printf("\nDoctor is not available for %s please try another slot\n");
						//			continue;
						//		}
						//		break;
						//	}
							if(strcmp(ptr->slot,"slot-1")==0 && s1_count<=10)
							{
								printf("\nSlot 1 Booked \n");
								s1_count=s1_count+1;
								s2_count=0;
								break;
							}
							else if(strcmp(ptr->slot,"slot-2")==0 && s2_count<=10)
							{
								printf("\nSlot 2 Booked \n");
								s2_count=s2_count+1;
								s1_count=0;
								break;
							}

							else
							{
								printf("Slots are filled");
								continue;
							}
							
						}
						break;
					}

				}
				break;
			}

			strcpy(new->doc_name,ptr->name);
			strcpy(new->pat_name,ptr1->name);
			new->aan=ptr1->aadhar_no;
			strcpy(new->book_slot,s);
			new->visit_no=s1_count+s2_count;
			new->license_no=ptr->MCI_no;

			printf("\n Doctor Name:%s\n VIST_NO: %d\n MCI Number:%d\n Slot:%s\n",new->doc_name,new->visit_no,new->license_no,new->book_slot);

		}

		if(!start2)
		{
			start2=last=new;
			new->next=NULL;
		}
		if(start2)
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
	
	
/*	if(!start2)
	{
		start2=new;
		new->next=NULL;
	}
	else if(new->aan<start2->aan)
	{
		new->next=start2;
		start2=new;

	}
	else
	{
		for(ptr2=start2;(ptr2) && ptr2->aan<new->aan;prev=ptr2,ptr2=ptr2->next);
		prev->next=new;
		new->next=ptr2;
	}*/


	return EXIT_SUCCESS;	
}

int edit_patient_data()
{
	patient *ptr1;
	if(!start1)
	{
		printf("\nEmpty list\n");
		return EXIT_FAILURE;
	}

	while(1)
	{
		int ano;
		printf("Enter aadhar no for editing -");
		scanf("%d",&ano);

		for(ptr1=start1;(ptr1) && ptr1->aadhar_no!=ano;ptr1=ptr1->next);
		if(!ptr1)
		{
			printf("\naadhar no %d is not found",ano);
			return EXIT_FAILURE;
		}
		while(1)
		{
			printf("\nEnter your Phone Number-");
			scanf("%s",ptr1->phone_no);
			int len;
			len = strlen(ptr1->phone_no);
			if(len != 10)
			{
				printf("\nPhone number must be of 10 digits please try again...\n");
				continue;
			}
			if(isdigit_validation(ptr1->phone_no))
			{
				printf("\nPhone number should contain only digits\n");
				continue;
			}
			else
			{

				break;
			}
		}
		printf("\nupdated successfully");
		return EXIT_SUCCESS;
	}
}
int view_patient_data()
{
	patient *ptr1;
	if(!start1)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	printf("\n AADHAR NO  NAME  AGE    GENDER   WEIGHT   PHONE_NO\n");
	for(ptr1=start1;(ptr1);ptr1=ptr1->next)
	{
		printf("\n%d---%s---%4d---%10s---%5d---%5s\n",ptr1->aadhar_no,ptr1->name,ptr1->age,ptr1->gender,ptr1->weight,ptr1->phone_no);
	}
	printf("\n");
	return EXIT_SUCCESS;

}
int delete_patient_data()
{
	patient *ptr1,*prev;
	if(!start1)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	int adno;
	printf("\nEnter aadhar no. for deleting-");
	scanf("%d",&adno);
	if(adno==start1->aadhar_no)
	{
		ptr1=start1;
		start1=start1->next;
		free(ptr1);
	}
	else
	{
		for(ptr1=start1;(ptr1) && ptr1->aadhar_no!=adno;prev=ptr1,ptr1=ptr1->next);
		if(!ptr1)
		{
			printf("\naadhar no %d not found for deletion \n",adno);
			return EXIT_FAILURE;
		}
		prev->next=ptr1->next;
		free(ptr1);
	}
	printf("Deleted data successfully");
	return EXIT_SUCCESS;

}


int patient_file_to_list()
{
	patient *new,*last;
	FILE *p;
	tp tp1;
        if((p=fopen("PATIENT","rb"))==NULL)
        {
                printf("\nFile is not there to read from\n");
                return EXIT_FAILURE;
        }
        fread(&tp1,sizeof(tp),1,p);
        while(!feof(p))
        {
                if((new=(patient *)calloc(1,sizeof(patient)))==NULL)
                {
                        printf("\nMemory Allocation failed\n");
                        return EXIT_FAILURE;
                }
                new->aadhar_no=tp1.aadhar_no;
                strcpy(new->name,tp1.name);
                new->age=tp1.age;
		new->weight=tp1.weight;

                strcpy(new->gender,tp1.gender);
                strcpy(new->phone_no,tp1.phone_no);
                if(!start1)
                {
                        start1=last=new;
                        new->next=NULL;
                }
                else
                {
                        last->next=new;
                        last=new;
                        new->next=NULL;
                }
                fread(&tp1,sizeof(tp),1,p);
        }
        fclose(p);
        return EXIT_SUCCESS;
}
int patient_list_to_file()
{
	patient *ptr1;
        tp tp2;
        if(!start1)
        {
                printf("\nList is empty\n");
                return EXIT_FAILURE;
        }
        FILE *p1;
        if((p1=fopen("PATIENT","wb"))==NULL)
        {
                printf("\nFile is not there to read from\n");
                return EXIT_FAILURE;
        }
        for(ptr1=start1;(ptr1);ptr1=ptr1->next)
        {
                tp2.aadhar_no=ptr1->aadhar_no;
                strcpy(tp2.name,ptr1->name);
                tp2.age=ptr1->age;
		tp2.weight=ptr1->weight;
                strcpy(tp2.gender,ptr1->gender);
                strcpy(tp2.phone_no,ptr1->phone_no);
                fwrite(&tp2,sizeof(tp),1,p1);

        }
        fclose(p1);
        return EXIT_SUCCESS;
}



int book_appointment_file_to_list()
{
	book_app *new,*last;
	FILE *b;
	tb tb1;
        if((b=fopen("BOOK_APP","rb"))==NULL)
        {
                printf("\nFile is not there to read from\n");
                return EXIT_FAILURE;
        }
        fread(&tb1,sizeof(tb),1,b);
        while(!feof(b))
        {
                if((new=(book_app *)calloc(1,sizeof(book_app)))==NULL)
                {
                        printf("\nMemory Allocation failed\n");
                        return EXIT_FAILURE;
                }
      
                strcpy(new->doc_name,tb1.doc_name);
                new->license_no=tb1.license_no;
                strcpy(new->book_slot,tb1.book_slot);
		new->aan=tb1.aan;
		new->visit_no=tb1.visit_no;
		strcpy(new->pat_name,tb1.pat_name);
                if(!start2)
                {
                        start2=last=new;
                        new->next=NULL;
                }
                else
                {
                        last->next=new;
                        last=new;
                        new->next=NULL;
                }
                fread(&tb1,sizeof(tb),1,b);
        }
        fclose(b);
        return EXIT_SUCCESS;
}
int book_appointment_list_to_file()
{
	book_app *ptr2;
        tb tb2;
        if(!start2)
        {
                printf("\nList is empty\n");
                return EXIT_FAILURE;
        }
        FILE *b1;
        if((b1=fopen("BOOK_APP","wb"))==NULL)
        {
                printf("\nFile is not there to read from\n");
                return EXIT_FAILURE;
        }
        for(ptr2=start2;(ptr2);ptr2=ptr2->next)
        {
                
                strcpy(tb2.doc_name,ptr2->doc_name);
                tb2.license_no=ptr2->license_no;
		tb2.aan=ptr2->aan;
		tb2.visit_no=ptr2->visit_no;
		strcpy(tb2.pat_name,ptr2->pat_name);
                strcpy(tb2.book_slot,ptr2->book_slot);
                fwrite(&tb2,sizeof(tb),1,b1);

        }
        fclose(b1);
        return EXIT_SUCCESS;
}


