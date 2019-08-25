import java.util.Scanner;
import java.lang.Math;

//https://open.kattis.com/problems/a1paper

public class statue
{
  static int[] antalPapper;
  static final double multiplier = Math.sqrt(0.5);

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    antalPapper = new int[sc.nextInt()+1];
    antalPapper[1] = 0;
    for(int i = 2; i < antalPapper.length; i++)
    {
        antalPapper[i] = sc.nextInt();
    }
    try{
      double amountOfTape = amountOfTape(1, 1);
      System.out.println(amountOfTape);
    }
    catch (Exception e)
    {
      System.out.println("impossible");
    }
    sc.close();

  }

  private static double amountOfTape(int storlek, int antal)
  {
    if(antal <= 0)
    {
      return 0;
    }
    if(storlek == antalPapper.length)
    {
      throw new IllegalArgumentException();
    }
    return Math.pow(multiplier,storlek-1)*Math.pow(2,-0.75)*antal   + amountOfTape(storlek+1, (2*antal-antalPapper[storlek+1]));
  }
}
