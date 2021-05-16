// file manager
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inst_num();
int inst_stri();
long count_char(FILE *f);

int main()
{
    int create_file();
    int rename_file();
    int delete_file();
    int open_file();
    int size();
    int copy();
    int insert();
    int insert_in_nth_posi();
    int marge();
    int word_count();
    int line_space_count();
    int maching();
    int remove_blank_space();
    int insest_and_marge();
    int reverse();
    int replace();
    int v_c_count();
    // Enter your choice
    int choice;
    // for continue
    int conti;
    do
    {
        printf("\n\t\t\t\t\t\t\t                  F I L E  M A N A G E R                      ");
        printf("\n\t\t\t\t\t\t_____________________________________________________________________\n");
        // print choices
        printf("\n\t\t\t\t\t\t\t  1. Create a File.\n\t\t\t\t\t\t\t  2. Rename a file.\n\t\t\t\t\t\t\t  3. Delete a File.\n\t\t\t\t\t\t\t  4. Open a File.\n\t\t\t\t\t\t\t  5. Size of a File.\n\t\t\t\t\t\t\t  6. Copying File.\n\t\t\t\t\t\t\t  7. Insert Elements.\n\t\t\t\t\t\t\t  8. Insert a word in nth Position.\n\t\t\t\t\t\t\t  9. Marge two file.\n\t\t\t\t\t\t\t 10. Word count.\n\t\t\t\t\t\t\t 11. Lines and space count.\n\t\t\t\t\t\t\t 12. Maching Two Files.\n\t\t\t\t\t\t\t 13. Remove Blank Space.\n\t\t\t\t\t\t\t 14. Insert element in two files and marge them in a new file.\n\t\t\t\t\t\t\t 15. Reverse Content in a File.\n\t\t\t\t\t\t\t 16. Replace Vowels with 'Z'.\n\t\t\t\t\t\t\t 17. Vowels and Consonants Count.");
        printf("\n\n\t\t\t\t\t\t\t Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            create_file();
            break;
        case 2:
            rename_file();
            break;
        case 3:
            delete_file();
            break;
        case 4:
            open_file();

            break;
        case 5:
            size();

            break;
        case 6:
            copy();

            break;
        case 7:
            insert();

            break;
        case 8:
            insert_in_nth_posi();

            break;
        case 9:
            marge();

            break;
        case 10:
            word_count();

            break;
        case 11:
            line_space_count();

            break;
        case 12:
            maching();

            break;
        case 13:
            remove_blank_space();

            break;
        case 14:
            insest_and_marge();

            break;
        case 15:
            reverse();

            break;
        case 16:
            replace();

            break;
        case 17:
            v_c_count();

            break;

        default:
            printf("\n\t\t\t\t\t\t\t Error! Invalid Choice..\n");
            break;
        }
        printf("\n\n\t\t\t\t\t\t_____________________________________________________________________\n");
        printf("\n\t\t\t\t\t\t\t Do You want to Continue (Press 1 for Yes or 0 for No): ");
        scanf("%d", &conti);

    } while (conti == 1);

    return 0;
}
int create_file()
{
    char filename[50];
    printf("\n\t\t\t\t\t\t\t Enter Your File Name: ");
    scanf("%s", filename);
    FILE *fptr;
    fptr = fopen(filename, "w");
    if (fptr == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! Unable to create file,try again....");
        return 0;
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t Your file is created Successfully...");
    }
    fclose(fptr);
    return 0;
}
int rename_file()
{
    char filename[50];
    printf("\n\t\t\t\t\t\t\t Enter Your File Name: ");
    scanf("%s", filename);
    FILE *fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! File not found.");
        return 0;
    }
    char re[50];
    printf("\n\t\t\t\t\t\t\t Enter Rename: ");
    scanf("%s", re);
    fclose(fptr);
    rename(filename, re);
    printf("\n\t\t\t\t\t\t\t Your file renamed Successfully....");
    return 0;
}
int delete_file()
{
    char filename[50];
    printf("\n\t\t\t\t\t\t\t Enter Your File Name: ");
    scanf("%s", filename);
    FILE *fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! File not found.");
        return 0;
    }
    fclose(fptr);
    remove(filename);
    printf("\n\t\t\t\t\t\t\t Your file deleted Successfully....");

    return 0;
}

int open_file()
{
    char ch;
    char filename[50];
    FILE *fptr;
    printf("\n\t\t\t\t\t\t\t Enter file name: ");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! File not found\n");
        return 0;
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t Reading Your file content.....\n");
        printf("\n\t\t\t\t\t\t\t Your file content ~~~");
        printf("\n");


        ch = fgetc(fptr);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = fgetc(fptr);
        }

        fclose(fptr);
    }
    return 0;
}

