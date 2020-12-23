#include<string.h>
#include<stdlib.h>
#include <stdio.h> 

struct Hospital
{
        int P_Id;
        char F_Name[100];
    	char L_Name[100];
    	char Gender[100];
    	char phone[100];
    	char disease[100];
        struct Hospital *next;
}* head;



void create(int P_Id, char*F_Name, char*L_Name, char*Gender, char*phone, char*disease)
{ 
struct Hospital * hospital=(struct Hospital *)malloc(sizeof(struct Hospital));
        if(hospital==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        
	hospital->P_Id = P_Id;
	strcpy(hospital->F_Name, F_Name);
	strcpy(hospital->L_Name, L_Name);
	strcpy(hospital->Gender, Gender);
	strcpy(hospital->phone, phone);
	strcpy(hospital->disease, disease);
	hospital->next = NULL;
	
        if(head==NULL)
        {
               head = hospital;
        }
        
        else
        {
        		hospital->next = head;
				head = hospital;
                
        }
}
void search(int P_Id)
{
    struct Hospital * hospital = head;
	while(hospital!=NULL){
		if(hospital->P_Id==P_Id){
			printf("------------------------------------------------\n");
			printf("------------------------------------------------\n");
			printf("Patient ID: %d\n", hospital->P_Id);
			printf("First Name: %s\n", hospital->F_Name);
			printf("Last Name: %s\n", hospital->L_Name);
			printf("Gender: %s\n", hospital->Gender);
			printf("Phone Number: %s\n", hospital->phone);
			printf("Disease: %s\n", hospital->disease);
			printf("------------------------------------------------\n");
			printf("------------------------------------------------\n");
			return;
		}
		hospital = hospital->next;
	}
	printf("Patient ID %d is not found !!!\n", P_Id);
}
void display()
{
       struct Hospital * hospital = head;
	
    if(hospital==NULL){
	printf("Patient with ID %d is not found !!!\n",hospital->P_Id);
	exit(0);
}

	while(hospital!=NULL){
	
			printf("Patient ID: %d\n", hospital->P_Id);
			printf("First Name: %s\n", hospital->F_Name);
			printf("Last Name: %s\n", hospital->L_Name);
			printf("Gender: %s\n", hospital->Gender);
			printf("Phone Number: %s\n", hospital->phone);
			printf("Disease: %s\n", hospital->disease);
		hospital = hospital->next;
	}
	
	
}
void insert_begin(int P_Id, char*F_Name, char*L_Name, char*Gender, char*phone, char*disease)
{
        
        struct Hospital * hospital=(struct Hospital *)malloc(sizeof(struct Hospital));
        
        if(hospital==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        hospital->P_Id = P_Id;
		strcpy(hospital->F_Name, F_Name);
		strcpy(hospital->L_Name, L_Name);
		strcpy(hospital->Gender, Gender);
		strcpy(hospital->phone, phone);
		strcpy(hospital->disease, disease);
		hospital->next = NULL;
        if(head==NULL)
        {
                head=hospital;
        }
        else
        {
                hospital->next=head;
                head=hospital;
        }
}
void insert_end(int P_Id, char*F_Name, char*L_Name, char*Gender, char*phone, char*disease)
{
        struct Hospital *hospital,*ptr;
        hospital=(struct Hospital *)malloc(sizeof(struct Hospital));
        if(hospital==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        hospital->P_Id = P_Id;
		strcpy(hospital->F_Name, F_Name);
		strcpy(hospital->L_Name, L_Name);
		strcpy(hospital->Gender, Gender);
		strcpy(hospital->phone, phone);
		strcpy(hospital->disease, disease);
		hospital->next = NULL;
        if(head==NULL)
        {
                head=hospital;
        }
        else
        {
                ptr=head;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =hospital;
        }
} 
void insert_position(int P_Id, char*F_Name, char*L_Name, char*Gender, char*phone, char*disease)
{	
        struct Hospital *ptr,*hospital;
        
        int i,pos;
        hospital=(struct Hospital *)malloc(sizeof(struct Hospital));
        if(hospital==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        
        hospital->P_Id = P_Id;
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
		strcpy(hospital->F_Name, F_Name);
		strcpy(hospital->L_Name, L_Name);
		strcpy(hospital->Gender, Gender);
		strcpy(hospital->phone, phone);
		strcpy(hospital->disease, disease);
		hospital->next = NULL;
        if(pos==0)
        {
                hospital->next=head;
                head=hospital;
        }
        else
        {
                for(i=0,ptr=head;i<pos-1;i++) {
				 ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]\n");
                                return;
                        }
                }
                hospital->next =ptr->next ;
                ptr->next=hospital;
        }
}
void discharge(int P_Id)
{
  struct Hospital * hospital1 = head;
	struct Hospital * hospital2 = head; 
	while(hospital1!=NULL){
		
		if(hospital1->P_Id==P_Id){
			
			printf("Record with ID  %d Found !!!\n", P_Id);
			
			if(hospital1==hospital2){
				
				head = head->next;
				free(hospital1);
			}
			else{
				
				hospital2->next = hospital1->next;
				free(hospital1); 
			}
			
			printf("Record Successfully Deleted !!!\n");
			return;
			
		}
		hospital2 = hospital1;
		hospital1 = hospital1->next;
		
	}
	printf("Patient with ID %d is not found !!!\n", P_Id);      
}
void update(int P_Id)
{
	int upchp;
    struct Hospital * hospital = head;
	while(hospital!=NULL){
		
		if(hospital->P_Id==P_Id){
			printf("------------------------------------------------\n");
			printf("------------------------------------------------\n");
			printf("\nRecord with Patient ID %d Found !!!\n", P_Id);
			printf("------------------------------------------------\n");
			printf("------------------------------------------------\n");
			printf("Patient ID: %d\n", hospital->P_Id);
			printf("First Name: %s\n", hospital->F_Name);
			printf("Last Name: %s\n", hospital->L_Name);
			printf("Gender: %s\n", hospital->Gender);
			printf("Phone Number: %s\n", hospital->phone);
			printf("Disease: %s\n", hospital->disease);
		 	printf("\n------------------------------------------------\n");
			printf("Enter the Number of variable you want to update");
		 	printf("------------------------------------------------\n");
    		printf(" 1.First Name    \n");
      		printf(" 2.Last Name    \n");
        	printf(" 3.Gender    \n");
         	printf(" 4.Phone Number  \n");
          	printf(" 5.Disease       \n");
           	printf(" 6.Nothing to update       \n");
           	printf("------------------------------------------------\n");

     printf("\nEnter Choice: ");
        scanf("%d", &upchp);
        switch (upchp)
        {
			
		case 1 :	
			
			printf("Enter new First name: \t");
			scanf("%s", hospital->F_Name);
			printf("Updated Successfully!!!\n");
			break;
		case 2 :	
			printf("Enter new Last name: \t");
			scanf("%s", hospital->L_Name);
			printf("Updated Successfully!!!\n");
			break;
			
		case 3 :	
			printf("Enter Gender: \t");
			scanf("%s", hospital->Gender);
			printf("Updated Successfully!!!\n");
			break;
			
		case 4 :	
			printf("Enter new phone number: \t");
			scanf("%s", hospital->phone);
			printf("Updated Successfully!!!\n");
			break;
			
		case 5 :	
			printf("Enter disease: \t");
			scanf("%s",&hospital->disease);
			printf("Updated Successfully!!!\n");
			break;
	 	case 6:
   			exit(0);
      		break;
        default:
        	printf("\n Wrong Choice:\n");
         	break;
			
		}
			printf("------------------------------------------------\n");
			printf("------------------------------------------------\n");
			printf("Patient ID: %d\n", hospital->P_Id);
			printf("First Name: %s\n", hospital->F_Name);
			printf("Last Name: %s\n", hospital->L_Name);
			printf("Gender: %s\n", hospital->Gender);
			printf("Phone Number: %s\n", hospital->phone);
			printf("Disease: %s\n", hospital->disease);	
			printf("------------------------------------------------\n");
			printf("------------------------------------------------\n");
		return;
		}
			
		hospital = hospital->next;
		
	}
	printf("Patient with ID  %d is not found !!!\n", P_Id);
	
}
int main()     
{
		head = NULL;
        int choice;
        int upchp;
        int P_Id;
        char F_Name[100];
    	char L_Name[100];
    	char Gender[100];
    	char phone[100];
    	char disease[100];
        
        
        do{
      	 		printf("--------------------------------------\n");
      	 		printf("**************************************\n");
                printf("                MENU                  \n");
                printf("**************************************\n");
                printf("--------------------------------------\n");
                printf("\n 1.Enter a Patient    \n");
                printf("\n 2.Display  the list of Patients \n");
                printf("\n 3.Insert Patient at the beginning  \n");
                printf("\n 4.Insert Patient at the end  \n");
                printf("\n 5.Insert Patient at specified position\n");
                printf("\n 6.Discharge a Patient \n");
                printf("\n 7.Search for a Patient  \n");
                printf("\n 8.Update a Patient \n");
                printf("--------------------------------------\n");
                printf("--------------------------------------\n");
                
                printf("Enter your choice:\t");
                
                scanf("%d",&choice);
                
                switch(choice)
                {
                        case 1:
                						printf("Enter Patient ID: \t");
						                scanf("%d", &P_Id);
						                printf("Enter First name: \t");
						                scanf("%s", F_Name);
						                printf("Enter Last name: \t");
						                scanf("%s", L_Name);
						                printf("Gender: \t");
						                scanf("%s", Gender);
						                printf("Enter phone number: \t");
						                scanf("%s", phone);
                						printf("Disease: \t");
                						scanf("%s", disease);
                                        create(P_Id,F_Name,L_Name,Gender,phone,disease);
                                        break;             
                        case 2:
                                        display();
                                        break;             
                        case 3: 		printf("Enter Patient ID: \t");
						                scanf("%d", &P_Id);
						                printf("Enter First name: \t");
						                scanf("%s", F_Name);
						                printf("Enter Last name: \t");
						                scanf("%s", L_Name);
						                printf("Gender: \t");
						                scanf("%s", Gender);
						                printf("Enter phone number: \t");
						                scanf("%s", phone);
                						printf("Disease: \t");
                						scanf("%s", disease);
                                        insert_begin(P_Id,F_Name,L_Name,Gender,phone,disease);
                                        break;             
                        case 4:			printf("Enter Patient ID: \t");
						                scanf("%d", &P_Id);
						                printf("Enter First name: \t");
						                scanf("%s", F_Name);
						                printf("Enter Last name: \t");
						                scanf("%s", L_Name);
						                printf("Gender: \t");
						                scanf("%s", Gender);
						                printf("Enter phone number: \t");
						                scanf("%s", phone);
                						printf("Disease: \t");
                						scanf("%s", disease);
                                        insert_end(P_Id,F_Name,L_Name,Gender,phone,disease);
                                        break;             
                        case 5:			printf("Enter Patient ID:\t ");
						                scanf("%d", &P_Id);
						                printf("Enter First name: \t");
						                scanf("%s", F_Name);
						                printf("Enter Last name: \t");
						                scanf("%s", L_Name);
						                printf("Gender: \t");
						                scanf("%s", Gender);
						                printf("Enter phone number: \t");
						                scanf("%s", phone);
                						printf("Disease: \t");
                						scanf("%s", disease);
                                        insert_position(P_Id,F_Name,L_Name,Gender,phone,disease);
                                        break;
										            
                        case 6:			printf("Enter Patient ID to discharge: \t");
						                scanf("%d", &P_Id);
                                        discharge(P_Id);
                                        break;            
                       
                        case 7:
                        				printf("Enter Patient ID to search: \t");
						                scanf("%d", &P_Id);
                                        search(P_Id);
                                        break;
                        case 8:
                        				printf("Enter Patient ID to Update: \t");
						                scanf("%d", &P_Id);
                                        update(P_Id);
                                        break;
                        case 9:
                                        exit(0);
                                        break;
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        } while (choice != 0);
}