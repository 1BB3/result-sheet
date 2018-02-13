#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct marks_obtained{
        int cprog,apmech,egdrg,egmath,egphy,bee;
};

struct student{
    int sn;
    char name[13];
    char level[7] = "BE/BCT";
    struct marks_obtained mksobt;
    int total;
    char result[5];
    float percentage;
    char div[7];
    char remark[11];
};

struct student stdt[48];


struct indentaions{                          
    int sn = 12;
    int name = 12;
    int level = 7;
    int cprog = 8;
    int apmech = 8;
    int egmath = 8;
    int egphy = 8;
    int egdrg = 8;
    int bee = 8;
    int total = 8;
    int result = 8;
    int percentage = 8;
    int div = 5;
    int remark = 8;
}indent;

void make_horizontal_line(){
    printf("|");for(int i=0;i<indent.sn;i++)printf("-");
    printf("|");for(int i=0;i<indent.name;i++)printf("-");
    printf("|");for(int i=0;i<indent.level;i++)printf("-");
    printf("|");for(int i=0;i<indent.cprog;i++)printf("-");
    printf("|");for(int i=0;i<indent.apmech;i++)printf("-");
    printf("|");for(int i=0;i<indent.egmath;i++)printf("-");
    printf("|");for(int i=0;i<indent.egphy;i++)printf("-");
    printf("|");for(int i=0;i<indent.egdrg;i++)printf("-");
    printf("|");for(int i=0;i<indent.bee;i++)printf("-");
    printf("|");for(int i=0;i<indent.total;i++)printf("-");
    printf("|");for(int i=0;i<indent.result;i++)printf("-");
    printf("|");for(int i=0;i<indent.percentage;i++)printf("-");
    printf("|");for(int i=0;i<indent.div;i++)printf("-");
    printf("|");for(int i=0;i<indent.remark;i++)printf("-");
    printf("|\n");
}

void make_header(const char *input_string, int space){
    int num = space - strlen(input_string);
    printf("|%s",input_string);for(int i=0;i<num;i++)printf(" ");
}

void make_header_0th_line(){
    int total = indent.sn + indent.name + indent.level + indent.cprog + indent.apmech + indent.egdrg + indent.egmath + indent.egphy + indent.bee + indent.total + indent.result + indent.percentage + indent.div + indent.remark + 13;  
    char mksobt[] =  "Result Sheet";
    int indt = (total - strlen(mksobt));
    int lindt = indt/2;
    int rindt = (indt%2==0)?lindt:lindt + 1;
    printf("\n\n%d %d %d %d\n\n",total,indt,lindt,rindt);
    printf("|");for(int i=0;i<lindt;i++)printf("-");printf("%s",mksobt);for(int i=0;i<rindt;i++)printf("-");
    printf("|\n");
}
void make_header_1st_line(){
    printf("|");for(int i=0;i<indent.sn;i++)printf("-");
    printf("|");for(int i=0;i<indent.name;i++)printf("-");
    printf("|");for(int i=0;i<indent.level;i++)printf("-");

    int total = indent.cprog + indent.apmech + indent.egdrg + indent.egmath + indent.egphy + indent.bee + 5;  
    char mksobt[] =  "Marks Obtained";
    int indt = (total - strlen(mksobt));
    int lindt = indt/2;
    int rindt = (indt%2==0)?lindt:lindt + 1;

    printf("|");for(int i=0;i<lindt;i++)printf("-");printf("%s",mksobt);for(int i=0;i<rindt;i++)printf("-");


    printf("|");for(int i=0;i<indent.total;i++)printf("-");
    printf("|");for(int i=0;i<indent.result;i++)printf("-");
    printf("|");for(int i=0;i<indent.percentage;i++)printf("-");
    printf("|");for(int i=0;i<indent.div;i++)printf("-");
    printf("|");for(int i=0;i<indent.remark;i++)printf("-");
    printf("|\n");
}

void make_empty_line(){
    int total = indent.sn + indent.name + indent.level + indent.cprog + indent.apmech + indent.egdrg + indent.egmath + indent.egphy + indent.bee + indent.total + indent.result + indent.percentage + indent.div + indent.remark + 13;  
    printf("|");for(int i=0;i<total;i++)printf(" ");
    printf("|\n");

}
void make_header_2nd_line(){
    make_header("Symbol No.",indent.sn);
    make_header("Name",indent.name);
    make_header("Level",indent.level);
    make_header("C-Prog",indent.cprog);
    make_header("ApMech",indent.apmech);
    make_header("EnMath",indent.egmath);
    make_header("EnPhy",indent.egphy);
    make_header("EnDrg",indent.egdrg);
    make_header("BEE",indent.bee);
    make_header("Total",indent.total);
    make_header("Result",indent.result);
    make_header("\%",indent.percentage);
    make_header("Div",indent.div);
    make_header("Remark",indent.remark);
    printf("|\n");
}

