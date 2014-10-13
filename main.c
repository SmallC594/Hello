#include <stdio.h>
#include <stdlib.h>
int store_bit_field(int original_value,int value_to_store,unsigned int starting_bit,unsigned int ending_bit );
void show_bits(int num);
int main()
{
    int original_value,value_to_store;unsigned int starting_bit, ending_bit;
  //int test = 128;

    printf("Hello world!\n");
    puts("Please input the original_value:");
    scanf("%X",&original_value);

    puts("Please input the value_to_store:");
    scanf("%X",&value_to_store);

    puts("Please input the starting_bit:");
    scanf("%d",&starting_bit);

    puts("Please input the ending_bit:");
    scanf("%d",&ending_bit);

    show_bits(store_bit_field(original_value,value_to_store,starting_bit,ending_bit ));

      return 0;
}

int store_bit_field(int original_value,int value_to_store,unsigned int starting_bit,unsigned int ending_bit )
{
    int n_bits = ending_bit-starting_bit+1;
    int mask = 0;
    int i;
    for(i=0;i<n_bits;i++)
        {
            mask<<=1;
            mask|=1;
            }
    value_to_store &=mask;
    original_value = (original_value&(~mask<<starting_bit))|(value_to_store<<starting_bit);
    return original_value;
    }

void show_bits(int num)
{
    static int SIZE = 8*sizeof(int);
    int i;
    printf("%d is:",num);
    char *bit_array = malloc(SIZE*sizeof(char)+1);
    if (bit_array ==NULL)
         return;
    else
    for(i=SIZE-1;i>=0;i--,num>>=1)
        {
            bit_array[i] = num&1? 1+'0':'0';
           // bit_array[i]=(num&1)+'0';
            }

    bit_array[SIZE] = '\0';
    /*
    while(*bit_array!='\0')
       {
            putchar(*bit_array++);
       }  */                                         /*以这种方式来输出，程序运行会出现异常,原因还不清楚*/

    for(i=0;i<SIZE;i++)
     {
         if(i%4==0)
         putchar(' ');
         putchar(bit_array[i]);
     }                                                 /*以这种方式来输出，程序则正常运行*/

    free(bit_array);
    }









