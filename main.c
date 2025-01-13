#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#include<windows.h>

///Structure Declaration
struct Contact{
char Name[50];
char Address[50];
char Mobile[20];
char Gmail[20];
}list;

///Global Variables Declaration
FILE *fp,*ftmp,*ff;
char search[20];

///Function declaration
void addcontact();
void listcontact();
void searchcontact();
void deletecontact();
void editcontact();
void addfavourite();
void listfavourite();
void deletefavourite();

int main(){

int choice;

printf("\n\n\t\t***************************************************************");
printf("\n\t\t***************************************************************");
printf("\n\t\t************Welcome to Phone Book Management System************");
printf("\n\t\t***************************************************************");
printf("\n\t\t***************************************************************");
printf("\n\n\t\t'Here you can add, edit, remove and view your contacts\n\n\t\twith others options. Feel free to use it for your purpose!!!' ");
printf("\n\n\n\t\t->Enter any key to continue further.");
getch();
menu:
system("cls");
printf("\n\n\t\t-------------------------------------------------------------");
printf("\n\n\t\t-------------------------------------------------------------");
printf("\n\t\t\t\t************MAIN MENU************");
printf("\n\t\t-------------------------------------------------------------");
printf("\n\n\t\t-------------------------------------------------------------");
	printf("\n\t\t[1] Add a new contact.\n");
	printf("\t\t[2] List all contacts.\n");
	printf("\t\t[3] Search a contact.\n");
	printf("\t\t[4] Delete a contact.\n");
	printf("\t\t[5] Edit a contact.\n");
	printf("\t\t[6] Add favorite contact.\n");
	printf("\t\t[7] List favorite contact.\n");
	printf("\t\t[8] Delete a favorite contact.\n");
	printf("\t\t[0] Exit.\n\n");
	printf("\t\t============================================================\n\t\t");
	printf("Enter the choice:");
	scanf("%d",&choice);

	switch(choice)
	{
		case 0:
			system("cls");
			printf("\n\nAre you sure you want to exit?");
			break;
		case 1:
	     	addcontact();
	     	printf("\nRECORD SAVED!!!");
	     	break;
        case 2:
            listcontact();
			system("cls");
			break;
        case 3:
            searchcontact();
            system("cls");
            break;
        case 4:
			deletecontact();
			break;
		case 5:
			editcontact();
			system("cls");
			printf("\n\nCONTACT EDITED!");
			break;
        case 6:
			addfavourite();
			system("cls");
			printf("\n\nCONTACT ADDED TO FAVOURITE!");
			break;
		case 7:
			listfavourite();
			system("cls");
			break;

        case 8:
			deletefavourite();
			system("cls");
			break;

	    default:
			printf("\n\nInvalid choice.");
			break;
	}///1st Switch Case Ends

	printf("\n1. Main Menu.");
	printf("\n2. Exit.");

	printf("\nEnter your choice : ");
	scanf("%d",&choice);

	switch(choice){

	case 1:
	    goto menu;
	        break;

    case 2:
        exit(1);


	}///2nd Switch Case Ends

return 0;
}///Main ends

///Function to add a new contact.
void addcontact(){
   struct Contact *ptr;
    int N,i;

fp = fopen("project.txt","a");///Creating file named "project.txt" in append mode
if(fp==NULL){
    printf("\nFile could not be opened.");
    exit(1);
}
system("cls");///Clears the current content in compiler.


printf("\nHow many records do you want to save?");
scanf("%d",&N);

ptr = (struct Contact*)calloc(N,sizeof(struct Contact)); ///Dynamic Memory Allocation
if(ptr==NULL){
    printf("\nMemory could not be reserved.");
    exit(1);
}

for(i=0;i<N;i++){
            system("cls");
            printf("\n\n\t\t-------------------------------------------------------------");
            printf("\n\t\t\t\t************ADD CONTACT(S)************");
            printf("\n\t\t-------------------------------------------------------------");
            printf("\n\tName : ");
            fflush(stdin);
            gets((ptr+i)->Name);
            printf("\n\tAddress : ");
            fflush(stdin);
            gets((ptr+i)->Address);
            printf("\n\tMobile Number : ");
            fflush(stdin);
            gets((ptr+i)->Mobile);
            printf("\n\tGmail : ");
            fflush(stdin);
            gets((ptr+i)->Gmail);
            printf("\n");
			fwrite((ptr+i),sizeof(struct Contact),1,fp);
}///Loop ends
system("cls");
free(ptr);///Setting the pointer free.
fclose(fp);///Closing the file.
}///Function to add a new contact ends.

