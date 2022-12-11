#include "common.h"
#include "doctor.h"

extern docnode *dochead;

void addDoc(docnode *docpointer){
	printf("**************  Doctor's  Portal  ************\n\n\n");
	int srl=1;
	char key;

	if(docpointer==NULL){
		dochead=(docnode*)malloc(sizeof(docnode));
		docpointer=dochead;
		docpointer->next=NULL;  
		printf("Enter Doctor's name: ");
		getchar();
		gets(docpointer->name);
		printf("Enter Doctor's Specialization : ");
		getchar();
		gets(docpointer->designation);
		printf("Enter your MIC licence number:");
		getchar();
		gets(docpointer->MIC);
		printf("Please choose your available slot:");
		printf("\n1.9 AM - 12 PM\n2.6 PM -9 PM\n");
phone_tag1:
		printf("Enter Doctor's Mobile Number: ");
		gets(docpointer->phone);

	}
	else{
		while(docpointer->next!=NULL)
		{
			docpointer=docpointer->next;
		}
		docpointer->next=(docnode*)malloc(sizeof(docnode));
		docpointer=docpointer->next;
		docpointer->next=NULL;
		printf("Enter Doctor's name: ");
		getchar();
		gets(docpointer->name);
		printf("Enter Doctor's Specialization : ");
		getchar();
		gets(docpointer->designation);
		printf("Enter the MIC licence number:");
		getchar();
		printf("Please choose your available time:");
		printf("\n1.9 AM- 12 PM\n2.6 PM-9 PM\n");
phone_tag:
		printf("Enter Doctor's Mobile Number: ");
		gets(docpointer->phone);

	}

	int len=strlen(docpointer->phone);
	if(len!=10)
	{
		printf("Invalid Mobile Number. Try again\n");
		goto phone_tag1;
	}
	int i;
	for(i=0;docpointer->phone[i]!='\0';i++)
	{
		if(docpointer->phone[i]<'0' || docpointer->phone[i]>'9')
		{
			printf("Invalid Mobile Number. Try again\n");
			goto phone_tag1;
		}
	}
	docpointer->serial=srl;
	srl++;
	printf("\n\nDoctor's detail added Successfully\n\n");
	printf("Press any key to continue...");
	scanf("%c",&key);
	if(key>=0){
		return;
	}
}



void updateDoc(docnode *docpointer){
	int updt;
	char key;
	printf("*************************************************  Doctor's detail Updation Portal  ******************************************************\n\n\n");
	printf("Enter Doctor's serial no: ");
	scanf(" %d",&updt); 
	if(docpointer==NULL){
		printf("\n\nNo Record Found!!!\n\n\n");
		return;
	}
	else{
		while(docpointer->serial != updt){
			docpointer=docpointer->next;
		}
		printf("Update Doctor's name: ");
		getchar();
		gets(docpointer->name);
		//printf("Update Doctor's Designation : ");
		//getchar();
		//gets(docpointer->designation);
phone_tag1:
		printf("Update Doctor's Mobile Number: ");
		gets(docpointer->phone);
		printf("\n\nDoctor's detail Updation Successful!!!\n\n");

		int len=strlen(docpointer->phone);
		if(len!=10)
		{
			printf("Invalid Mobile Number. Try again\n");
			goto phone_tag1;
		}
		int i;
		for(i=0;docpointer->phone[i]!='\0';i++)
		{
			if(docpointer->phone[i]<'0' || docpointer->phone[i]>'9')
			{
				printf("Invalid Mobile Number. Try again\n");
				goto phone_tag1;
			}
		}
		printf("Press any key to continue...");
		scanf("%c",&key);
		if(key>=0){
			return;
		}
	}
}



void docProfile(docnode *docpointer){
	printf("*************************************************  Doctor's Profile ******************************************************\n\n\n");
	if(docpointer==NULL)
	{
		printf("No Record Found!!!\n\n\n");
		return;
	}
	while(docpointer!=NULL)
	{	
		printf("\t\t\t\t--------My Profile---------\n");
		printf("\t\t\t\tLogin ID\t\t:\t");
		printf("%d ",docpointer->serial);
		printf("\n");
		printf("\t\t\t\tName\t\t\t:\t");
		printf("%s",docpointer->name);
		printf("\n");
		printf("\t\t\t\tSpecialization\t\t:\t");
		printf("%s",docpointer->designation);
		printf("\n");
		printf("\t\t\t\tContact No\t\t:\t");
		printf("%s",docpointer->phone);
		printf("\n");
		docpointer=docpointer->next;
	}
	printf("\n\n\n\Press any key to go back : ");
	char key;
	getchar();
	scanf("%c",&key);
	if(key>=0)
	{   
		return;
	}
}

void viewDoc(docnode *docpointer){
	printf("***************  Doctor's Profile ********************* \n\n\n");
	if(docpointer==NULL)
	{
		printf("No Record Found!!!\n\n\n");
		return;
	}
	while(docpointer!=NULL)
	{	
		printf("\t\t\t\t--------LIST OF DOCTORS---------\n");
		printf("\t\t\t\tSerial No\t\t:\t");
		printf("%d ",docpointer->serial);
		printf("\n");
		printf("\t\t\t\tName\t\t\t:\t");
		printf("%s",docpointer->name);
		printf("\n");
		printf("\t\t\t\tSpecialization\t\t:\t");
		printf("%s",docpointer->designation);
		printf("\n");
		printf("\t\t\t\tContact No\t\t:\t");
		printf("%s",docpointer->phone);
		printf("\n");
		docpointer=docpointer->next;
	}
	printf("\n\n\n\Press any key to go back : ");
	char key;
	getchar();
	scanf("%c",&key);
	if(key>=0)
	{   
		return;
	}
}


void Dwrite(docnode *docpointer){
	FILE *rptr = fopen("doctor.txt","w");
	for(docpointer=dochead; docpointer; docpointer=docpointer->next){
		fprintf(rptr," %d ,%s ,%s ,%s\n",docpointer->serial,docpointer->name,docpointer->phone,docpointer->designation);
	}
	fclose(rptr);
	printf("\n\nData written to the doctor file Successfully!!!\n\n");
	printf("\n\nPress any key to go back : ");
	char key;
	getchar();
	scanf("%c",&key);
	if(key>=0)
	{   
		return;
	}
}
