import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

class BinarySearch {
	public static int binarySearch(List<Integer> arr, int target) {
		// WRITE YOUR BRILLIANT CODE HERE
		int l = 0, r = arr.size() - 1;

		while (l <= r) {
			int mid = (l + (r - l)) / 2;

			if (arr.get(mid) < target) {
				l = mid + 1;
			} else if (arr.get(mid) > target) {
				r = mid - 1;
			} else {
				return mid;
			}
		}
		return -1;
	}

	public static List<String> splitWords(String s) {
		return s.isEmpty() ? List.of() : Arrays.asList(s.split(" "));
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		List<Integer> arr = splitWords(scanner.nextLine()).stream().map(Integer::parseInt).collect(Collectors.toList());
		int target = Integer.parseInt(scanner.nextLine());
		scanner.close();
		int res = binarySearch(arr, target);
		System.out.println(res);
	}
}
