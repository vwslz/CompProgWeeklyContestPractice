// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);

		StringTokenizer st = new StringTokenizer(r.readLine());

			int n = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(r.readLine());
			int[] a = new int[n];
			long total = 0;
			for (int i = 0; i < n; i++) {
				a[i] = Integer.parseInt(st.nextToken());
				total += a[i];
			}
			PriorityQueue<Integer> evens = new PriorityQueue<>(Comparator.reverseOrder());
			PriorityQueue<Integer> odds = new PriorityQueue<>(Comparator.reverseOrder());
			for (int x : a) {
				if (x % 2 == 0) {
					evens.offer(x);
				} else {
					odds.offer(x);
				}
			}
			long val = take(evens, odds);
			evens = new PriorityQueue<>(Comparator.reverseOrder());
			odds = new PriorityQueue<>(Comparator.reverseOrder());
			for (int x : a) {
				if (x % 2 == 0) {
					evens.offer(x);
				} else {
					odds.offer(x);
				}
			}
			val = Math.max(val, take(odds, evens));
			pw.println(total - val);
		pw.close();
	}

	public static long take(Queue<Integer> q1, Queue<Integer> q2) {
		int i = 0;
		long take = 0;
		while (true) {
			Queue<Integer> current = (i % 2 == 0) ? q1 : q2;
			if (current.isEmpty()) break;
			take += current.poll();
			i++;
		}
		return take;
	}
}

