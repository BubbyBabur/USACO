import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class paint {

    public static int[] strokes(String str, int n) {
        int[] strokes = new int[n+1];
        strokes[0] = 0;

        boolean[] contains = new boolean[26];
        boolean[] repaintnecessary = new boolean[26];

        int currstroke = 0;
        for(int i = 0; i < n; i++) {
            int charcode = (int) str.charAt(i) - 65;
            if(!contains[charcode]) {
                repaintnecessary[charcode] = false;
                currstroke ++;

                for(int l = charcode+1; l < 26; l++) {
                    repaintnecessary[l] = true;
                }
                contains[charcode] = true;
            } else {
                if(repaintnecessary[charcode]) {
                    currstroke++;
                    repaintnecessary[charcode] = false;
                }
                for(int l = charcode+1; l < 26; l++) {
                    repaintnecessary[l] = true;
                }
            }

            strokes[i+1] = currstroke;
        }
        return strokes;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = in.nextInt();
        int q = in.nextInt();
        in.nextLine();
        String str = in.nextLine();

        // ID = (int) '_' - 65

        int[] frontstrokes = strokes(str, n);

        String reversed = "";
        for(int i = 0; i < n; i++) {
            reversed += str.charAt(n - i - 1);
        }

        int[] backstrokes = strokes(reversed,n);

        for(int i = 0; i < q; i++) {
            int a = in.nextInt() - 1;
            int b = n - in.nextInt();

            int beginning = frontstrokes[a];
            int end = backstrokes[b];

            out.println(beginning + end);
        }

        in.close();
        out.flush();
        out.close();
    }
}
