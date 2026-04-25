#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define BKCONT 100

typedef struct book
{
    char name[30];
    char writer[30];
    char number[30];
    int hot;
    int sc;
    float price;
}BK;

void show(void);
void key_scan(void);
void intput(char *str);
void password(void);
void ch_passwd(void);
void add_book(void);
void search_book(void);
void search_all_book(void);
void search_name_book(void);
void search_writer_book(void);
void hot_book(void);
void return_book(void);

char *pass_sys="123456";
BK bks[BKCONT];


int main(void)
{
    
    //密码登录
    password();
    

    while(1)
    {
        //界面函数
        show();
        //按键扫描识别功能函数
        key_scan();
        getch();
        
    }
    
    return 0;
}

void show(void)
{
    system("cls");
    printf("========================================\n");
    printf("|     Library Management System v1.0   |\n");
    printf("========================================\n");
    printf("|  [1] Search Book    [2] Return Book  |\n");
    printf("|  [3] Top Ranking    [4] Add New Book |\n");
    printf("|  [5] Edit Password  [0] Exit System  |\n");
    printf("========================================\n");
    printf("Please enter your choice: ");
}

void key_scan(void)
{
    char key;
STAR:
    key = getch();
    system("cls");
    switch (key)
    {
        case '1': search_book(); break;
        case '2': return_book(); break;
        case '3': hot_book(); break;
        case '4':add_book(); break;
        case '5':ch_passwd(); break;
        case '0': exit(1); break;
        default: 
            printf("Invalid command! Please try again.\n"); 
            goto STAR; 
            break;
    }
}
/*******************************************************
*函数名    ： intput
*函数功能  ： 用户输入的字符进入到数组中, 并且以*显示
*函数参数  ： char *str
*函数返回值： 无
*函数描述  ：
********************************************************/
void intput(char *str)
{   int i =0;
    while(1)
    {   
        //通过输入字符到数组中
        *(str+i)=getch();
        //判断不是回车和退格字符才显示*
        if (*(str+i)!=8 && *(str+i)!='\r')
        {
            printf("*");
        }
        
        //如果是回车字符就结束输入
        if (*(str+i)=='\r')
        {
            *(str+i)='\0';
            break;
        }
        //如果是退格界面和数组删除处理
        if(*(str+i)==8){
            //界面层面
            if(i>0){
                printf("\b");
                printf(" ");
                printf("\b");

            }
            

            //数组层面
            i-=2;//下标i 回退2
            if (i<=-2){
                i=-1;
            }
        }
        i++;

    }

}

/*******************************************************
*函数名    ： password
*函数功能  ： 密码登录函数
*函数参数  ： 无
*函数返回值： 无
*函数描述  ：
********************************************************/
void password(void)
{
    char pass_user[10]={0};
    printf("please input password:");
PASS:
    //用户输入字符存储数组 并且以*显示
    intput(pass_user);
    /*密码对比*/
    if(strcmp(pass_sys,pass_user)!=0){
        system("cls");
        printf("wrong password, please try again:");
        goto PASS;

    }

}
/*******************************************************
*函数名    ： ch_passwd
*函数功能  ： 修改密码
*函数参数  ： 无
*函数返回值： 无
*函数描述  ：
********************************************************/
void ch_passwd(void){
    static char pass1[10]={0};
    char pass2[10]={0};
    /*log in orginal password*/
    password();
    system("cls");
PP:
    /*change password*/
    printf("please input new password for first time:");
    intput(pass1);

    printf("\n");
    printf("please input new password for second time:");
    intput(pass2);

    /*compare the two passwords*/
    if(strcmp(pass1,pass2)==0){
        //give new password to system
        //原密码指针变量重新指向新密码
        pass_sys=pass1;
        system("cls");
    }else{
        system("cls");
        printf("the two password are different!\n");
        goto PP;
    }
    printf("password was changed successfully, please login again ");
    /*login again*/
    password();
}
/*******************************************************
*函数名    ： add_book
*函数功能  ： 添加新书函数
*函数参数  ： 无
*函数返回值： 无
*函数描述  ： 进入此函数可以添加新书到数组中
********************************************************/
void add_book(void)
{
    static int i = 0;

    while(i < BKCONT)
    {
        printf("please add number %d book\n", i + 1);

        //用户手动输入变量成员信息
        printf("Please enter book name: ");
        scanf("%s", bks[i].name);
    
        printf("Please enter author: ");
        scanf("%s", bks[i].writer);
        
        printf("Please enter serial number: ");
        scanf("%s", bks[i].number);
        
        printf("Please enter popularity: ");
        scanf("%d", &bks[i].hot);
        
        printf("Please enter stock quantity: ");
        scanf("%d", &bks[i].sc);
        
        printf("Please enter price: ");
        scanf("%f", &bks[i].price);
        i++;
        //询问是否继续
        printf("Do you want to continue? Press [y] to continue, any other key to exit.\n");
        if(getch() != 'y')
        {
            break;
        }
    }
}

