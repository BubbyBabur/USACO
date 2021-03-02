
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class yearofcow {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = in.nextInt();
        int k = in.nextInt() - 1;

        HashSet<Integer> times = new HashSet<>();

        for(int i = 0; i < n; i++) {
            times.add(in.nextInt() / 12);
        }
        
        Integer[] t = new Integer[times.size()];
        int index = 0;
        for(Integer i : times) {
            t[index] = i;
            index++;
        }

        Arrays.sort(t);

        int total = t[t.length - 1] + 1;

        Integer[] gaps = new Integer[t.length];
        gaps[0] = t[0];
        for(int i = 1; i < t.length; i++) {
            gaps[i] = t[i] - t[i-1] - 1;
        }

        Arrays.sort(gaps);

        for(int i = 0; i < k; i++) {
            total -= gaps[gaps.length - i - 1];
        }

        // out.println(Arrays.toString(gaps));
        out.println(total * 12);

        out.flush();
        
        out.close(); in.close();
    }
}