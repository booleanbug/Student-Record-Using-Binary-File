#include<stdlib.h>
#include <stdio.h>
#include "binaryFile.h"


void insert(){
    FILE *fp;
    char ans;
    int i;

    fp=fopen("data.dat","ab");	
    if(fp==NULL)
    {
        printf("File could not open");
        exit(0);
    }

    while(1)
    {
        printf("\nEnter Student Record\n");
        printf("Mis No:");
        scanf("%d",&student.mis);
        getchar();
        printf("Name:");
        gets(student.name);
        getchar();
        printf("Stream:");
        gets(student.stream);
        printf("CGPA :");
        scanf("%f",&student.cgpa);
        getchar();
        /* write a record to binary file */
        fwrite(&student,sizeof(student),1,fp);
        printf("\nRecord has been added successfully");

        printf("\nAdd more records? press y or n = \n");
        ans=getche();
        if(ans=='n' || ans=='N')
        break;
    }
    fclose(fp);
}

void display(){
    FILE *fptr;

    char ans;
    int i;

    /*open binary file in read mode*/
    fptr=fopen("data.dat","rb");	
    if(fptr==NULL)
    {
        printf("File could not open");
        exit(0);
    }

    printf("\nRecords in Student File are:");
    printf("\n=======================");
    i=1;
    while((fread(&student,sizeof(student),1,fptr)==1))
    {
        
        printf("\nRecord No:%d",i);
        printf("\n------------------");
        printf("\nMisNo : %d",student.mis);
        printf("\nName : %s",student.name);
        printf("\nCGPA : %f",student.cgpa);
        printf("\nStream : %s",student.stream);
        i++;
        printf("\n=======================");
    }
    fclose(fptr);
}

void search(){
    FILE *fptr;

    int found=0, roll;


    /*open binary file in read mode*/
    fptr=fopen("data.dat","rb");	
    if(fptr==NULL)
    {
        printf("File could not open");
        exit(0);
    }

    printf("\n Enter Roll No of Student to Search Record=");
    scanf("%d",&roll);

    while((fread(&student,sizeof(student),1,fptr)==1))
    {
        
        if(student.mis == roll)
        {
        found=1;
        printf("\nRecord of Student With RollNo %d is as follows:",roll);
        printf("\n=======================");
        
        printf("\nMIS No : %d",student.mis);
        printf("\nName : %s",student.name);
        printf("\nCGPA : %f",student.cgpa);
        printf("\nName : %s",student.stream);
        
        printf("\n=======================\n");
        
        break;
    }
    }
    if(found==0)
    printf("\n Record Not found in this file!");
    fclose(fptr);
}

void delete(){
    int mis;
    scanf("%d",&mis);
    FILE *fp;
	FILE *fp_tmp;
	int found = 0 ;

	fp=fopen("data.dat", "rb");
	if (!fp) {
		printf("Unable to open file %s", "data.dat");
	}
	fp_tmp=fopen("tmp.bin", "wb");
	if (!fp_tmp) {
		printf("Unable to open file temp file.");
	}
	
	while (fread(&student,sizeof(student),1,fp) != NULL) {
		if (student.mis == mis) {
			printf("A record with requested name found and deleted.\n\n");
			found=1;
		} else {
			fwrite(&student, sizeof(student), 1, fp_tmp);
		}
	}
	if (! found) {
		printf("No record(s) found with the requested name: %d\n\n", mis);
	}

	fclose(fp);
	fclose(fp_tmp);

	remove("data.dat");
	rename("tmp.bin", "data.dat");
}