/*******************************************************
*函数名    ： search_book
*函数功能  ： 检索图书
*函数参数  ： 无
*函数返回值： 无
*函数描述  ： 三种方式查找图书
********************************************************/
void search_book(void)
{
    char k;

STAR:
    system("cls");
    /* Interface Prompts */
    printf("--------------------------------------------------\n");
    printf("|                Search Methods                  |\n");
    printf("--------------------------------------------------\n");
    printf("|           [1] Search All Books                 |\n");
    printf("|           [2] Search by Book Name              |\n");
    printf("|           [3] Search by Author                 |\n");
    printf("|           [0] Return to Main Menu              |\n");
    printf("--------------------------------------------------\n");
    printf("Please enter your choice: ");
    k = getch(); // <--- 关键修正：获取用户输入的按键赋给 k
    printf("%c\n", k); // 可选：把按下的键显示出来，方便确认
    /*判断选择方式执行相应搜索*/
    if(k == '1'){
        // Search All
        search_all_book();
    } else if (k == '2'){
        // Search by Book Name
        search_name_book();
    } else if (k == '3'){
        // Search by Author
        search_writer_book();
    } else if (k == '0'){
        // Return to main menu
        return;
    }
}

/*******************************************************
*函数名    ： search_all_book
*函数功能  ： 检索全部图书
*函数参数  ： 无
*函数返回值： 无
*函数描述  ： 显示所有图书信息
********************************************************/
void search_all_book(void)
{
    int i = 0;
    printf("The list of all books found is as follows:\n");
    
    // 遍历数组，直到遇到空书名为止
    while(bks[i].name[0] != '\0')
    {
        printf("Name: %s\nAuthor: %s\nSerial Number: %s\nPopularity: %d\nStock: %d\nPrice: %.2f\n", 
                bks[i].name, bks[i].writer, bks[i].number, bks[i].hot, bks[i].sc, bks[i].price);
        printf("----------------------\n");
        i++;
    }
    
    printf("Press any key to return to the search menu...\n");
    getch();
}   

/*******************************************************
*函数名    ： search_name_book
*函数功能  ： 按书名检索图书
*函数参数  ： 无
*函数返回值： 无
*函数描述  ： 
********************************************************/
void search_name_book(void){
    char k;
    int i = 0;
    char user_name[30]={0};
    char user_number[30]={0};
    int b_cont=0;
    int book_flag;

    /*提示用户输入书名*/
    printf("please input the name of book:");
    scanf("%s",user_name);

    /*查找有效书里符合条件的书打印记录本书*/
    while(bks[i].name[0]!='\0'){
        if(strcmp(user_name,bks[i].name)==0){
            book_flag =i;
            b_cont++;
            printf("Name: %s\nAuthor: %s\nSerial Number: %s\nPopularity: %d\nStock: %d\nPrice: %.2f\n", 
                bks[i].name, bks[i].writer, bks[i].number, bks[i].hot, bks[i].sc, bks[i].price);

        }
        i++;
}
        
        if(b_cont==0){
            printf("No matching books found. Press [any key] to return to Main Menu\n");
            getch();
        }
        //有一本书
        else if(b_cont == 1){
        printf("Press [j] to borrow, [any other key] to return to Main Menu\n");
        k = getch();
        if(k == 'j'){
            if(bks[book_flag].sc>0)
            {
                bks[book_flag].hot++;
                bks[book_flag].sc--;
                printf("borrow successfully, Press [any key] to return to Main Menu\n ");
            }
            else{
                printf("we are out of this book, please try other books,Press [any key] to return to Main Menu\n ");
            }
            getch();

        }
        }
        else if(b_cont>1){
            printf("Press [j] to borrow, [any other key] to return to Main Menu\n");
            k=getch();
            if(k=='j')
            {
    STAR_B:
                printf("please input the user_number of book");
                scanf("%s",user_number);
                //根据用户输入的编号确认下标
                i= 0;
                while(bks[i].name[0]!='\0'){
                    if(strcmp(user_number,bks[i].number)==0){
                        break;
                    }
                    i++;
                }
                //i就是要查找的下标
                if(strcmp(bks[i].name,user_name)==0){
                    if(bks[i].sc>0){
                        bks[i].sc--;
                        bks[i].hot++;
                        printf("borrow successfully, Press [any key] to return to Main Menu\n ");
                    }
                    else{
                        printf("we are out of this book, please try other books,Press [any key] to return to Main Menu\n ");
                    }
                    getch();
                }
                else{
                    printf("Incorrect ID input. Press [y] to continue, or [any key] to exit\n");
                    k = getch();
                    if (k == 'y')
                    {
                        goto STAR_B;
                    }
                }
            }
        }
    }

