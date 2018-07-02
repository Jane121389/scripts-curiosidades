import java.io.*;
import java.util.Scanner;
class Multi_primos
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        int     p=2, i=0, j=0, cont=0, num, num2;
        int []  pri=new int[10];
        double  ra =0;
        System.out.print("número: ");
        num = sc.nextInt();
        num2=num;
        ra  =Math.sqrt(num);
        for (p=2; p < num; p++)
        {
            cont=0;
            for (i=2; i < p; i++)
                if ((p % i) == 0)
                {
                    cont++;
                    i=p;
                }
            if (cont < 1)//el número p es primo


                while (num2 % p == 0)
                {
                    num2  =num2 / p;
                    pri[j]=p;
                    j++;
                    if (num2 == 1)
                    {
                        i=p + 1;
                        p=num + 1;
                    }
                }
        }
        System.out.print(num + "=");
        if (j == 0)
        {
            pri[j++]=1;
            pri[j++]=num;
        }
        for (i=0; i < j; i++)
        {
            System.out.print(pri[i]);
            if (i < j - 1)
                System.out.print("x");
        }
    }
}