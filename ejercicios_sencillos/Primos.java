import java.io.*;
import java.util.Scanner;
class Primos
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        int     p=0, i=0, cont=0;
        double  ra=0;
        System.out.print("número: ");
        p = sc.nextInt();
        ra=Math.sqrt(p);
        for (i=2; i < ra; i++)
        {
            System.out.println("modulo:" + (p % i));
            if ((p % i) == 0)
            {
                cont++;
                i=p;
            }
        }
        if (cont >= 1)
            System.out.println("El número:" + p + " no es primo");
        else
            System.out.println("El número:" + p + " es primo");
    }
}