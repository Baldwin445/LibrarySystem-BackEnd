#include "used.h"

extern book *books;
extern int numBook;
extern int arraySize;


int save_data()
{
    FILE *fp;
    char fname[30];

    if(numBook == 0)
    {
        cout << "无记录存储！";
        return -1;
    }
    strcpy(fname,"books.txt");
    if((fp=fopen(fname,"wb"))==NULL)
    {
        cout << "存入文件失败！" << endl;
        return -1;
    }

    fwrite(books,sizeof(book)*numBook,1,fp);
    //SetFileAttributes(fname, FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_SYSTEM);
    fclose(fp);
    return 0;
}

int load_data()
{
    FILE *fp;
    char fname[30], str[5];

    strcpy(fname,"books.txt");
    if ((fp=fopen(fname,"ab+"))==NULL)
	{
	    cout << "无法打开文件！" << endl;
		return -1;
	}

    while(!feof(fp))
	{
		// 现在的数组空间不足，需要重新申请空间
		if (numBook >= arraySize)
		{
			books = (book*)realloc(books,(arraySize+INCR_SIZE)*sizeof(book));
			if (books == NULL)
			{
				printf("Memory failed!");
				exit(-1);
			}
			arraySize = arraySize+INCR_SIZE;
		}

		if(fread(&books[numBook],sizeof(book),1,fp) != 1) break;
		//读取一条新记录,保存到records[numStus],

		numBook++;//记录数加1

	}


	fclose(fp);
    return 0;

}