bool is_input_valid(int field,int idx){
    switch (field)
    {
        case 1:{
            if(stdt[idx].sn < 0 || stdt[idx].sn > 9999){
                printf("\nINVALID ENTRY!\nPlease input in the limits [0,9999]\n");
                return false;
            }
            return true;
        }
        case 2:{
            if(strlen(stdt[idx].name) > indent.name){
                printf("\nINVALID ENTRY!\nCharacters length limit = %d\n",indent.name);
                return false;
            }
            return true;
        }
         case 3:{
            if(strlen(stdt[idx].level) > indent.level){
                printf("\nINVALID ENTRY!\nCharacters length limit = %d\n",indent.level);
                return false;
            }
            return true;
        }
        case 41:{
            if(stdt[idx].mksobt.cprog < 0 || stdt[idx].mksobt.cprog > 100){
                printf("\nINVALID ENTRY!\nPlease input in the limits [0,100]\n");
                return false;
            }
            return true;
        }
        case 42:{
            if(stdt[idx].mksobt.apmech < 0 || stdt[idx].mksobt.apmech > 100){
                printf("\nINVALID ENTRY!\nPlease input in the limits [0,100]\n");
                return false;
            }
            return true;
        }
         case 43:{
            if(stdt[idx].mksobt.egdrg < 0 || stdt[idx].mksobt.egdrg > 100){
                printf("\nINVALID ENTRY!\nPlease input in the limits [0,100]\n");
                return false;
            }
            return true;
        }
         case 44:{
            if(stdt[idx].mksobt.egmath < 0 || stdt[idx].mksobt.egmath > 100){
                printf("\nINVALID ENTRY!\nPlease input in the limits [0,100]\n");
                return false;
            }
                return true;
        }
        case 45:{
            if(stdt[idx].mksobt.egphy < 0 || stdt[idx].mksobt.egphy > 100){
                printf("\nINVALID ENTRY!\nPlease input in the limits [0,100]\n");
                return false;
            }
                return true;
        }
        case 46:{
            if(stdt[idx].mksobt.bee < 0 || stdt[idx].mksobt.bee > 100){
                printf("\nINVALID ENTRY!\nPlease input in the limits [0,100]\n");
                return false;
            }
                return true;
        }default : return false;
    }
}

int input_marks(){
    int number_of_students;
    printf("Enter the number of students : ");
    scanf("%d",&number_of_students);
    system("cls");

    for(int i=0;i<number_of_students;i++){
        printf("Studen No. %d\n\n",i+1);
        do{
        printf("Symbol No. ? ");
        scanf("%d",&stdt[i].sn);
        }while(!is_input_valid(1,i));
        do{
        printf("Name ? ");
        scanf("%s",stdt[i].name);
        }while(!is_input_valid(2,i));
        do{
        printf("Level ? ");
        scanf("%s",stdt[i].level);
        }while(!is_input_valid(3,i));
        
        printf("Marks Obtained in : \n");

        do{
        printf("    Computer Programming ? ");
        scanf("%d",&stdt[i].mksobt.cprog);
        }while(!is_input_valid(41,i));
        do{
        printf("    Applied Mechanics ? ");
        scanf("%d",&stdt[i].mksobt.apmech);
        }while(!is_input_valid(42,i));
        do{
        printf("    Engineering Maths ? ");
        scanf("%d",&stdt[i].mksobt.egmath);
        }while(!is_input_valid(44,i));
        do{
        printf("    Engineering Physics ? ");
        scanf("%d",&stdt[i].mksobt.egphy);
        }while(!is_input_valid(45,i));
        do{
        printf("    Engineering Drawing ? ");
        scanf("%d",&stdt[i].mksobt.egdrg);
        }while(!is_input_valid(43,i));
        do{
        printf("    Basic Electrical Engineering ? ");
        scanf("%d",&stdt[i].mksobt.bee);
        }while(!is_input_valid(46,i));
        
        system("cls");
    }
    printf("\n");
    system("cls");
    return number_of_students;
}

