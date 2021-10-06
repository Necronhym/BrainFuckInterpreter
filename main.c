#include <stdio.h>
#include <stdlib.h>
struct Node
	{
		int value;
		struct Node* prev;
		struct Node* next;
	};
void addNode(struct Node **N, int i)
	{
		struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
		NewNode->value = i;
		NewNode->prev = *N;
		NewNode->next = NULL;
		if(*N != NULL)
			{
				(*N)->next = NewNode;
			}
		*N = NewNode;
	}
void pushNode(struct Node **N, int i)
	{
		struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
		NewNode->value = i;
		NewNode->prev = NULL;
		NewNode->next = *N;
		if(*N != NULL)
			{
				(*N)->prev = NewNode;
			}
		*N = NewNode;
	}
void nextNode(struct Node** N)
	{
		*N = (*N)->next;
	}
void prevNode(struct Node** N)
	{
		*N = (*N)->prev;
	}
void inc(struct Node** N)
	{
		(*N)->value++;
	}
void dec(struct Node** N)
	{
		(*N)->value--;
	}
int main(int argc, char* argv[])
	{
		if(argv[1] == NULL)
			{
				return 0;
			}
		FILE *f = fopen(argv[1], "r");
		struct Node* list = NULL;
		addNode(&list, 0);
		char c;
		while((c=fgetc(f)) != EOF)
			{
				switch(c)
					{
						case('>'):
							if(list->next == NULL)
								addNode(&list, 0);
							else
								nextNode(&list);
						break;
						case('<'):
							if(list->prev == NULL)
								pushNode(&list, 0);
							else
								prevNode(&list);
						break;
						case('+'):
							inc(&list);
						break;
						case('-'):
							dec(&list);
						break;
						case('.'):
							printf("%c", (list)->value);
						break;
						case(','):
							scanf(" %c", &(list->value));
						break;
						case('['):
							if(list->value == 0)
								{
									int d=1;
									while(d)
										{
											c=fgetc(f);
											if(c == '[')
												{
													d++;
												}
											if(c == ']')
												{
													d--;
												}	
										}
								}
						break;
						case(']'):
							if(list->value != 0)
								{
									int d=1;
									while(d)
										{
											fseek(f, -2, SEEK_CUR);
											c=fgetc(f);
											if(c == ']')
												{
													d++;
												}
											if(c == '[')
												{
													d--;
												}	
										}
								}	
						break;
						default:
						break;
					}
			}	
	}