int size()
{
    char file_name[25], ch;
    FILE *fptr;
    printf("\n\t\t\t\t\t\t\t Enter file name: ");
    scanf("%s", file_name);
    fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! File is not found...");
        fclose(fptr);
        return 0;
    }
    long long int count = 0;
    //    count no of char present in a file
    for (ch = getc(fptr); ch != EOF; ch = getc(fptr))
    {

        // Increment count for this character
        count = count + 1;
    }
    printf("\n\t\t\t\t\t\t\t Size of the file is %lld bytes.", count);
    fclose(fptr);
    return 0;
}
int copy()
{
    FILE *source, *coping;
    char s_file[100], c_file[100];
    char ch;
    printf("\n\t\t\t\t\t\t\t Enter source file name: ");
    scanf("%s", s_file);
    printf("\n\t\t\t\t\t\t\t Enter coping file name: ");
    scanf("%s", c_file);
    source = fopen(s_file, "r");
    coping = fopen(c_file, "w");
    if (source == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! Source File is not found...");
        fclose(source);
        return 0;
    }
    if (coping == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Unable to creat.....");
        fclose(source);
        return 0;
    }
    printf("\n\t\t\t\t\t\t\t Coping .....\n");
    ch = fgetc(source);
    while (ch != EOF)
    {
        fputc(ch, coping);
        ch = fgetc(source);
    }
    printf("\n\t\t\t\t\t\t\t File Copied.\n");
    fclose(source);
    fclose(coping);
    return 0;
}

int insert()
{
    int a = 1;
    while (a == 1)
    {
        int choice;
    re:
        printf("\n\t\t\t\t\t\t\t 1> Number. \n\t\t\t\t\t\t\t 2> String \n\t\t\t\t\t\t\t What are you want to insert:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            inst_num();
            break;
        case 2:
            inst_stri();
            break;
        default:
            printf("\n\t\t\t\t\t\t\t Invalid Input..Try again....");
            goto re;
            break;
        }
        printf("\n\t\t\t\t\t\t\t Want to insert more:(Press 1 for YES or 0 for NO): ");
        scanf("%d", &a);
    }
    return 0;
}
int inst_num()
{
    FILE *f1;
    int n1, num;
    char file_name[25];
    printf("\n\t\t\t\t\t\t\t Enter file name: ");
    scanf("%s", file_name);
    f1 = fopen(file_name, "a");
    if (f1 == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! unable to open file %s ...", file_name);
        fclose(f1);
        return 0;
    }
    printf("\n\t\t\t\t\t\t\t Enter how many number you want to insert: ");
    scanf("%d", &n1);
    printf("\n\t\t\t\t\t\t\t Enter all Numbers: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &num);
        fprintf(f1, " %d ", num);
    }

    printf("\n\t\t\t\t\t\t\t Numbers inserted Successfully....\n");
    fclose(f1);
    return 0;
}
int inst_stri()
{
    FILE *f1;
    char file_name[25];
    printf("\n\t\t\t\t\t\t\t Enter file name: ");
    scanf("%s", file_name);
    f1 = fopen(file_name, "a");
    if (f1 == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! unable to open file %s ...", file_name);
        fclose(f1);
        return 0;
    }
    char ch;
    char s[10];
    printf("\n\t\t\t\t\t\t\t Enter Your String(You can insert 10 word at a time): ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", s);
        fprintf(f1, "%s ", s);
    }

    printf("\n\t\t\t\t\t\t\t String insert successfully...");

    fclose(f1);
    return 0;
}
int insert_in_nth_posi()
{
    char file_name[25], ch;
    FILE * fptr, *temp;
    printf("\n\t\t\t\t\t\t\t Enter the file name: ");
    scanf("%s",file_name);
    fptr=fopen(file_name,"r");
    if(fptr==NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! File is not found....");
        fclose(fptr);
        return 0;

    }
    temp=fopen("temp.txt","w");

    int count=0;
    char input[10];
    int pos;
    int flag=0;
    printf("\n\t\t\t\t\t\t\t Enter inserting Position: ");
    scanf("%d",&pos);
    printf("\n\t\t\t\t\t\t\t Enter a word: ");
    scanf("%s",input);
    int len=strlen(input);
    ch=fgetc(fptr);
    while(ch!=EOF)
    {
        if(count==pos)
        {
            flag=1;
            for(int i=0;i<len;i++)
            {
                
                fputc(input[i],temp);

                

            }
        }
        fputc(ch,temp);
        ch=fgetc(fptr);
        
        count++;

    }
    if(flag==1){

    printf("\n\t\t\t\t\t\t\t Successfully inserted in %dth position in the file.....",pos);
    }
    else{
       printf("\n\t\t\t\t\t\t\t Error! can't insert in %dth position in this file!!...",pos); 
    }
    fclose(fptr);
    fclose(temp);
    remove(file_name);
    rename("temp.txt",file_name);
    return 0;
}
int marge()
{
    FILE *f1, *f2, *fm;
    char f1_name[25], f2_name[25], ch;
    printf("\n\t\t\t\t\t\t\t Enter file 1: ");
    scanf("%s", f1_name);
    f1 = fopen(f1_name, "r");
    if (f1 == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! %s is not found...", f1_name);
        fclose(f1);
        return 0;
    }
    printf("\n\t\t\t\t\t\t\t Enter file 2: ");
    scanf("%s", f2_name);
    f2 = fopen(f2_name, "r");
    if (f2 == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! %s is not found...", f2_name);
        fclose(f2);
        return 0;
    }
    fm = fopen("marge.txt", "a");
    ch = fgetc(f1);
    while (ch != EOF)
    {
        fputc(ch, fm);
        ch = fgetc(f1);
    }
    ch = fgetc(f2);
    while (ch != EOF)
    {
        fputc(ch, fm);
        ch = fgetc(f2);
    }
    printf("\n\t\t\t\t\t\t\t Your files are marged and store in marge.txt.");
    fclose(f1);
    fclose(f2);
    fclose(fm);
    return 0;
}
int word_count()
{
    FILE *fptr;
    int count_w = 0;
    char f_name[100], ch;
    printf("\n\t\t\t\t\t\t\t Enter the File Name: ");
    scanf("%s", f_name);
    fptr = fopen(f_name, "r");
    if (fptr == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! File not found...\n");
        return 0;
    }
    while (1)
    {
        ch = fgetc(fptr);
        if (ch == EOF)
        {
            count_w++;
            break;
        }
        if (ch == '\n' || ch == ' ' || ch == '\t')
        {
            count_w++;
        }
    }

    printf("\n\t\t\t\t\t\t\t No. of words: %d", count_w);
    fclose(fptr);
    return 0;
}
int line_space_count()
{
    FILE *fptr;
    int count_s = 0, count_l = 0;
    char f_name[100], ch;
    printf("\n\t\t\t\t\t\t\t Enter the File Name: ");
    scanf("%s", f_name);
    fptr = fopen(f_name, "r");
    if (fptr == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! File not found...\n");
        return 0;
    }
    while (1)
    {
        ch = fgetc(fptr);
        if (ch == EOF)
        {
            count_l++;
            break;
        }
        if (ch == '\n')
        {
            count_l++;
        }
        if (ch == ' ')
        {
            count_s++;
        }
    }
    printf("\n\t\t\t\t\t\t\t No. of Spaces: %d and No. of lines: %d", count_s, count_l);
    fclose(fptr);
    return 0;
}