int no_of_digits(int num){
    if(num < 10)return 1;
    if(num < 100)return 2;
    if(num < 1000)return 3;
    if(num < 10000)return 4;

}

int no_of_digits_percentage(float num){
    if(num < 10.00)return 4;
    if(num < 100.00)return 5;
    if(num = 100.00)return 6;
}

void make_content(int nos){
    printf("|%d",stdt[nos].sn);for(int i = 0;i<indent.sn-no_of_digits(stdt[nos].sn);i++)printf(" ");
    printf("|%s",stdt[nos].name);for(int i = 0;i<indent.name-strlen(stdt[nos].name);i++)printf(" ");
    printf("|%s",stdt[nos].level);for(int i = 0;i<indent.level-strlen(stdt[nos].level);i++)printf(" ");
    printf("|%d",stdt[nos].mksobt.cprog);for(int i = 0;i<indent.cprog-no_of_digits(stdt[nos].mksobt.cprog);i++)printf(" ");
    printf("|%d",stdt[nos].mksobt.apmech);for(int i = 0;i<indent.apmech-no_of_digits(stdt[nos].mksobt.apmech);i++)printf(" ");
    printf("|%d",stdt[nos].mksobt.egmath);for(int i = 0;i<indent.egmath-no_of_digits(stdt[nos].mksobt.egmath);i++)printf(" ");
    printf("|%d",stdt[nos].mksobt.egphy);for(int i = 0;i<indent.egphy-no_of_digits(stdt[nos].mksobt.egphy);i++)printf(" ");
    printf("|%d",stdt[nos].mksobt.egdrg);for(int i = 0;i<indent.egdrg-no_of_digits(stdt[nos].mksobt.egdrg);i++)printf(" ");
    printf("|%d",stdt[nos].mksobt.bee);for(int i = 0;i<indent.bee-no_of_digits(stdt[nos].mksobt.bee);i++)printf(" ");
    printf("|%d",stdt[nos].total);for(int i = 0;i<indent.total-no_of_digits(stdt[nos].total);i++)printf(" ");
    printf("|%s",stdt[nos].result);for(int i = 0;i<indent.result-strlen(stdt[nos].result);i++)printf(" ");
    printf("|%.2f",stdt[nos].percentage);for(int i = 0;i<indent.percentage-no_of_digits_percentage(stdt[nos].percentage);i++)printf(" ");   
    printf("|%s",stdt[nos].div);for(int i = 0;i<indent.div-strlen(stdt[nos].div);i++)printf(" ");
    printf("|%s",stdt[nos].result);for(int i = 0;i<indent.result-strlen(stdt[nos].result);i++)printf(" ");
    printf("|\n");
}

void process_data(int nos){
    for(int i = 0;i<nos;i++){
        stdt[i].total = stdt[i].mksobt.cprog + stdt[i].mksobt.apmech + stdt[i].mksobt.egdrg + stdt[i].mksobt.egmath + stdt[i].mksobt.egphy + stdt[i].mksobt.bee;
        stdt[i].percentage = stdt[i].total/6.0;

        if(stdt[i].percentage>74){
            strcpy(stdt[i].div,"Dist.");
            strcpy(stdt[i].result,"PASS");
        }else if(stdt[i].percentage>59){
            strcpy(stdt[i].div,"1st");
            strcpy(stdt[i].result,"PASS");  
        }else if(stdt[i].percentage>49){
            strcpy(stdt[i].div,"2nd");
            strcpy(stdt[i].result,"PASS");   
        }else if(stdt[i].percentage>39){
            strcpy(stdt[i].div,"3rd");
            strcpy(stdt[i].result,"PASS");   
        }else{
            strcpy(stdt[i].div,"4th");
            strcpy(stdt[i].result,"FAIL");  
        }

        if(stdt[i].mksobt.cprog<40 || stdt[i].mksobt.apmech<40 || stdt[i].mksobt.egdrg<40 || stdt[i].mksobt.egmath<40 || stdt[i].mksobt.egphy<40 || stdt[i].mksobt.bee<40){
            strcpy(stdt[i].result,"FAIL");
        }

    }


}



main(){
    printf("\n");
    int number_of_students = input_marks();
    process_data(number_of_students);
    printf("\n\n");
    make_header_0th_line();
    make_empty_line();
    make_header_1st_line();
    make_header_2nd_line();
    make_horizontal_line();
    for(int i = 0;i<number_of_students;i++){
            make_content(i);
    }
    make_horizontal_line();
    printf("\n\n");
}