///Function to list the saved contacts starts here.
void listcontact(){

system("cls");
fp=fopen("project.txt","r");///Creating file named "project.txt" in read mode.
if(fp==NULL){
    printf("\nThe file couldn't be opened in read mode.");

}
printf("\t\t\t\t*********************************************************");
printf("\n\t\t\t\t*********************************************************");
printf("\n\t\t\t\t\t\t----LIST OF CONTACTS----");
printf("\n\t\t\t\t*********************************************************");
printf("\n\t\t\t\t*********************************************************");
///Reading data from files in structure variable.
while(fread(&list,sizeof(struct Contact),1,fp)==1){

    printf("\n\tName : %s",list.Name);
    printf("\n\tAddress:%s",list.Address);
    printf("\n\tMobile :%s",list.Mobile);
    printf("\n\tGmail :%s",list.Gmail);
printf("\n\n");
}
fclose(fp);///Closing a file.
getch();
}///Function to list the saved contacts ends here.


///Function to search a contact from saved contacts starts here.
void searchcontact(){

system("cls");
int count=0;
printf("\t\t\t\t*********************************************************");
printf("\n\t\t\t\t*********************************************************");
printf("\n\t\t\t\t\t\t----SEARCH CONTACTS----");
printf("\n\t\t\t\t*********************************************************");
printf("\n\t\t\t\t*********************************************************");
fp=fopen("project.txt","r");
if(fp==NULL){
    printf("\nThe file couldn't be opened in read mode.");

}///IF ends

printf("\n\tEnter mobile number or name of contact to search : ");
fflush(stdin);
gets(search);

///Reading data from files in structure variable.
while(fread(&list,sizeof(struct Contact),1,fp)==1){
        if(stricmp(list.Name,search)==0 || strcmp(list.Mobile,search)==0){
            count++;
            printf("\n\tName : %s",list.Name);
            printf("\n\tAddress : %s",list.Address);
            printf("\n\tMobile : %s",list.Mobile);
            printf("\n\tE-mail : %s",list.Gmail);
            printf("\n\t==================================\n");
        }

}///WHILE LOOP ENDS
if(count==0){
    printf("\n\t==================================\n");
    printf("\n\tRecord not found!!");
}else{
printf("\t==================================");
printf("\n\t%d Record(s) found.",count);
}///If else ends

getch();
fclose(fp);///Closing a file.
}///Function to search a contact from saved contacts ends here.

///Function to edit a contact from saved contacts starts here.
void editcontact(){

char edit[30];
fp=fopen("project.txt","r");///Creating file named "project.txt" in read mode
if(fp==NULL){
 printf("The file couldn't be read");
 exit(-1);
}
ftmp=fopen("temp.txt","w");///Creating file named "temp.txt" in read mode
if(ftmp==NULL){
printf("The file couldn't be created");
exit(-1);
}
printf("\n\t********************************************************");
printf("\n\t\t\t----EDIT CONTACT----");
printf("\n\t********************************************************");
printf("\nEnter the name of the contact you want to edit : ");
fflush(stdin);
gets(edit);
rewind(fp);///Sets the pointer in the file in the beginning
///Reading data from files in structure variable.
while(fread(&list,sizeof(struct Contact),1,fp)==1){
    if(strcmp(list.Name,edit)!=0){
        fwrite(&list,sizeof(struct Contact),1,ftmp);
    }///IF Statement ends

}///While loop ends.

printf("\n\tEditing the new contact.");
printf("\n\n\tName : ");
gets(list.Name);
printf("\n\tAddress : ");
gets(list.Address);
printf("\n\tMobile : ");
gets(list.Mobile);
printf("\n\tGmail : ");
gets(list.Gmail);

fwrite(&list,sizeof(struct Contact),1,ftmp);
fclose(fp);
fclose(ftmp);
remove("project.txt");
rename("temp.txt","project.txt");
getch();
}///Function to edit a contact from saved contacts ends here.


