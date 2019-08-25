import java.util.Scanner;
import java.lang.Math;

//https://open.kattis.com/problems/3dprinter

public class statue
{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    double x = Math.ceil(Math.log10(k)/Math.log10(2));
    System.out.println((int)(x)+1);
    sc.close();
  }
}
