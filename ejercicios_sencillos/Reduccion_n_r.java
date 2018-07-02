import java.io.*;
//import java.Math.*;
class Reduccion_n_r
{
    static double cx2=0, cy2=0;
    public static void multiplica_complejo(double er, double ei, double er2, double ei2)
    {
        cx2=(-ei * ei2) + (er * er2);
        cy2=(ei * er2) + (ei2 * er);
    }

    public static void main(String args[])
    {
        double vxr[]={
            1, -0.5, -0.5
        };
        double vxi[]={
            0, Math.sqrt(3) / 2, -Math.sqrt(3) / 2
        };
        double cx=.5, cy=0, cx3=0, cy3=0;
        double rr=0, ri=0;
        double error1, error2=1;
        int    pasar=0, i=0, con=0;
        while (pasar == 0)
        {
            multiplica_complejo(cx, cy, cx, cy);
            multiplica_complejo(cx, cy, cx2, cy2);
            rr=(cx2 - 1) / 3;
            ri=cy2 / 3;
            multiplica_complejo(cx, cy, cx, cy);
            cx3=cx2;
            cy3=cy2;
            multiplica_complejo(rr, ri, -cx3, cy3);
            rr=cx2;
            ri=cy2;
            multiplica_complejo(cx3, cy3, -cx3, cy3);
            rr=rr / cx2;
            ri=ri / cx2;
            cx=rr - cx;
            cy=ri - cy;
            con++;
            if (cx < 0)
                System.out.println("Resutlado=" + cy + "i" + cx);
            else
                System.out.println("Resutlado=" + cy + "i+" + cx);
            for (i=0; i < 3; i++)
            {
                error1=Math.sqrt(Math.pow(cx - vxr[i], 2) + Math.pow(cy - vxi[i], 2));
                System.out.println(" =" + vxr[i] + "=" + vxi[i] + "=" + con);
                if (error1 < 0.1)
                {
                    pasar++;
                    i=3;
                }
            }
        }
    }
}