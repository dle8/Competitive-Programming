import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author DHV
 */
public class test {
    public static void main(String[] args) throws IOException{
        // InputStream inputStream = System.in;
        // OutputStream outputStream = System.out;
        // Scanner in = new Scanner(inputStream);
        // PrintWriter out = new PrintWriter(outputStream);
        // CBrutality solver = new CBrutality();
        // solver.solve(1, in, out);
        // out.close();
        // FileInputStream in = new FileInputStream("input.txt");
        // FileOutputStream out = new FileOutputStream("ans.txt");
        // // solve(1, in, out);
        // in.close();
        // out.close();
        File filein = new File("input.txt");
        File fileout = new File("ans.txt");
        Scanner in = new Scanner(filein);
        PrintWriter out = new PrintWriter(fileout);
        CBrutality solver = new CBrutality();
        solver.solve(1, in, out);
        out.close();
    }

    static class CBrutality {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // int n = in.nextInt();
            // int k = in.nextInt();
            // String str = "";
            int n = in.nextInt();
            int k = in.nextInt();
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = in.nextInt();
            char[] c = in.next().toCharArray();
            long res = 0;
            PriorityQueue<Long> p = new PriorityQueue<>(Collections.reverseOrder());
            for (int i = 0; i < n - 1; i++) {
                p.add(a[i]);
                if (c[i] != c[i + 1]) {
                    int t = k;
                    while (!p.isEmpty() && t > 0) {
                        res += p.poll();
                        t--;
                    }
                    p.clear();
                }
            }
            p.add(a[n - 1]);
            int t = k;
            while (!p.isEmpty() && t > 0) {
                res += p.poll();
                t--;
            }
            p.clear();
            out.print(res);
        }

    }
}
// import java.io.*;
// public class test {
//
//    public static void main(String args[]) throws IOException {
//       FileInputStream in = null;
//       FileOutputStream out = null;
//
//       try {
//          in = new FileInputStream("input.txt");
//          out = new FileOutputStream("output.txt");
//
//          int c;
//          while ((c = in.read()) != -1) {
//             out.write(c);
//          }
//       }finally {
//          if (in != null) {
//             in.close();
//          }
//          if (out != null) {
//             out.close();
//          }
//       }
//    }
// }