int maching()
{
    char ch1, ch2;
    FILE *f1, *f2;
    char f1_file[25], f2_file[25];
    int flag = 0;
    printf("\n\t\t\t\t\t\t\t Enter first filename: ");
    scanf("%s", f1_file);
    printf("\n\t\t\t\t\t\t\t Enter second filename: ");
    scanf("%s", f2_file);
    f2 = fopen(f2_file, "r");
    f1 = fopen(f1_file, "r");
    if (f1 == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! %s is not found!", f1_file);
        fclose(f1);
        return 0;
    }
    if (f2 == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! %s is not found!", f2_file);
        fclose(f2);
        return 0;
    }
    printf("\n\t\t\t\t\t\t\t Reading file content....\n");
    while ((fscanf(f1, "%s", f1_file) != EOF) && (fscanf(f2, "%s", f2_file) != EOF))
    {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);
        if (ch1 == ch2)
        {
            continue;
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("\n\t\t\t\t\t\t\t Files are identical...");
    }
    else
    {

        printf("\n\t\t\t\t\t\t\t Files are not identical....");
    }
    fclose(f1);
    fclose(f2);
    return 0;
}

int remove_blank_space()
{
    char file_name[25], ch;
    FILE *fptr;
    printf("\n\t\t\t\t\t\t\t Enter file name: ");
    scanf("%s", file_name);
    fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! File is not found...");
        fclose(fptr);
        return 0;
    }
    FILE *tmp;
    tmp = fopen("temp.txt", "w");
    if (tmp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! Unable to creat a temp File! Try Again...");
        return 0;
    }

