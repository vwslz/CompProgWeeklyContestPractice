import java.util.Scanner;

public class Nineteen {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        sc.close();

        int NUM_E = 3;
        int NUM_I = 1;
        int NUM_N = 3;
        int NUM_T = 1;

        int n = str.length();

        int countE = n - str.replace("e", "").length();
        int countI = n - str.replace("i", "").length();
        int countN = n - str.replace("n", "").length();
        int countT = n - str.replace("t", "").length();

        int valueN = (countN <= 2) ? 0 : (countN - 1) / 2;

        int max = Math.min(
            countE / NUM_E,
            Math.min(
                countI / NUM_I,
                Math.min(
                    valueN,
                    countT / NUM_T
                )
            )
        );
        System.out.println(max);
    }
}
