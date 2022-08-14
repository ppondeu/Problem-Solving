#include <stdio.h>
#include <string.h>
#include <math.h>

int convert(char cv[])
{
    int sum = 0;
    int k;
    for (int i = 0; i < strlen(cv); i++)
    {
        k = cv[i] - '0';
        sum += (k * pow(2, strlen(cv) - i - 1));
    }
    return sum;
}
int main()
{
    char input[1000];
    scanf(" %[^\n]*c", input);
    // printf("%s",input);

    int len_input = strlen(input);
    // printf("%d",len_input);
    char bin_8[9];
    strcpy(bin_8, "");
    char bin_rev_8[9];
    strcpy(bin_rev_8, "");
    char str[1000];
    strcpy(str, "");
    for (int i = 0; i < len_input; i++)
    {
        int dec = (int)input[i];
        // printf("%d ",dec);

        while (dec > 0)
        {
            char cv_inttobin = dec % 2 + '0';
            // printf("%c ",cv_inttobin);

            strncat(bin_8, &cv_inttobin, 1);
            dec /= 2;
        }
        int len_temp = strlen(bin_8);
        // printf("%d\n",len_temp);
        for (int j = 0; j < 8 - len_temp; j++)
        {
            char concat_zero = '0';
            strncat(bin_8, &concat_zero, 1);
        }
        bin_8[8] = '\0';

        // printf("%s",bin_8);
        int z = 0;
        for (int k = 7; k >= 0; k--)
        {
            bin_rev_8[z++] = bin_8[k];
        }
        bin_rev_8[8] = '\0';

        strcat(str, bin_rev_8);

        strcpy(bin_8, "");
        // printf("\n");
    }

    // printf("%s",str);
    int all_digit;
    if ((len_input * 8) % 6 == 0)
    {
        all_digit = (len_input * 8) / 6;
    }
    else
    {
        all_digit = (len_input * 8) / 6 + 1;
    }

    char bin_6[all_digit + 1][7];
    int m = 0;
    int len_str = strlen(str);

    // printf("%d",len_str);
    strcpy(bin_6[m], "");
    int beg = ((len_input * 8) / 6) * 6;
    // char pushback[5];
    int cnt_equal = 0;
    // strcpy(pushback,"");
    for (int i = 0; i < len_str; i++)
    {
        if (i >= beg && i == len_str - 1)
        {
            char concat_monobin = str[i];
            // printf("%c ",concat_monobin);
            strncat(bin_6[m], &concat_monobin, 1);
            cnt_equal = 6 - (len_str - beg);
            for (int y = 1; y <= cnt_equal; y++)
            {
                char concat_zero = '0';
                strncat(bin_6[m], &concat_zero, 1);
            }
            // bin_6[m][6] = '\0';
            //  printf("%d\n",m);
            //   printf("%s\n",bin_6[m]);
        }
        if (i % 6 == 5 && i != 0)
        {

            // printf("%d\n",i);
            //  bin_6[m][6]='\0';

            char concat_monobin = str[i];
            strncat(bin_6[m], &concat_monobin, 1);
            // printf("%s\n",bin_6[m]);
            ++m;
            strcpy(bin_6[m], "");
            continue;
        }
        if (i != len_str - 1)
        {
            char concat_monobin = str[i];
            // printf("%c ",concat_monobin);
            strncat(bin_6[m], &concat_monobin, 1);
            // printf("%s ",bin_6[m]);
        }
    }

    // printf("%d",cnt_equal);
    int table_base64[64];
    for (int i = 0; i < 64; i++)
    {
        if (i >= 0 && i <= 25)
        {
            table_base64[i] = i + 65;
        }
        else if (i > 25 && i < 52)
        {
            table_base64[i] = i + 71;
        }
        else if (i >= 52 && i < 62)
        {
            table_base64[i] = i - 4;
        }
        else if (i == 62)
        {
            table_base64[i] = 43;
        }
        else if (i == 63)
        {
            table_base64[i] = 47;
        }
    }

    // printf("%d",all_digit);
    for (int i = 0; i < all_digit; i++)
    {
        //printf("%s ", bin_6[i]);
        int ans = convert(bin_6[i]);
        char cv_asciitochar = (char) table_base64[ans];
        printf("%c",cv_asciitochar);
        //printf("%d\n", ans);
    }

    for(int i=1;i<=cnt_equal/2;i++){
        printf("=");
    }
    // printf("\n\n%s",bin_6[6]);
    return 0;
}
