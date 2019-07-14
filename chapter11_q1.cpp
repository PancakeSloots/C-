#pragma warning(disable: 4996)
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
//Hardware Inventory
//Database of tools, requires hardware.dat file in source files
//1-Add 2-Update 3-Delete 4-List 5-Exit
//@author Peter Mitchell Adams
//padam2d@acd.ccac.edu
//@date 7/13/2019

struct hardwareData
{
	int recordNum;
	char toolname[20];
	int quantity;
	double cost;
};
int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
FILE *hfPtr;
int main()
{
	FILE *cfPtr;
	int choice;
	if ((cfPtr = fopen("hardware.dat", "rb+")) == NULL)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		while ((choice = enterChoice()) != 5)
		{
			switch (choice)
			{
			case 1:
				newRecord(cfPtr);
				break;
			case 2:
				updateRecord(cfPtr);
				break;
			case 3:
				deleteRecord(cfPtr);
				break;				
			case 4:
				textFile(cfPtr);
				break;				
			default:
				printf("Incorrect choice\n");
				break;
			}
		}
		fclose(cfPtr);
	}
	system("pause");
	return 0;
}
void textFile(FILE *readPtr)
{
	FILE *writePtr;
	struct hardwareData hardware = { 0, "", 0, 0.0 };
	if ((writePtr = fopen("hardware.txt", "w")) == NULL)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		rewind(readPtr);
		fprintf(writePtr, "%-6s%-16s%-11s%-10s\n", "Record #", "Tool name", "Quantity", "Cost");
		while (!feof(readPtr))
		{
			fread(&hardware, sizeof(struct hardwareData), 1, readPtr);
			if (hardware.recordNum != 0)
			{
				fprintf(writePtr, "%-6d%-16s%-11d%10.2lf\n", hardware.recordNum, hardware.toolname, hardware.quantity, hardware.cost);
			}
		}
		fclose(writePtr);
	}
}
void updateRecord(FILE *fPtr)
{
	int record;
	struct hardwareData hardware = { 0, "", 0, 0.0 };
	printf("Enter record to update (1-100): ");
	scanf("%d", &record);
	fseek(fPtr, (record - 1) * sizeof(struct hardwareData), SEEK_SET);
	fread(&record, sizeof(struct hardwareData), 1, fPtr);
	if (hardware.recordNum == 0)
	{
		printf("Record #%d has no information.\n", record);
	}
	else
	{
		printf("Enter new tool name, quantity,cost \n?");
		scanf("%s%d%lf", hardware.toolname, &hardware.quantity, &hardware.cost);
		fseek(fPtr, (record - 1) * sizeof(struct hardwareData), SEEK_SET);
		fwrite(&hardware, sizeof(struct hardwareData), 1, fPtr);
	}
}
void deleteRecord(FILE *fPtr)
{
	struct hardwareData hardware;
	struct hardwareData blankRecord = { 0, "", 0,0.0 };
	int recordNum;
	printf("Enter record number to delete (1-100): ");
	scanf("%d", &recordNum);
	fseek(fPtr, (recordNum - 1) * sizeof(struct hardwareData), SEEK_SET);
	fread(&hardware, sizeof(struct hardwareData), 1, fPtr);
	if (hardware.recordNum == 0)
	{
		printf("Record %d does not exist.\n", recordNum);
	}
	else
	{
		fseek(fPtr, (recordNum - 1) * sizeof(struct hardwareData), SEEK_SET);
		fwrite(&blankRecord, sizeof(struct hardwareData), 1, fPtr);
	}
}
void newRecord(FILE *fPtr)
{
	struct hardwareData hardware = { 0, "", 0, 0.0 };
	int piece;
	printf("Enter record number to create (1-100) : ");
	scanf("%d", &piece);
	fseek(fPtr, (piece - 1) * sizeof(struct hardwareData), SEEK_SET);
	fread(&hardware, sizeof(struct hardwareData), 1, hfPtr);
	if (hardware.recordNum != 0)
	{
		printf("Record already exists.\n", hardware.recordNum);
	}
	else
	{
		printf("Enter tool name, quantity, cost\n?");
		scanf("%s%d%.2lf", hardware.toolname, &hardware.quantity, &hardware.cost);
		hardware.recordNum = piece;
		fseek(fPtr, (hardware.recordNum - 1) * sizeof(struct hardwareData), SEEK_SET);
		fwrite(&hardware, sizeof(struct hardwareData), 1, hfPtr);
	}
}
int enterChoice(void)
{
	int menuChoice;
	printf("\nEnter your choice\n"
		"1 - List of all tools\n"
		"2 - Update an existing tool\n"
		"3 - Add a new tool\n"
		"4 - Delete a tool\n"
		"5 - End program\n? ");
	scanf("%d", &menuChoice);
	return menuChoice;
}