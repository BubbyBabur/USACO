import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
// IS TOO SLOW

public class dancemooves {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = in.nextInt();
        int k = in.nextInt();

        Cow[] cows = new Cow[n];
        for(int i = 0; i < n; i++) {
            cows[i] = new Cow(i,n);
        }

        int steps[][] = new int[k][2];
        for(int i = 0; i < k; i++) {
            steps[i][0] = in.nextInt() - 1;
            steps[i][1] = in.nextInt() - 1;
        }
        

        for(int l = 0; l < n; l++) {
            for(int i = 0; i < k; i++) {

                int a = steps[i][0];
                int b = steps[i][1];

                cows[a].visit(b);
                cows[b].visit(a);

                Cow tempcow = cows[a];
                cows[a] = cows[b];
                cows[b] = tempcow;

            }
        }

        Arrays.sort(cows, new SortByOrig());

        for(int i = 0; i < n; i++) {
            out.println(cows[i].numvisited);
        }

        in.close();
        out.flush();
        out.close();
    }
}

class SortByOrig implements Comparator<Cow> {

	public int compare(Cow o1, Cow o2) {
		return o1.origpos - o2.origpos;
	}
    
}

class Cow {
    public boolean[] visited;
    public int numvisited = 1;
    public int origpos;
    Cow(int pos, int n) {
        visited = new boolean[n];
        visited[pos] = true;
        origpos = pos;
    }

    void visit(int pos) {

        if(!visited[pos]) {
            visited[pos] = true;
            numvisited++;
        }

    }
}