me:
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        if (ch != ' ')
        {
            fputc(ch, tmp);
        }

        goto me;
    }

    fclose(fptr);
    fclose(tmp);
    remove(file_name);
    rename("temp.txt", file_name);
    printf("\n\t\t\t\t\t\t\t All blank-spaces are removed...\n");

    return 0;
}
int insest_and_marge()
{
    FILE *f1, *f2, *fm;
    char f1_name[25], f2_name[25], ch;
    printf("\n\t\t\t\t\t\t\t Enter file 1: ");
    scanf("%s", f1_name);
    f1 = fopen(f1_name, "r");
    if (f1 == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! %s is not found...", f1_name);
        fclose(f1);
        return 0;
    }
    printf("\n\t\t\t\t\t\t\t Enter file 2: ");
    scanf("%s", f2_name);
    f2 = fopen(f2_name, "r");
    if (f2 == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! %s is not found...", f2_name);
        fclose(f2);
        return 0;
    }
    fclose(f1);
    fclose(f2);
    int i, n1, n2;
    printf("\n\t\t\t\t\t\t\t Enter number of element you want to insert in file 1: ");
    scanf("%d", &n1);
    printf("\n\t\t\t\t\t\t\t Enter number of element you want to insert in file 2: ");
    scanf("%d", &n2);
    f1 = fopen(f1_name, "a");
    printf("\n\t\t\t\t\t\t\t Enter the %d words for file 1: ", n1);
    char a[n1], b[n2];
    for (i = 0; i < n1; i++)
    {
        scanf("%s", a);
        fprintf(f1, "%s ", a);
    }
    fclose(f1);
    f2 = fopen(f2_name, "a");
    printf("\n\t\t\t\t\t\t\t Enter the %d words for file 2: ", n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%s", b);
        fprintf(f2, "%s ", b);
    }
    fclose(f2);
    f1 = fopen(f1_name, "r");
    f2 = fopen(f2_name, "r");
    fm = fopen("newFile.txt", "w");
    while ((ch = fgetc(f1)) != EOF)
    {
        fputc(ch, fm);
    }
    while ((ch = fgetc(f2)) != EOF)
    {
        fputc(ch, fm);
    }
    printf("\n\t\t\t\t\t\t\t  Wait your files are marging...");
    printf("\n\t\t\t\t\t\t\t Merged!....Files are saved in newFile.txt");
    fclose(f1);
    fclose(f2);
    fclose(fm);
    return 0;
}
int reverse()
{
    FILE *fp, *fptr;
    char file_name[25];
    printf("\n\t\t\t\t\t\t\t Enter the file name: ");
    scanf("%s", file_name);
    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! File Not found....");
        fclose(fp);
        return 0;
    }
    fptr = fopen("reversefile.txt", "w");
    if (fptr == NULL)
    {
        fclose(fptr);
        printf("\n\t\t\t\t\t\t\t Error! Unable to create file...Try Again.");
    }
    char c;
    long tc = count_char(fp);
    fseek(fp, -1L, 2);
    long i = 0;
    while (i < tc)
    {
        c = fgetc(fp);
        fputc(c, fptr);
        fseek(fp, -2L, 1);
        i++;
    }
    fclose(fp);
    fclose(fptr);
    printf("\n\t\t\t\t\t\t\t Reverse of the given file is store in reversefile.txt....\n");
    return 0;
}
long count_char(FILE *f)
{
    fseek(f, -1L, 2);
    long tc = ftell(f);
    tc++;
    return tc;
}
int replace()
{
    FILE *fptr, *temp;
    char f_name[25], ch;
    printf("\n\t\t\t\t\t\t\t Enter the File Name: ");
    scanf("%s", f_name);
    fptr = fopen(f_name, "r");
    if (fptr == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! File not found...\n");
        return 0;
    }

    temp = fopen("temp.txt", "w");
    ch = fgetc(fptr);
    while (ch != EOF)
    {

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            ch = 'z';
        }

        fputc(ch, temp);
        ch = fgetc(fptr);
    }
    fclose(fptr);
    fclose(temp);
    remove(f_name);
    rename("temp.txt", f_name);
    printf("\n\t\t\t\t\t\t\t All vowels are replaced with 'Z' Successfully..");
}
int v_c_count()
{
    int count_v = 0, count_c = 0;
    FILE *fptr;
    char f_name[100], ch;
    printf("\n\t\t\t\t\t\t\t Enter the File Name: ");
    scanf("%s", f_name);
    fptr = fopen(f_name, "r");
    if (fptr == NULL)
    {
        printf("\n\t\t\t\t\t\t\t Error! File not found...\n");
        return 0;
    }

    ch = fgetc(fptr);
    while (ch != EOF)
    {

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            count_v++;
            // ch = fgetc(fptr);
        }
        else
        {
            count_c++;
        }
        if (ch == ' ')
        {
            count_c--;
        }
        ch = fgetc(fptr);
    }
    fclose(fptr);
    printf("\n\t\t\t\t\t\t\t Consonants: %d Vowels: %d", count_c, count_v);
    return 0;
}
