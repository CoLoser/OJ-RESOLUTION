import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    private static Scanner cin;

    public static void main(String[] args) {
        cin = new Scanner(System.in);

        BigInteger A, B;
        A = cin.nextBigInteger();
        B = cin.nextBigInteger();

        System.out.println(A.divide(B));
        System.out.println(A.mod(B));
    }
}