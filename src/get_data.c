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