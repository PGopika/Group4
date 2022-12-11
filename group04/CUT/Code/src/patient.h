#ifndef CUST_H
#define CUST_H


typedef struct node
{
    int serial;
    char name[100];
    char phone[12];
    char illness[100];
    char adhaar[12];
    char medications[100];
    struct node *next;
}node;

//for receptionist use
void Appoint(node *);
void Delete(node *);
void Update(node *);
void View(node *);
void UpdateMedicalRecord(node *);

//for doctor use
void Showlist(node *);
void Call(node *);
void Pwrite(node *);

#endif
