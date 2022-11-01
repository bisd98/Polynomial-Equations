import java.util.Arrays;
import java.util.Scanner;

public class LAB_01 {
    public static void main(String[] args) {
        //Zadanie 1.
        System.out.println(getName());
        System.out.println(getAge());
        //Zadanie 2.
        simpleEquations(getNumber(), getNumber());
        //Zadanie 3.
        System.out.println(checkEven(getNumber()));
        //Zadanie 4.
        System.out.println(checkMod3and5(getNumber()));
        //Zadanie 5.
        System.out.println(cubeNumber(getNumber()));
        //Zadanie 6.
        System.out.println(sqrtNumber(getNumber()));
        //Zadanie 7.
        System.out.println(randNumbers(getNumber(), getNumber()));
    }
    public static String getName(){return "Dawid";}

    public static Integer getAge(){return 23;}

    public static void simpleEquations(double a, double b){
        System.out.println("suma: " + (a+b) + "\nroznica: "
                + (a-b) +"\niloczyn: " + (a*b) + "\niloraz: " + (a/b));
    }
    public static double getNumber(){return new Scanner(System.in).nextDouble();}

    public static boolean checkEven(double n){
        return n % 2 == 0;
    }

    public static boolean checkMod3and5(double n){
        return (n % 3 == 0 && n % 5 == 0);
    }

    public static double cubeNumber(double n){
        return (n * n * n);
    }

    public static double sqrtNumber(double n){
        return Math.sqrt(n);
    }

    public static boolean randNumbers(double a, double b) {
        double[] numbers = new double[3];
        for(int i = 0; i < 3; i++)
        {
         numbers[i] = (double)(Math.random() * b + a);
        }
        return possibleTriangle(numbers);
    }

    public static boolean possibleTriangle(double[] a)
    {
        Arrays.sort(a);
        return (a[0] + a[1]) < a[2];
    }
}