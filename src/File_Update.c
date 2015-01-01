#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct emp_rec
{
	int id;
	char name[4];
	char place[10];
} EMP;

void file_write( EMP emp_rec[], int size, FILE *fp, int argc, const char** argv);

/*
void file_write( EMP emp_rec[], int size, FILE *fp, int argc, const char** argv)
{
	int i;
	int j=1;
	
	if (argc < 2)
    {
    	for (i=0; i<size; i++)
    	{
    		scanf("%d", &emp_rec[i].id);
    		scanf("%s", emp_rec[i].name);
    		scanf("%s", emp_rec[i].place);
    		fprintf(fp, "%d %s %s\n", emp_rec[i].id, emp_rec[i].name, emp_rec[i].place);
    	}
    }
    else
    {
    	while (argv[j] != NULL && i < size)
		{
	
			emp_rec[i].id = atoi(argv[j]);
			j++;
			strcpy(emp_rec[i].name, argv[j]);
			j++;
			strcpy(emp_rec[i].place, argv[j]);
			j++;
		
//			printf("Emp id is %d\n", emp_rec[i].id);
			fprintf(fp, "%d %s %s\n", emp_rec[i].id, emp_rec[i].name, emp_rec[i].place);
			i++;
		}
    }
    
    printf("Records are \n");
    for (i=0; i<size; i++)
    {
    	printf("%d %s %s\n", emp_rec[i].id, emp_rec[i].name, emp_rec[i].place);
    }
    
}

*/
void print_file_content (FILE *fp)
{
	char ptr[100];
	
	fseek(fp, 0, 0);
	fgets( ptr, 100, fp);
	
	printf("File Contents are:\n");
	
	while (!feof(fp))
	{
		printf("%s", ptr);
		fgets( ptr, 100, fp);
	}	
}

void file_UpdateMain(EMP emp_rec[], int size, FILE *fp)
{
	int i=0;
	int j=0;
	int rec_pos[10];
	int rec_count =1;
	
	for (i=0; i<10; i++)
		rec_pos[i] = -1;
		
	fseek(fp, 0, 0);
	
	for (i=0; i<size; i++)
    {
    	    if (strcmp(emp_rec[i].place, "BANGALORE") == 0)
    	    {
    	    		rec_pos[j] = i;
    	    		j++;
    	    }
    		
    }
	
	printf("Val of j is:%d\n", j);
	fseek(fp, 0, 0);
	
	i=0;
	while(rec_pos[i] != -1)
	{
		fseek(fp, rec_pos[i]*18+8,0);
		fprintf(fp, "BENGALURU\n");
		i++;
	}
	
}




#ifndef __CXX_TEST_MAIN__

int main(int argc, const char** argv){
	
	FILE *fp;
	EMP emp_rec[10];
	
	char ptr[100];
	int size = 5;
	
	memset(emp_rec, 0, sizeof(EMP)*10);
	
	fp = fopen("my_test", "w+");
	if (fp == NULL)
    {
    	printf("Error\n");
    	return(0);
    }
    
    
	file_write (emp_rec,size, fp, argc, argv);

	print_file_content (fp);
	
    file_UpdateMain(emp_rec,size, fp );
    
    print_file_content (fp);
    
   
    return 0;
}

#endif