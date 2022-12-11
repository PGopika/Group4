#ifndef DPH_H
#define DPH_H

typedef struct doctor_details
{
        int  MCI_no;
        char name[20];
        int age;
        char gender[10];
        char specialization[15];
        char  phone_no[11];
        char email_id[20];
        char password[10];
        char slot[15];
        struct doctor_details *next;
}doctor;
doctor *start;

typedef struct doc_temp
{
        int MCI_no;
        char name[20];
        int age;
        char gender[10];
        char specialization[15];
        char phone_no[11];
        char email_id[20];
        char password[10];
        char slot[15];
}td; 

typedef struct patient_details
{
        int aadhar_no;
        char name[20];
        int age;
        int weight;
        char gender[10];
        char phone_no[11];
        struct patient_details *next;
}patient;
patient *start1;

typedef struct pat_temp
{
	int aadhar_no;
        char name[20];
        int age;
        int weight;
        char gender[10];
        char phone_no[11];
}tp;

typedef struct book_appoint
{
	char doc_name[20];
	char pat_name[20];
	int aan;
	int license_no;
	int visit_no;
	char book_slot[15];
	struct book_appoint *next;
}book_app;
book_app *start2,*last;

typedef struct book_temp
{
	char doc_name[20];
	char pat_name[20];
	int aan;
	int visit_no;
	int license_no;
	char book_slot[15];
}tb;


typedef struct record_pat_history
{
	char rpt_name[20];
        char disease[15];
        char treatment[20];
        char medicine[20];
	int visit_nb;
	int sno;
	int rpt_age;
	int rpt_weight;
	int rpt_aadhar;
        struct record_pat_history *next;
}rpt;
rpt *start3;

typedef struct record_pat_temp
{
	char rpt_name[20];
        char disease[15];
        char treatment[20];
        char medicine[20];
	int visit_nb;
	int sno;
	int rpt_age;
	int rpt_weight;
	int rpt_aadhar;
}tr;


//main functions


int patient_corner();
int doctor_corner();
int admin_corner();

//admin corner functions


int patient_file_maintenance();
int doctor_file_maintenance();
int doctor_license_query();
int edit_patient_data();
int view_patient_data();
int delete_patient_data();
int delete_doctor_data();


//patient corner functions


int patient_registration();
int book_appointment();



//doctor corner functions

int doctor_registration();
int doctor_login(); 
int view_bookings();
int record_patient_history();
int view_patient_history();
int edit_doctor_info();
int view_doctor_info();


//file handaling functions


int doctor_file_to_list();
int doctor_list_to_file();
int patient_list_to_file();
int patient_file_to_list();
int book_appointment_file_to_list();
int book_appointment_list_to_file();
int record_patient_history_file_to_list();
int record_patient_history_list_to_file();


//validation functions

int CheckPassword();
int isalpha_validation(char *);
int isdigit_validation(char *);
int isalpha_validation1(char *);
int isdigit_validation1(char *);

#endif

