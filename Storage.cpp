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
        cout << "�޼�¼�洢��";
        return -1;
    }
    strcpy(fname,"books.txt");
    if((fp=fopen(fname,"wb"))==NULL)
    {
        cout << "�����ļ�ʧ�ܣ�" << endl;
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
	    cout << "�޷����ļ���" << endl;
		return -1;
	}

    while(!feof(fp))
	{
		// ���ڵ�����ռ䲻�㣬��Ҫ��������ռ�
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
		//��ȡһ���¼�¼,���浽records[numStus],

		numBook++;//��¼����1

	}


	fclose(fp);
    return 0;

}
