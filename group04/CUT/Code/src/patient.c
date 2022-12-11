#include "common.h"
#include "patient.h"

extern node *head;
int appointment=10;
void Appoint(node*pointer)
{
	printf("*******************  Patient Portal  ********************\n\n\n");
	int serial;
	char key;
	if(appointment==0){
		printf("Sorry! Today's Appointment Full. Try after 8 p.m. for tomorrows appointment\n\n\n");
		printf("Press any key to continue...");
		scanf("%c",&key);
		if(key>=0)
			return;
	}
	else{
		if(pointer==NULL){
			head=(node*)malloc(sizeof(node));
			pointer=head;
			pointer->next=NULL;
			printf("Enter Patient's name: ");
			getchar();
			gets(pointer->name);
			printf("Enter your adhaar number:");
			getchar();
			gets(pointer->adhaar);
			printf("Enter Patient's illness: ");
			getchar();
			gets(pointer->illness);
phone_tag1:
			printf("Enter Patient's Mobile Number: ");
			gets(pointer->phone);
		}
		else{
			while(pointer->next!=NULL)
			{
				pointer=pointer->next;
			}

			pointer->next=(node*)malloc(sizeof(node));
			pointer=pointer->next;
			pointer->next=NULL;
			printf("Enter patient's name: ");
			getchar();
			gets(pointer->name);
			printf("Enter your adhaar number:");
			getchar();
			gets(pointer->adhaar);
			printf("Enter patient's illness: ");
			getchar();
			gets(pointer->illness);
phone_tag:
			printf("Enter Patient's Mobile Number: ");
			gets(pointer->phone);
		}

		int len=strlen(pointer->phone);
		if(len!=10)
		{
			printf("Invalid Mobile Number. Try again\n");
			goto phone_tag1;
		}
		int i;
		for(i=0;pointer->phone[i]!='\0';i++)
		{
			if(pointer->phone[i]<'0' || pointer->phone[i]>'9')
			{
				printf("Invalid Mobile Number. Try again\n");
				goto phone_tag1;
			}
		}
		appointment--;
		serial=10-appointment;
		pointer->serial=serial;
		printf("\n\nAppointment accepted.\n");
		printf("Your serial number is %d.\n\n\n",pointer->serial);
		printf("Press any key to continue...");
		scanf("%c",&key);
		if(key>=0)
			return;
	}
}


void Delete(node *pointer){
	int del;
	char key; 
	node *temp;
	printf("********************  Appointment Deletion Portal  *******************\n\n\n");
	printf("Enter serial No : ");
	scanf(" %d",&del);
	if(pointer==NULL){
		printf("No Record Found!!!\n\n\n");
	}
	else if(pointer->serial == del){
		temp=pointer;
		pointer=NULL;
		free(temp);
		printf("\nAppointment Deletion Successful!!!\n\n");
	}  
	else{
		node *temp2, *temp1=pointer;
		while(temp1->next->serial != del){
			temp1=temp1->next;
		}
		temp2=temp1->next->next;
		temp=temp1->next;
		temp1->next=temp2;
		free(temp);
		printf("\nAppointment Deletion Successful!!!\n\n");
	}

	printf("Press any key to continue...");
	scanf("%c",&key);
	if(key>=0){
		return;
	}
} 


