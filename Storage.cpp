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
        cout << "�޼�¼�洢��";
        return;
    }
    strcpy(fname,"data");
    if((fp=fopen(fname,"wb"))==NULL)
    {
        cout << "�����ļ�ʧ�ܣ�" << endl;
        return;
    }

    cout << endl << "�����ļ���..." << endl;
    fwrite(books,sizeof(book)*numBook,1,fp);
    fclose(fp);
    cout << numBook << "����¼�Ѵ����ļ���" << endl;
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
		// ���ڵ�����ռ䲻�㣬��Ҫ��������ռ�
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
		//��ȡһ���¼�¼,���浽records[numStus],

		numBook++;//��¼����1

	}

	fclose(fp);



}
