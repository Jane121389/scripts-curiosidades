import java.io.*;
import java.util.Scanner;
class Mcd
{
    public static void main(String [] args)
    {
        Scanner  sc = new Scanner(System.in);
        int      p=2, i=0, j=0, cont=0, num=0, num2=0, k=0, j2=0, num_aux=0;
        int [][] pri=new int[2][10];
        int      mcd=1;
        double   ra =0;
        for (k=0; k < 2; k++)
        {
            j2     =j;
            j      =0;
            num_aux=num;
            System.out.print("\nNúmero " + k + ": ");
            num = sc.nextInt();
            num2=num;
            ra  =Math.sqrt(num);
            for (p=2; p < num; p++)
            {
                cont=0;
                while (num2 % p == 0)
                {
                    num2     =num2 / p;
                    pri[k][j]=p;
                    j++;
                    if (num2 == 1)
                        p=num + 1;
                }
            }
            System.out.print(num + "=");
            if (j == 0)
            {
                pri[k][j++]=1;
                pri[k][j++]=num;
            }
            for (i=0; i < j; i++)
            {
                System.out.print(pri[k][i]);
                if (i < j - 1)
                    System.out.print("x");
            }
        }
        k=0;
        i=0;
        while (i < j2)
        {
            if (pri[0][i] == pri[1][k])
            {
                mcd      =mcd * pri[1][k];
                pri[1][k]=0;
                k++;
                i++;
            }
            else
                i++;
            if (i == j2 && k < j)
            {
                k++;
                i=0;
            }
        }
        System.out.print("\nMaximo común divisor:" + mcd);
        System.out.print("\nMinimo común multiplo:" + ((num * num_aux) / mcd));
    }
}