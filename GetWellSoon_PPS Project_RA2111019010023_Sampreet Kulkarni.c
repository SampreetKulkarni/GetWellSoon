#include<stdio.h>
#include<conio.h>
#include<string.h>

//user defined datatype
//group all related data
struct medi
{
	int medId;
	char medName[20];
	char medCompName[20];
	int qty;
	float price;
};

struct medi med[100]; //array of medicine
int count=0;

//To add a new medicine
void add()
{
	int n;
	printf("\n\n\n ADDING NEW MEDICINE\n\n\n");
	if(count==0) //auto generation of medicine id 
		count=1;
	else
		count++;
	
	med[count-1].medId  = count;
	printf("\n\nEnter Medicine Name:");
	fflush(stdin);//to remove \n 
	gets(med[count-1].medName);
	printf("\n\nEnter Medicine Company Name:");
	gets(med[count-1].medCompName);
	printf("\n\nEnter Medicine Quantity:");
	scanf("%d",&med[count-1].qty);
	printf("\nEnter Medicine Price:");
	scanf("%f",&med[count-1].price);

	printf("\nMEDICINE ADDED SUCCESSFULLY!\n");
	return;
}

//To search for a medicine based on the medicine name
void search()
{
	char sname[20];
	int i;
	int flag=0;
	printf("\nEnter Medicine Name to be searched:");
	fflush(stdin);
	gets(sname);
	for(i=0;i<count;i++)
	{
		if(strcmp(sname,med[i].medName)==0)
		{
			printf("\n%d   %s   %s   %d   %f\n",med[i].medId,med[i].medName,med[i].medCompName,med[i].qty,med[i].price);
			printf("\nMedicine Found!");
			flag=1;//medicine found then flag raised to 1
			break;
		}
	}
	if(flag==0)
		printf("\nMedicine Not Found!");

	return;
}

//Modify medicine details by searching based on medicine name
void modify()
{
	char mname[20];
	int i;
	int flag=0;
	printf("\nEnter Medicine Name to be modified:");
	fflush(stdin);
	gets(mname);
	for(i=0;i<count;i++)
	{
		if(strcmp(mname,med[i].medName)==0)
		{
			printf("\n%d   %s   %s   %d   %f\n",med[i].medId,med[i].medName,med[i].medCompName,med[i].qty,med[i].price);
			printf("\nMedicine Found!");
			
			flag=1;
			printf("\n\n ENTER NEW DETAILS OF MEDICINE\n\n");
			printf("\n\nEnter new Medicine Name:");
			fflush(stdin);
			gets(med[i].medName);
			printf("\n\nEnter new Medicine Company Name:");
			gets(med[i].medCompName);
			printf("\n\nEnter new Medicine Quantity:");
			scanf("%d",&med[i].qty);
			printf("\nEnter new Medicine Price:");
			scanf("%f",&med[i].price);

			printf("\nMEDICINE MODIFIED SUCCESSFULLY!\n");
			break;
		}
	}
	if(flag==0)
		printf("\nMedicine Not Found!");

	return;
}


//To delete medicine by searching based on medicine name
void deleteM()
{
	char mname[20];
	int i;
	int flag=0;
	printf("\nEnter Medicine Name to be deleted:");
	fflush(stdin);
	gets(mname);
	for(i=0;i<count;i++)
	{
		if(strcmp(mname,med[i].medName)==0)
		{
			printf("\n%d   %s   %s   %d   %f\n",med[i].medId,med[i].medName,med[i].medCompName,med[i].qty,med[i].price);
			printf("\nMedicine Found!");
			med[i].medId = -111;
			flag=1;
			

			printf("\nMEDICINE DELETED SUCCESSFULLY!\n");
			break;
		}
	}
	if(flag==0)
		printf("\nMedicine Not Found!");

	return;
}

//To display all the medicines
void display()
{
	int i;
	for(i=0;i<count;i++)
	{
		if(med[i].medId!=-111)
		{
			printf("\n%d   %s   %s   %d   %f\n",med[i].medId,med[i].medName,med[i].medCompName,med[i].qty,med[i].price);
		}
	}
	return;
}


//main Menu
void menu()
{
	int ch;
	do
	{
		printf("\nMENU\n");
		printf("\nAdd Medicine   1");
		printf("\nDisplay Medicine 2");
		printf("\nDelete Medicine  3");
		printf("\nModify Medicine 4");
		printf("\nSearch Medicine 5");
		printf("\nExit 6\n\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			   add();
			   break;
		case 2: 
				display();
				break;
		case 3:
				deleteM();
				break;
		case 4:
				modify();
				break;
		case 5:
				search();
				break;
		case 6:
				printf("\n\n\nGET WELL SOON!\n\n\nExiting!!!\n\nTHANK YOU\n\n");
				break;
		}
	}while(ch!=6);
}


//main function
void main()
{
	menu();

	getch();
	return;
}