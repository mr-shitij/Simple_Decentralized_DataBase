#include<stdio.h>
#include<stdlib.h>
#include"../lib/SLL.h"
#include"../lib/TABLE.h"
#include<stdarg.h>
#include<string.h>

//

int main() {
	printf("p1\n\n");
	Table *table = open("abc.txt");//tableInit("sii", "Name", "Age", "Phone_No");
	printf("p2\n\n");

	if(table->tableRow == NULL)
		printf("Table_ROWS : \n\n");
	if(table->tableRow->row == NULL)
		printf("Table_ROWS->row : \n\n");

	printColums(table);

//	insertRow(table, "sii", "RAM2", 199, 1234567890);
//	insertRow(table, "sii", "SHAM2", 199, 987654321);

	printf("p3\n\n");
	showRow(table, 0);
	printf("p4\n\n");
	showRow(table, 1);
	printf("p5\n\n");

	showRow(table, 2);
	printf("p6\n\n");
//	showRow(table, 3);
//	printf("p7\n\n");

//	save(table, "abc.txt");
/*

	showColum(table, 0);
	showColum(table, 1);

	printf("\n\n p4");
	
	Node *n1 = getNode(table, 0, 2);
	printf("\n N1 : ");
	printBasedOnData(n1->type, n1->data);

	n1 = getNode(table, 1, 1);
	printf("\t N1 : ");
	printBasedOnData(n1->type, n1->data);

	Node *n2 = getNode(table, 0, 0);
	printf("\n N2 : ");
	printBasedOnData(n2->type, n2->data);

	n2 = getNode(table, 0, 1);
	printf("\t N2 : ");
	printBasedOnData(n2->type, n2->data);

//	getNode(table, 0, 0);
//	getNode(table, 1, 0);
*/
	return 0;
}