void UpdateMedicalRecord(node *pointer){

	int updt;
	char key;
	printf("*************************************  Patient Medical Record Updation portal  **********************************\n\n\n");
	printf("Enter Patient's serial no: ");
	scanf(" %d",&updt);
	if(pointer==NULL){
		printf("No Record Found!!!\n\n\n");
	}
	else if(pointer->serial == updt){
		printf("Update patient's illness: ");
		getchar();
		gets(pointer->illness);
		printf("Patients Medications:");
		getchar();
		gets(pointer->medications);
	}
	else{
		while(pointer->next->serial != updt){
			pointer=pointer->next;
		}

		printf("Enter patient's illness: ");
		getchar();
		gets(pointer->illness);
		printf("Patient's Medications:");
		getchar();
		gets(pointer->medications);

		printf("\n\nPatient's Medical Details Updation Successful!!!\n\n");
	}

	int len=strlen(pointer->phone);
	if(len!=10)
	{
		printf("Invalid Mobile Number. Try again\n");

	}
	int i;
	for(i=0;pointer->phone[i]!='\0';i++)
	{
		if(pointer->phone[i]<'0' || pointer->phone[i]>'9')
		{
			printf("Invalid Mobile Number. Try again\n");

		}
	}
	printf("\nPress any key to continue...");
	scanf("%c",&key);
	if(key>=0)
		return;
}
void Update(node *pointer){
	int updt;
	char key;
	printf("******************************************  Appointment Updation portal  ***********************************************\n\n\n");
	printf("Enter Patient's serial no: ");
	scanf(" %d",&updt); 
	if(pointer==NULL){
		printf("No Record Found!!!\n\n\n");
	}
	else if(pointer->serial == updt){
		printf("Update Patient's Name: ");
		getchar();
		gets(pointer->name);
		printf("Update patient's illness: ");
		getchar();
		gets(pointer->illness);
phone_tag1:
		printf("Update Patient's Mobile Number: ");
		gets(pointer->phone);
		printf("\n\nAppointment Updation Successful!!!\n\n");
	}  
	else{
		while(pointer->next->serial != updt){
			pointer=pointer->next;
		}
		printf("Update patient's name: ");
		getchar();
		gets(pointer->name);
		printf("Enter patient's illness: ");
		getchar();
		gets(pointer->illness);
phone_tag:
		printf("Update patient's Mobile Number: ");
		gets(pointer->phone);
		printf("\n\nAppointment Updation Successful!!!\n\n");
	}

	int len=strlen(pointer->phone);
	if(len!=10)
	{
		printf("Invalid Mobile Number. Try again\n");
		goto phone_tag1;
	}
	int i;
	for(i=0;pointer->phone[i]!='\0';i++)
	{
		if(pointer->phone[i]<'0' || pointer->phone[i]>'9')
		{
			printf("Invalid Mobile Number. Try again\n");
			goto phone_tag1;
		}
	}
	printf("\nPress any key to continue...");
	scanf("%c",&key);
	if(key>=0)
		return;
}



void Showlist(node *pointer)
{
	printf("***********************************************  Today's Appointment list  ***********************************************\n\n\n");
	if(pointer==NULL)
	{
		printf("No Appointment today!!!\n\n\n");
		return;
	}
	while(pointer!=NULL)
	{
		printf("%d: ",pointer->serial);
		printf("%s (Ph: %s ), Illness: %s\n\n",pointer->name,pointer->phone,pointer->illness);
		pointer=pointer->next;
	}
	printf("\n\n\nPress any key to go back to Doctor's menu: ");
	char key;
	getchar();
	scanf("%c",&key);
	if(key>=0)
	{   
		system("clear");
		return;
	}
}


void View(node *pointer)
{   
	printf("***********************************************  Appointment Portal  ***********************************************\n\n\n");
	int srl;
	printf("Enter your Serial no : ");
	scanf(" %d",&srl);
	if(pointer==NULL)
	{
		printf("No Appointment today!!!\n\n\n");
		return;
	}
	while(pointer->serial != srl)
	{
		pointer=pointer->next;
	}
	if(pointer->serial == srl){
		printf("%d: ",pointer->serial);
		printf("%s (Ph: %s ), Illness: %s\n\n",pointer->name,pointer->phone,pointer->illness);
	}
	else{
		printf("No Record Found!!!\n\n\n");
	}
	printf("\n\n\n\nPress any key to go back to Doctor's menu: ");
	char key;
	getchar();
	scanf("%c",&key);
	if(key>=0)
	{   
		system("clear");
		return;
	}
}



void Call(node *head)
{
	printf("***********************************************  Calling Portal  ***********************************************\n\n\n");
	node *temp;
	temp=head;
	char key;
	printf("\n\n");
	if(temp==NULL)
	{
		printf("No Appointment today!!!\n\n\n");
		printf("Press any key to go back to main menu");
		scanf("%c",&key);
		if(key>=0)
		{
			system("clear");
			return;
		}
	}
	printf("Calling:\n");
	printf("Serial %d: %s\nPhone:%s\nIllness:%s\n\n",temp->serial,temp->name,temp->phone,temp->illness);
	if(temp->next!=NULL)
	{
		temp=temp->next;
		printf("Next is:\n");
		printf("Serial %d: %s\nPhone:%s\nIllness:%s\n\n",temp->serial,temp->name,temp->phone,temp->illness);
	}
	printf("\n\nPress any key to go back to Doctor's Menu...");
	getchar();
	scanf("%c",&key);
	if(key>=0)
	{
		node *temp1=head;
		head=head->next;
		free(temp1);
		system("clear");
		return;
	}
}



void Pwrite(node *pointer){
	FILE *rptr = fopen("patient.txt","w");
	for(pointer=head; pointer; pointer=pointer->next){
		fprintf(rptr," %d ,%s ,%s %s\n",pointer->serial,pointer->name,pointer->phone,pointer->illness);
	}
	fclose(rptr);
	printf("\n\nData written to the patient file Successfully!!!\n\n");
	printf("\n\nPress any key to go back : ");
	char key;
	getchar();
	scanf("%c",&key);
	if(key>=0)
	{   
		return;
	}
}

