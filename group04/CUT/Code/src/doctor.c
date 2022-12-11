#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include "dph.h"
#define max_len 15


//doctor *new,*ptr,*prev,*last;
int doctor_registration()

{
	doctor *new,*ptr,*prev;
        if((new=(doctor *)calloc(1,sizeof(doctor)))==NULL)
        {
                printf("\nMemory Allocation failed\n");
                return EXIT_FAILURE;
        }
	char str[20];
        while(1)
        {
		
                printf("Enter MCI no-");
                scanf("%s",str);
		int len;
		len = strlen(str);
		if(isdigit_validation(str))
		{
			printf("\nMCI number should contain only digits\n");
			continue;
		}
		if(len != 6)
		{
			printf("\n MCI number must be of 6 digits please try again...\n");
			continue;
		}
		new->MCI_no=atoi(str);

                if(start)
                {
                        for(ptr=start;(ptr) && ptr->MCI_no!=new->MCI_no;ptr=ptr->next);
                        if(ptr)
                        {
                                printf("\nMCI no %d is duplicate\n",str);
                                return EXIT_FAILURE;
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
                printf("Enter name-");
                scanf("%s",new->name);
                if(strlen(new->name)>max_len)
                {
                        printf("length of name should be less than 15 characters\n");
                        continue;
                }
                if(isalpha_validation(new->name))
                {
                        printf("name should contain only characters\n");
                        continue;
                }
                break;
        }
        while(1)
        {
                printf("Enter  age-");
                scanf("%s",str);
		int a=0;
		a=strlen(str);
		if(isdigit_validation(str))
		{
			printf("\nage should contain only digits\n");
			continue;
		}
		new->age=atoi(str);
		if(new->age<=10 || new->age>=150)
		{
			printf("\n age must be in the range of 10 to 150...\n");
			continue;
		}
		else
		{
		
			break;
		}
        }
	while(1)
	{
		printf("Enter gender-");
        	scanf("%s",new->gender);
		if(isalpha_validation(new->gender))
                {
                printf("name should contain only characters\n");
                continue;
                }
		if(strcmp("male",new->gender)==0||strcmp("female",new->gender)==0)
			break;
		else
		{
			printf("\n invalid input. enter male or female");
			continue;
		}	
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
		if(isdigit_validation(new->phone_no))
		{
			printf("\nPhone number should contain only digits\n");
			continue;
		}
		else
		{

			break;
		}
	}
	while(1)
	{
		printf("\n1.orthopedician\n2.cardiologist\n3.neurologist\n4.pediatrician\n5.dermatologist\n");
		int choice;
		scanf("%d",&choice);
		if(choice<=0 || choice>=6)
		{
			printf("\nInvalid choice enter valid choice\n");
			continue;
		}
		if(choice == 1)
		{
			strcpy(new->specialization,"orthopedician");
			break;
		}	
		if(choice == 2)
		{
			strcpy(new->specialization,"cardiologist");
			break;
		}
		if(choice == 3)
		{
			strcpy(new->specialization,"neurologist");
			break;
		}
		if(choice == 4)
		{
			strcpy(new->specialization,"pediatrician");
			break;
		}
		if(choice == 5)
		{
			strcpy(new->specialization,"dermatologist");
			break;
		}


		else
			break;
	}

	while(1)
	{
		printf("Enter email id ");
		scanf("%s",new->email_id);
		int ap,dp;
		char eid[20];
		strcpy(eid,new->email_id);
		for(int i=0;eid[i]!='\0';i++)
		{
			if(eid[i]=='@')
			{
				ap=i;
			}
			if(eid[i]=='.')
			{
				dp=i;
			}
		}
		if(ap>3 && (dp-ap)>3)
			break;
		else
			printf("Invalid Email id\n");
	}	
	while(1)
	{
		int choice;
		printf("\n1.slot-1\n2.slot-2\n3.both slots\n");
		scanf("%d",&choice);
		if(choice<=0 || choice>=4)
		{
			printf("\nInvalid choice enter valid choice\n");
			continue;
		}
		if(choice == 1)
		{
			strcpy(new->slot,"slot-1");
			break;
		}
		if(choice == 2)
		{
			strcpy(new->slot,"slot-2");
			break;
		}
		if(choice == 3)
		{
			strcpy(new->slot,"Both");
			break;
		}
		else
			break;
	}

	while(1)
	{
		printf("Enter the password : ");
        	scanf("%s",new->password);
        	if(CheckPassword(new->password))
		{
               		printf("All conditions satisfied\n");
			break;
		}
       		else
               		printf("Incorrect format\n");
			
	}

        if(!start)
        {
                start=new;
                new->next=NULL;
        }
        else if(new->MCI_no<start->MCI_no)
        {
                new->next=start;
                start=new;
        }
        else
        {
                for(ptr=start;(ptr) && ptr->MCI_no<new->MCI_no;prev=ptr,ptr=ptr->next);
                prev->next=new;
                new->next=ptr;
        }
        return EXIT_SUCCESS;
}

int view_bookings()
{
	book_app *ptr2;
	if(!start2)
	{
		printf("\nEmpty list\n");
		return EXIT_FAILURE;
	}
	printf("\n.....viewing appointments with patient info....\n");
	printf("\nAADHAR_NO  NAME  SLOT\n");
	for(ptr2=start2;(ptr2);ptr2->next)
	{
		printf("\n%d---%s---%s\n",ptr2->aan,ptr2->pat_name,ptr2->book_slot);
	}
	return EXIT_SUCCESS;
}
int record_patient_history()
{
	patient *ptr1;
	rpt *new,*pt,*prev,*next;
//	book_app *ptr2;
	int an;
	while(1)
	{
		printf("\nenter patient aadhar number:\n");
		scanf("%d",&an);
		if((new=(rpt *)calloc(1,sizeof(rpt)))==NULL)
		{
			printf("\ninvalid memory allocation\n");
			return EXIT_FAILURE;
		}

		for(ptr1=start1;(ptr1) && ptr1->aadhar_no!=an;ptr1=ptr1->next);
		if(!ptr1)
		{
			printf("\n Given aadhar number is not present in patient records\n");
			continue;
		}
		strcpy(new->rpt_name,ptr1->name);
		new->rpt_age=ptr1->age;
		new->rpt_weight=ptr1->weight;
		new->rpt_aadhar=ptr1->aadhar_no;
		printf("\nenter disease\n");
		scanf("%s",new->disease);
		printf("\nenter treatment\n");
		scanf("%s",new->treatment);
		printf("\nenter medicine\n");
		scanf("%s",new->medicine);
		if(!start3)
		{
			start3=new;
			new->next=NULL;
		}
		else if(new->rpt_aadhar<start3->rpt_aadhar)
		{
			new->next=start3;
			start3=new;
		}
		else
		{
			for(pt=start3;(pt) && pt->rpt_aadhar<new->rpt_aadhar;prev=pt,pt=pt->next);
			prev->next=new;
			new->next=pt;
		}
		break;
	}
	return EXIT_SUCCESS;


}
int view_patient_history()
{
	rpt *pt;
	book_app *ptr2;
	if(!start3)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	int an;
	while(1)
	{
		printf("\nenter patient aadhar number:\n");
		scanf("%d",&an);
		for(ptr2=start2;(ptr2);ptr2=ptr2->next);
		for(pt=start3;(pt);pt=pt->next);
		if(pt)
		{
			pt->visit_nb=ptr2->visit_no;

		}
		for(pt=start3;(pt) && pt->rpt_aadhar!=an;pt=pt->next);
		if(!pt)
		{

			printf("\n Given aadhar number is not present in patient records\n");
			continue;
		}

		printf("\n.........PATIENT RECORD HISTORY........\n");	      
		printf("NAME     AGE  WEIGHT  DISEASE  TREATMENT  MEDICINE  VISIT_NO\n");
		printf("\n%s---%d---%d---%s---%s---%s---%d\n",pt->rpt_name,pt->rpt_age,pt->rpt_weight,pt->disease,pt->treatment,pt->medicine,pt->visit_nb);
		break;
	}
	return EXIT_SUCCESS;


}
int edit_doctor_info()
{
	doctor *ptr;
	if(!start)
	{
		printf("\nEmpty list\n");
		return EXIT_FAILURE;
	}
	char str[20];
	while(1)
	{
		int MCI;
		printf("Enter MCI no for editing -");
		scanf("%d",&MCI);

		for(ptr=start;(ptr) && ptr->MCI_no!=MCI;ptr=ptr->next);
		if(!ptr)
		{
			printf("\nMCI no %d is not found",MCI);
			return EXIT_FAILURE;
		}
		while(1)
		{
			printf("\nEnter your Phone Number-");
			scanf("%s",ptr->phone_no);
			int len;
			len = strlen(ptr->phone_no);
			if(len != 10)
			{
				printf("\nPhone number must be of 10 digits please try again...\n");
				continue;
			}
			if(isdigit_validation(ptr->phone_no))
			{
				printf("\nPhone number should contain only digits\n");
				continue;
			}
			else
			{

				break;
			}
		}
		while(1)
		{
			printf("Enter email id ");
			scanf("%s",ptr->email_id);
			int ap,dp;
			char eid[20];
			strcpy(eid,ptr->email_id);
			for(int i=0;eid[i]!='\0';i++)
			{
				if(eid[i]=='@')
				{
					ap=i;
				}
				if(eid[i]=='.')
				{
					dp=i;
				}
			}
			if(ap>3 && (dp-ap)>3)
				break;
		else
			printf("Invalid Email id\n");
	}

	while(1)
	{
		int choice;
		printf("\n1.slot-1\n2.slot-2\n3.both slots\n");
		scanf("%d",&choice);
		if(choice<=0 || choice>=4)
		{
			printf("\nInvalid choice enter valid choice\n");
			continue;
		}
		if(choice == 1)
		{
			strcpy(ptr->slot,"slot-1");
			break;
		}
		if(choice == 2)
		{
			strcpy(ptr->slot,"slot-2");
			break;
		}
		if(choice == 3)
		{
			strcpy(ptr->slot,"Both");
			break;
		}
		else
			break;
	}
	printf("\nsuccesfully given details are updated\n");
	return EXIT_SUCCESS;
	}

}
int view_doctor_info()
{
	doctor *ptr;
	if(!start)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	printf("\n MCI_NO  NAME      AGE    GENDER SPECIALIZATION EMAIL_ID PHONE_NO  SLOT_SELECTION\n");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		printf("\n%d---%s---%4d---%5s---%10s---%10s---%5s---%5s\n",ptr->MCI_no,ptr->name,ptr->age,ptr->gender,ptr->specialization,ptr->email_id,ptr->phone_no,ptr->slot);
	}
	printf("\n");
	return EXIT_SUCCESS;
}
int delete_doctor_data()
{
	doctor *ptr,*prev;
        if(!start)
        {
                printf("\nEmpty List\n");
                return EXIT_FAILURE;
        }
        int mrno;
        printf("\nEnter mci no. for deleting-");
        scanf("%d",&mrno);
        if(mrno==start->MCI_no)
        {
                ptr=start;
                start=start->next;
                free(ptr);
        }
        else
        {
                for(ptr=start;(ptr) && ptr->MCI_no!=mrno;prev=ptr,ptr=ptr->next);
                if(!ptr)
                {
                        printf("\nMCI no %d not foundfor deletion \n",mrno);
                        return EXIT_FAILURE;
                }
                prev->next=ptr->next;
                free(ptr);
        }
	printf("Deleted data successfully");
        return EXIT_SUCCESS;
}


int isalpha_validation(char *str)
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
int isdigit_validation(char *str)
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
	
int CheckPassword(char *s)
{
        if(strlen(s)<5 || isdigit(s[0]))
               	return 0;
       	int f1,f2;
       	for(int i=0;i<strlen(s)-1;i++)
       	{
               	if(s[i]=='/' || s[i]==' ')
                     	return 0;
                if(isupper(s[i]))
                        f1=1;
                if(isdigit(s[i]))
                        f2=1;
        }
        if(f1==1 && f2==1)
                return 1;
        else
                return 0;

}

int doctor_license_query()
{
	doctor *ptr;
	book_app *ptr2;
	int mci;
	while(1)
	{
		printf("Enter your MCI no\n");
		scanf("%d",&mci);
		for(ptr=start;(ptr) && ptr->MCI_no!=mci ;ptr=ptr->next);
		if(!ptr)
		{
			printf("\n Invalid MCI no\n");
			continue;
		}
		if(!start2)
		{
			printf("\nEmpty list\n");
			return EXIT_FAILURE;
		}
		printf("\n.....viewing appointments with patient info....\n");
		printf("\nAADHAR_NO  NAME  SLOT\n");
		for(ptr2=start2;(ptr2);ptr2->next)
		{
			printf("\n%d---%s---%s\n",ptr2->aan,ptr2->pat_name,ptr2->book_slot);
		}
		break;
	}
		return EXIT_SUCCESS;
}


int doctor_file_to_list()
{
	doctor *new,*last;
	FILE *d;
	td td1;
        if((d=fopen("DOCTOR","rb"))==NULL)
        {
                printf("\nFile is not there to read from\n");
                return EXIT_FAILURE;
        }
        fread(&td1,sizeof(td),1,d);
        while(!feof(d))
        {
                if((new=(doctor *)calloc(1,sizeof(doctor)))==NULL)
                {
                        printf("\nMemory Allocation failed\n");
                        return EXIT_FAILURE;
                }
                new->MCI_no=td1.MCI_no;
                strcpy(new->name,td1.name);
                new->age=td1.age;
                strcpy(new->gender,td1.gender);
                strcpy(new->phone_no,td1.phone_no);
                strcpy(new->specialization,td1.specialization);
                strcpy(new->email_id,td1.email_id);
                strcpy(new->slot,td1.slot);
                strcpy(new->password,td1.password);
                if(!start)
                {
                        start=last=new;
                        new->next=NULL;
                }
                else
                {
                        last->next=new;
                        last=new;
                        new->next=NULL;
                }
                fread(&td1,sizeof(td),1,d);
        }
        fclose(d);
        return EXIT_SUCCESS;
}
int doctor_list_to_file()
{
	doctor *ptr,*new;
        td td2;
        if(!start)
        {
                printf("\nList is empty\n");
                return EXIT_FAILURE;
        }
        FILE *d1;
        if((d1=fopen("DOCTOR","wb"))==NULL)
        {
                printf("\nFile is not there to read from\n");
                return EXIT_FAILURE;
        }
        for(ptr=start;(ptr);ptr=ptr->next)
        {
                td2.MCI_no=ptr->MCI_no;
                strcpy(td2.name,ptr->name);
                td2.age=ptr->age;
                strcpy(td2.gender,ptr->gender);
                strcpy(td2.phone_no,ptr->phone_no);
                strcpy(td2.specialization,ptr->specialization);
                strcpy(td2.email_id,ptr->email_id);
                strcpy(td2.slot,ptr->slot);
                strcpy(td2.password,ptr->password);
                fwrite(&td2,sizeof(td),1,d1);

        }
        fclose(d1);
        return EXIT_SUCCESS;
}

int record_patient_history_file_to_list()
{
	rpt *new,*last;
	FILE *r;
	tr tr1;
        if((r=fopen("RPT","rb"))==NULL)
        {
                printf("\nFile is not there to read from\n");
                return EXIT_FAILURE;
        }
        fread(&tr1,sizeof(tr),1,r);
        while(!feof(r))
        {
                if((new=(rpt *)calloc(1,sizeof(rpt)))==NULL)
                {
                        printf("\nMemory Allocation failed\n");
                        return EXIT_FAILURE;
                }
                strcpy(new->rpt_name,tr1.rpt_name);
                strcpy(new->disease,tr1.disease);
                strcpy(new->treatment,tr1.treatment);
                strcpy(new->medicine,tr1.medicine);
		new->visit_nb=tr1.visit_nb;
                new->sno=tr1.sno;
		new->rpt_age=tr1.rpt_age;
		new->rpt_weight=tr1.rpt_weight;
		new->rpt_aadhar=tr1.rpt_aadhar;
		if(!start3)
                {
                        start3=last=new;
                        new->next=NULL;
                }
                else
                {
                        last->next=new;
                        last=new;
                        new->next=NULL;
                }
                fread(&tr1,sizeof(tr),1,r);
        }
        fclose(r);
        return EXIT_SUCCESS;
}
int record_patient_history_list_to_file()
{
	rpt *ptr3;
        tr tr2;
        if(!start3)
        {
                printf("\nList is empty\n");
                return EXIT_FAILURE;
        }
        FILE *r1;
        if((r1=fopen("RPT","wb"))==NULL)
        {
                printf("\nFile is not there to read from\n");
                return EXIT_FAILURE;
        }
        for(ptr3=start3;(ptr3);ptr3=ptr3->next)
        {
                strcpy(tr2.rpt_name,ptr3->rpt_name);
                strcpy(tr2.disease,ptr3->disease);
                strcpy(tr2.treatment,ptr3->treatment);
                strcpy(tr2.medicine,ptr3->medicine);
                tr2.sno=ptr3->sno;
		tr2.visit_nb=ptr3->visit_nb;
		tr2.rpt_age=ptr3->rpt_age;
		tr2.rpt_weight=ptr3->rpt_weight;
		tr2.rpt_aadhar=ptr3->rpt_aadhar;

		fwrite(&tr2,sizeof(tr),1,r1);

        }
        fclose(r1);
        return EXIT_SUCCESS;
}

