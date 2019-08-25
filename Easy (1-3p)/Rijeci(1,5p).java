import java.util.Scanner;

//https://open.kattis.com/submissions/3488581

public class test
{

  public static void main(String[] args)
  {
    int a = 1;
    int b = 0;
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    for(int i = 0; i < k; i++)
    {

      int temp = b;
      b = a+b;
      a = temp;
    }
    System.out.println(a + " " + b);
  }
}