///Function to delete a contact from saved contacts starts here.
void deletecontact(){

system("cls");
fp=fopen("project.txt","r");///Creating file named "project.txt" in read mode.
if(fp==NULL){
    printf("\nThe file couldn't be opened in read mode.");

}

ftmp=fopen("temp.txt","w");
if(ftmp==NULL){
    printf("\nThe file couldn't be opened.");

}
printf("\n\t********************************************************");
printf("\n\t\t\t----Delete a contact----");
printf("\n\t********************************************************");
printf("\n\n\tEnter the contact name you want to delete : ");
fflush(stdin);
gets(search);
///Reading data from files in structure variable.
while(fread(&list,sizeof(struct Contact),1,fp)==1){
        if(stricmp(search,list.Name)!=0){
            fwrite(&list,sizeof(struct Contact),1,ftmp);
        }///IF statement ends


}///While loop ends
fclose(fp);///Closing a file.
fclose(ftmp);///Closing a file.
remove("project.txt");///Removing main file where contacts to be deleted are present.
rename("temp.txt","project.txt");///Renaming temporary file holding the contacts as main file.
getch();
}
///Function to delete a contact from saved contacts ends here.


///Function to select and add favourite contact from saved ones starts.
void addfavourite(){

system("cls");
printf("\n\t\t\t\t*********************************************************");
printf("\n\t\t\t\t\t\t----ADD FAVOURITE(S)----");
printf("\n\t\t\t\t*********************************************************");

char favName[30];

fp=fopen("project.txt","r");///Creating file named "project.txt" in read mode
ff=fopen("favourite.txt","a");///Creating file named "favourite.txt" in append mode
if(ff==NULL){
    printf("The file could not be created");
    exit(1);
}
if(fp==NULL){
    printf("The file could not be opened to read data.");
    exit(1);
}

printf("\n\tWrite the name of contact you want to add to favourite :");
fflush(stdin);
gets(favName);
///Reading data from files in structure variable.
while(fread(&list,sizeof(struct Contact),1,fp)==1){
    if(stricmp(list.Name,favName)==0){
        fwrite(&list,sizeof(struct Contact),1,ff);
    }///IF CONDITION ENDS
}///WHILE LOOP ENDS

}///Function to select and add favourite contact from saved ones ends.


///Function to list favourite contact from saved ones ends.
void listfavourite(){

char username[20]="orchid";
char password[20]="orchid";
char userName[20];
char passWord[20];

ff=fopen("favourite.txt","r");///Creating file named "favourite.txt" in read mode
if(ff==NULL){
  printf("The file couldn't be read");
}

printf("\n\tPlease enter username and password to proceed.");
printf("\n\tEnter user-name :");
fflush(stdin);
gets(userName);
printf("\n\tEnter password :");
fflush(stdin);
gets(passWord);
///Setting up password so only authorized user can view favourite contacts.
if((strcmp(username,userName)==0)&&(strcmp(password,passWord)==0)){
system("cls");
printf("\n\t\t\t\t*********************************************************");
printf("\n\t\t\t\t\t\t----LIST OF FAVOURITES----");
printf("\n\t\t\t\t*********************************************************");
///Reading data from files in structure variable.
while(fread(&list,sizeof(struct Contact),1,ff)==1){
    printf("\n\n\tName : %s",list.Name);
    printf("\n\tAddress : %s",list.Address);
    printf("\n\tMobile : %s",list.Mobile);
    printf("\n\tE-mail :%s",list.Gmail);
    printf("\n\n\t==================================");
    printf("\n\t==================================");
}///while loop ends
}///IF Statement Ends
else{
    printf("\n\tUsername and Password did not match.");
}///Else Statement ends
fclose(ff);
getch();
}///Function to list favourite contact ends.

///Function to delete a favourite contact starts.
void deletefavourite(){

system("cls");
fp=fopen("favourite.txt","r");///Creating file named "favourite.txt" in read mode
if(fp==NULL){
    printf("\nThe file couldn't be opened in read mode.");

}

ftmp=fopen("temp.txt","w");///Creating file named "temp.txt" in read mode
if(ftmp==NULL){
    printf("\nThe file couldn't be opened.");

}
printf("\n\t********************************************************");
printf("\n\t\t\t----Delete favourite contact----");
printf("\n\t********************************************************");
printf("\n\n\tEnter the contact name you want to delete : ");
fflush(stdin);
gets(search);
///Reading data from files in structure variable.
while(fread(&list,sizeof(struct Contact),1,fp)==1){
        if(stricmp(search,list.Name)!=0){
            fwrite(&list,sizeof(struct Contact),1,ftmp);
        }///IF Statement ends
}///While loop ends
fclose(fp);
fclose(ftmp);
remove("favourite.txt");///Removing main file where contacts to be deleted are present.
rename("temp.txt","favourite.txt");///Renaming temporary file holding the contacts as main file.
getch();
}///Function to delete a favourite contact ends.
