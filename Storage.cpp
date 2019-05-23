#include "used.h"

extern book *books;
extern int numBook;
extern int arraySize;


void save_data()
{
    FILE *fp;
    char fname[30];

    if(numBook == 0)
    {
        cout << "无记录存储！";
        return;
    }
    strcpy(fname,"data");
    if((fp=fopen(fname,"wb"))==NULL)
    {
        cout << "存入文件失败！" << endl;
        return;
    }

    cout << endl << "存入文件中..." << endl;
    fwrite(books,sizeof(book)*numBook,1,fp);
    fclose(fp);
    cout << numBook << "条记录已存入文件。" << endl;
}

void load_data()
{
    FILE *fp;
    char fname[30], str[5];

    strcpy(fname,"data");
    if ((fp=fopen(fname,"rb"))==NULL)
	{
		return;
	}

    while(!feof(fp))
	{
		// 现在的数组空间不足，需要重新申请空间
		if (numBook >= arraySize)
		{
			books = (book*)realloc(books,(arraySize+INCR_SIZE)*sizeof(book));
			if (books == NULL)
			{
				printf("memory failed!");
				exit(-1);
			}
			arraySize = arraySize+INCR_SIZE;
		}

		if(fread(&books[numBook],sizeof(book),1,fp) != 1) break;
		//读取一条新记录,保存到records[numStus],

		numBook++;//记录数加1

	}

	fclose(fp);



}