/*******************************************************
*函数名    ： search_writer_book
*函数功能  ： 按作者检索图书
*函数参数  ： 无
*函数返回值： 无
*函数描述  ： 
********************************************************/
void search_writer_book(void) {
    char k;
    int i = 0;
    char user_writer[30] = {0}; // 存储用户输入的作者名
    char user_number[30] = {0};
    int b_cont = 0;
    int book_flag;

    /* 1. 提示用户输入作者名 */
    printf("please input the author name: ");
    scanf("%s", user_writer);

    /* 2. 查找匹配该作者的所有书籍并打印 */
    i = 0;
    while (bks[i].name[0] != '\0') {
        // 关键改动：对比 writer 字段
        if (strcmp(user_writer, bks[i].writer) == 0) {
            book_flag = i; // 记录下标（如果是单本的情况）
            b_cont++;
            printf("Name: %s\nAuthor: %s\nSerial Number: %s\nPopularity: %d\nStock: %d\nPrice: %.2f\n", 
                    bks[i].name, bks[i].writer, bks[i].number, bks[i].hot, bks[i].sc, bks[i].price);
            printf("----------------------\n");
        }
        i++;
    }

    /* 3. 根据搜索结果数量进行处理 */
    if (b_cont == 0) {
        printf("No books found for this author. Press [any key] to return to Main Menu\n");
        getch();
    } 
    // 只有一本书的情况
    else if (b_cont == 1) {
        printf("Press [j] to borrow, [any other key] to return to Main Menu\n");
        k = getch();
        if (k == 'j') {
            if (bks[book_flag].sc > 0) {
                bks[book_flag].hot++;
                bks[book_flag].sc--;
                printf("borrow successfully! Press [any key] to return to Main Menu\n");
            } else {
                printf("Out of stock! Press [any key] to return to Main Menu\n");
            }
            getch();
        }
    } 
    // 该作者有多本书的情况
    else if (b_cont > 1) {
        printf("This author has multiple books. Press [j] to borrow, [any other key] to return to Main Menu\n");
        k = getch();
        if (k == 'j') {
        STAR_B:
            printf("please input the serial number of the book you want: ");
            scanf("%s", user_number);
            
            // 根据编号确认具体是哪一本
            i = 0;
            int found = 0;
            while (bks[i].name[0] != '\0') {
                if (strcmp(user_number, bks[i].number) == 0 && strcmp(user_writer, bks[i].writer) == 0) {
                    found = 1;
                    break;
                }
                i++;
            }

            if (found) {
                if (bks[i].sc > 0) {
                    bks[i].sc--;
                    bks[i].hot++;
                    printf("borrow successfully! Press [any key] to return to Main Menu\n");
                } else {
                    printf("Out of stock! Press [any key] to return to Main Menu\n");
                }
                getch();
            } else {
                printf("Incorrect serial number. Press [y] to try again, or [any key] to exit\n");
                k = getch();
                if (k == 'y') {
                    goto STAR_B;
                }
            }
        }
    }
}

/*******************************************************
*函数名    ： hot_book
*函数功能  ： 热度排序
*函数参数  ： 无
*函数返回值： 无
*函数描述  ： 
********************************************************/
void hot_book(void){
    int i=0;
    int j=0;
    int n=0;
    BK temp;
    /*检测有效书的本数*/
    while(bks[i].name[0]!='\0'){
        n++;
        i++;
    }
    /*排序*/
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            //从大到小
            if(bks[j].hot <bks[j+1].hot){
                temp=bks[j];
                bks[j]=bks[j+1];
                bks[j+1]=temp;
            }
        }
    }

    /*打印排列后的数组*/
    i=0;
    while(bks[i].name[0]!='\0'){
        printf("Name: %s\nAuthor: %s\nSerial Number: %s\nPopularity: %d\nStock: %d\nPrice: %.2f\n", 
                    bks[i].name, bks[i].writer, bks[i].number, bks[i].hot, bks[i].sc, bks[i].price);
        printf("\n");
        i++;

    }
    printf("Press [any key] to return to Main Menu\n"); 
    getch(); 

}

/*******************************************************
*函数名    ： return_book
*函数功能  ： 还书函数
*函数参数  ： 无
*函数返回值： 无
*函数描述  ： 根据图书编号归还图书，库存加1
********************************************************/
void return_book(void)
{
    char user_number[30] = {0};
    int i = 0;
    int found = 0;

    printf("Please enter the serial number of the book to return: ");
    scanf("%s", user_number);

    // 遍历数组查找匹配编号的图书
    while(bks[i].name[0] != '\0')
    {
        if(strcmp(user_number, bks[i].number) == 0)
        {
            // 找到图书
            bks[i].sc++; // 库存加1
            found = 1;
            
            // 打印确认信息
            printf("Please confirm: You have returned the book with serial number: %s\n", bks[i].number);
            printf("Book Name: %s\nCurrent Stock: %d\n", bks[i].name, bks[i].sc);
            break;
        }
        i++;
    }

    if(!found)
    {
        printf("Error: Book with serial number %s not found!\n", user_number);
    }

    printf("\nPress any key to return to Main Menu...");
    getch();
}
