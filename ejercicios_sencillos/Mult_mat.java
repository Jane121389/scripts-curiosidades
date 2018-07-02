import java.io.*;
import java.util.Scanner;
class Mult_mat
{
    static double matriz[][]=new double[3][3];
    static double clave[][] =new double[3][3];
    static String mensaje   ="";
    public static void introduce_clave()
    {
        Scanner sc = new Scanner(System.in);
        int     j=0, i=0;
        System.out.println("Escribe los numeros de la matriz clave ordenadamente:");
        for (i=0; i < 3; i++)
            for (j=0; j < 3; j++)
                clave[i][j] = sc.nextDouble();
    }

    public static void introduce_matr_num()
    {
        Scanner sc = new Scanner(System.in);
        int     j=0, i=0;
        System.out.println("Escribe los numeros de la matriz resultado ordenadamente:");
        for (i=0; i < 3; i++)
            for (j=0; j < 3; j++)
                matriz[i][j] = sc.nextDouble();
    }

    public static void multiplica(double [][] clave, double [][] matriz)
    {
        int    i=0, j=0, k=0;
        double resulta      =0;
        double resultado[][]=new double[3][3];
        for (k=0; k < 3; k++)
            for (i=0; i < 3; i++)
            {
                for (j=0; j < 3; j++)
                    resulta=resulta + (clave[k][j] * matriz[j][i]);
                resultado[k][i]=resulta;
                resulta        =0;
            }
        imprime_matriz(resultado);
    }

    public static void mensaje_t(double [][] resultado)
    {
        int i=0, j=0;
        for (i=0; i < 3; i++)
            for (j=0; j < 3; j++)
            {
                if (resultado[i][j] == 28)
                    mensaje=mensaje + " ";
                else if (resultado[i][j] == 29)
                    mensaje=mensaje + ",";
                else if (resultado[i][j] == 30)
                    mensaje=mensaje + ".";
                else if (resultado[i][j] == 31)
                    mensaje=mensaje + " ";
                else
                    mensaje=mensaje + (char)(resultado[i][j] + 96);
            }
        System.out.println("El mensaje es:" + mensaje);
    }

    public static void invierte_matriz(double [][] matriz)
    {
        double ma_id[][]=new double[3][6];
        double valor=0, valor2=0;
        int    i=0, j=0;
        for (i=0; i < 3; i++)
            for (j=0; j < 6; j++)
            {
                if (j < 3)
                    ma_id[i][j]=matriz[i][j];
                else
                    ma_id[i][j]=0;
            }
        ma_id[0][3]=1;
        ma_id[1][4]=1;
        ma_id[2][5]=1;
        i          =0;
        for (j=0; j < 6; j++)
            ma_id[i][j]=ma_id[i][j] / ma_id[0][0];
        i    =1;
        valor=ma_id[i][0];
        for (j=0; j < 6; j++)
            ma_id[i][j]=(ma_id[0][j] * valor * -1) + ma_id[i][j];
        valor=ma_id[1][1];
        for (j=0; j < 6; j++)
            ma_id[i][j]=ma_id[i][j] / valor;
        i    =2;
        valor=ma_id[i][0];
        for (j=0; j < 6; j++)
            ma_id[i][j]=(ma_id[0][j] * valor * -1) + ma_id[i][j];
        valor=ma_id[i][1];
        for (j=0; j < 6; j++)
            ma_id[i][j]=(ma_id[1][j] * valor * -1) + ma_id[i][j];
        valor=ma_id[2][2];
        for (j=0; j < 6; j++)
            ma_id[i][j]=ma_id[i][j] / valor;
        i    =1;
        valor=ma_id[1][2];
        for (j=0; j < 6; j++)
            ma_id[i][j]=(ma_id[2][j] * valor * -1) + ma_id[i][j];
        i    =0;
        valor=ma_id[0][1];
        for (j=0; j < 6; j++)
            ma_id[i][j]=(ma_id[1][j] * valor * -1) + ma_id[i][j];
        imprime_matriz2(ma_id);
        valor=ma_id[0][2];
        for (j=0; j < 6; j++)
            ma_id[i][j]=(ma_id[2][j] * valor * -1) + ma_id[i][j];
        for (i=0; i < 3; i++)
            for (j=3; j < 6; j++)
                clave[i][j - 3]=ma_id[i][j];

        System.out.println("Matriz inversa:");
        imprime_matriz(clave);
    }

    public static void imprime_matriz(double [][] matriz)
    {
        int j=0, i=0;
        for (i=0; i < 3; i++)
        {
            System.out.println("");
            for (j=0; j < 3; j++)
                System.out.print(matriz[i][j] + " ");
        }
    }

    public static void imprime_matriz2(double [][] matriz)
    {
        int j=0, i=0;
        System.out.println("");
        for (i=0; i < 3; i++)
        {
            System.out.println("");
            for (j=0; j < 6; j++)
                System.out.print(matriz[i][j] + " ");
        }
    }

    public static void main(String [] args)
    {
        introduce_clave();
        invierte_matriz(clave);
        introduce_matr_num();
        multiplica(clave, matriz);
        mensaje_t(clave);
        //System.out.println("Palabra="+palabra);
    }
}
