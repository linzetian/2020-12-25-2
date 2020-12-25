////利用realloc开辟内存空间
#include<stdio.h>
#include<stdlib.h>//calloc库函数
#include<string.h>//strerror和errno库函数
int main()
{
	int* p = (int*)malloc(5*sizeof(int));//10 * sizeof(int)//换为INT_MAX
	if (p == NULL)
	{
		printf("%s", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
			*(p + i) = i;
	}
	int* prt = (int*)realloc(p, 40);
	//p = prt;
	if (prt != NULL)
	{
		p = prt;
		int i = 0;
		for (i = 5; i < 10; i++)
			*(p + i) = i;
		for (i = 0; i < 10; i++)
			printf("%d ", *(p + i));
	}
	
	free(p);//释放空间
	p = NULL;//因为p还有记忆，所以赋值空指针
	
	return 0;
}